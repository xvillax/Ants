#pragma once
#include "Colors.h"
#include "Graphics.h"


class Ant
{

public:
	enum Direction
	{
		LEFT,RIGHT,UP,DOWN
	};
	
public:
	Ant() = default;
	void AntInit(int x, int y, Color c);
	void UpdateAnt();
	void Draw(Graphics& gfx) const; 
	void setDirection(int d);
private:
    
	int antX;
	int antY;
	Color antColor;
	int antDirection; 
};