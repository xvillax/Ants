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
	Color GetColor() const;
	Color getPixelColor(Graphics& gfx, Ant& ant) const;
	bool isSuperAnt(Ant& antA, Ant& antB) const;
private:
    
	int antX;
	int antY;
	Color antColor;
	int antDirection; 
};