#include "Ant.h"

void Ant::AntInit(int x, int y, Color c)
{
	antX = x;
	antY = y;
	antColor = c;

}

void Ant::UpdateAnt()
{
	if (antDirection == Ant::Direction::LEFT)
	{
		// vove ant to the left
		antX--;
	}
	else
		if (antDirection == Ant::Direction::RIGHT) {
			antX++;
		}
	else
		if (antDirection == Ant::Direction::UP) {
			antY--;
		}
	else
		if (antDirection == Ant::Direction::DOWN) {
			antY++;
		}
}

void Ant::Draw(Graphics & gfx) const
{
	gfx.PutPixel(antX, antY, antColor);
}

void Ant::setDirection(int d)
{
	antDirection = d;
}
