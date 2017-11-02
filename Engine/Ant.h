#pragma once
#include "Colors.h"


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

private:
    
	int antX;
	int antY;
	Color antColor;
	Direction antDirection;
};