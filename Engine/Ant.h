#pragma once
#include "Colors.h"
#include "Graphics.h"


class Ant
{

public:
	enum Direction
	{
		left, right, up, down
	};

public:
	Ant() = default;
	void AntInit(int x, int y, Color c);
	void UpdateAnt(int in_x, int in_y, Color c);
	void Draw(Graphics& gfx) const; 
private:
    
	int antX;
	int antY;
	Color antColor;
	Direction antDirection;
};