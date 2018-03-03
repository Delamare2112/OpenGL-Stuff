#pragma once
#include "PackedDynamicArray.hpp"
#include "Component.hpp"
#include "Game.hpp"
#include "Transform.hpp"

class Entity
{
private:
	size_t iid;
	std::vector<Component*> components;
protected:
	Entity(bool shouldTick=false);
public:
	Transform transform;

	virtual ~Entity();
	static PackedDynamicArray<Entity*> entities;
	virtual void Tick();

	template<class T>
	T* GetComponent()
	{
		for(auto& c : components)
		{
			T* t = dynamic_cast<T*>(c);
			if(t)
				return t;
		}
	}

	template<class T>
	T* AddComponent()
	{
		return components.emplace_back(new T(this));
	}
};
