/*
	A good collection for when you need indices not to change when modifying the collection.
	Dynamically allocates when out of space.
	Values keep their indices after a remove.
	Values that are removed are quickly replaced before moved to the back of the collection.
	Trevor Berninger - Oct 18, 2015
*/

#pragma once

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
#include <sstream>

#define SSTR(x) dynamic_cast<std::ostringstream&>((std::ostringstream() << std::dec << x)).str()

#ifndef LOG
	#define LOG(message) std::cout << message;
#endif

template<typename T>
class PackedDynamicArray {
private:
	std::queue<size_t> emptySlots;
	size_t length, capacity;
	T* array;
public:
	size_t Size() { return length; }
	size_t Capacity() { return capacity; }
	T& operator[](size_t i) { return array[i]; }
	// for(:) support:
	T* begin() const { return array; }
	T* end() const { return &(array[length]); }

	PackedDynamicArray(PackedDynamicArray<T> const& other) {
		//SDL_Log("Oh my");
		array = new T[other.capacity];
		for(T i : other)
			Add(i);
		length = other.length;
		capacity = other.capacity;
	}

	PackedDynamicArray(size_t initCapacity = 30) { 
		array = new T[initCapacity];
		length = 0;
		capacity = initCapacity;
	}

	~PackedDynamicArray() { if(array != nullptr) delete [] array; }

	size_t Add(T value) {
		if(!emptySlots.empty()) {
			size_t pos = emptySlots.front();
			array[pos] = value;
			emptySlots.pop();
			return pos;
		}
		else {
			size_t pos = length;
			if(length++ == capacity) {
				ReallocateWithSize(capacity + 20);
			}
			array[pos] = value;
			return pos;
		}
	}

	bool RemoveValue(T value) {
		T* i = std::find(array, array + capacity, value);
		if(i != array + capacity) {
			RemoveAt(i - array);
			return true;
		}
		return false;
	}

	void RemoveAt(size_t index) {
		if(index > capacity) {
			LOG("PDA: Attempted remove at " + SSTR(index) + " with capacity of " + SSTR(capacity));
			return;
		}
		array[index] = T();
		emptySlots.push(index);
	}

	void Display() {
		for(size_t i = 0; i < length; i++) {
			// SDL_Log( i << '\t' << array[i] << '\n' );
			SDL_Log("%d\t%d", i, array[i]);
		}
	}

	template<typename rT>
	constexpr rT* Get(size_t index) {
		return (rT*)array[index];
	}

private:
	void ReallocateWithSize(size_t size) {
		T* a = new T[size];
		std::copy(array, array + capacity, a);
		capacity = size;
		delete [] array;
		array = a;
	}
};
