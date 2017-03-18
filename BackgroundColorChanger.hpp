#pragma once

#include "Engine/Entity.hpp"

class BackgroundColorChanger : public Entity
{
private:
	Color clearColor;
public:
	BackgroundColorChanger();
	virtual void Tick() override;
};
