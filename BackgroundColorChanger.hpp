#pragma once

#include "Entity.hpp"

class BackgroundColorChanger : public Entity
{
private:
	Color clearColor;
public:
	BackgroundColorChanger();
	virtual void Tick() override;
};
