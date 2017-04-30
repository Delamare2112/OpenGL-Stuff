/*
	A good collection for when you need indices not to change when modifying the collection.
	Dynamically allocates when out of space.
	Values keep their indices after a remove.
	Values that are removed are quickly replaced before moved to the back of the collection.
	Trevor Berninger - Apr 29, 2017
*/

#pragma once

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

template<typename T>
class PackedDynamicArray {
private:
    struct Node {
        bool valid;
        T value;
        Node() {valid = false; value = T();}
        Node(bool valid, T val) {this->valid = valid; value = val;}
        bool operator==(const Node& rhs) {
            return valid == rhs.valid && rhs.value == value;
        }
    };

    std::queue<size_t> emptySlots;
    size_t packSize, capacity, size, tailNodeIndex, headNodeIndex;
    Node* array;
public:
    class Iterator {
    private:
        size_t baseIndex;
        const PackedDynamicArray* pda;
    public:
        Iterator(const PackedDynamicArray* pda, size_t index) {
            baseIndex = index;
            this->pda = pda;
        }
        Iterator& operator++() {
            do {
                baseIndex++;
            }while(baseIndex != pda->tailNodeIndex+1 && !pda->array[baseIndex].valid);
            return *this;
        }
        Iterator& operator--() {
            do {
                baseIndex--;
            }while(baseIndex != pda->headNodeIndex && !pda->array[baseIndex].valid);
            return *this;
        }
        size_t GetIndex() {
            return baseIndex;
        }
        T& operator*() {
            return pda->array[baseIndex].value;
        }
        bool operator!=(const Iterator& rhs) {
            return baseIndex != rhs.baseIndex;
        }
    };

    size_t Size() { return size; }
    size_t Capacity() { return capacity; }
    T& operator[](size_t i) { return array[i].value; }
    // for(:) support:
    Iterator begin() const { return Iterator(this, headNodeIndex); }
    Iterator end() const { return Iterator(this, tailNodeIndex+1); }

    PackedDynamicArray(PackedDynamicArray<T> const& other) {
        //SDL_Log("Oh my");
        capacity = other.capacity;
        array = new Node[capacity];
        for(T i : other)
            Add(i);
    }

    PackedDynamicArray(size_t initCapacity = 30) {
        array = new Node[initCapacity];
        packSize = 0;
        size = 0;
        capacity = initCapacity;
    }

    ~PackedDynamicArray() { if(array != nullptr) delete [] array; }

    size_t Add(T value) {
        size_t pos;
        if(!emptySlots.empty()) {
            pos = emptySlots.front();
            emptySlots.pop();
        }
        else {
            pos = packSize;
            tailNodeIndex = packSize;
            if(packSize++ == capacity) {
                ReallocateWithSize(capacity + 20);
            }
        }
        array[pos].value = value;
        array[pos].valid = true;
        size++;
        if(packSize == 1)
            headNodeIndex = pos;
        return pos;
    }

    bool RemoveValue(T value) {
        Node* i = std::find(array, array + capacity, Node(true, value));
        if(i != array + capacity) {
            RemoveAt(i - array);
            return true;
        }
        return false;
    }

    void RemoveAt(size_t index) {
        if(index > capacity) {
            std::cout << "PDA: Attempted remove at " << index << " with capacity of " << capacity;
            return;
        }
        if(tailNodeIndex == index) {
            tailNodeIndex = end().operator--().GetIndex();
        }
        else if(headNodeIndex == index) {
            headNodeIndex = begin().operator++().GetIndex();
        }
        array[index].value = T();
        array[index].valid = false;
        size--;
        emptySlots.push(index);
    }

    void Display() {
        std::cout << headNodeIndex << "->" << tailNodeIndex << '=' << packSize << ':' << size << '(' << capacity << ")\n";
        for(size_t i = 0; i < capacity; i++) {
            std::cout << i << '{' << array[i].valid << ':' << array[i].value << "}  ";
        }
        std::cout << '\n';
    }

private:
    void ReallocateWithSize(size_t size) {
        Node* a = new Node[size];
        std::copy(array, array + capacity, a);
        capacity = size;
        delete [] array;
        array = a;
    }
};
