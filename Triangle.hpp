#pragma once

#include "Entity.hpp"

class Triangle : public Entity
{
public:
	Triangle();
	~Triangle();
	virtual void Tick() override;
};
