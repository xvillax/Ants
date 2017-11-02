#include "Ant.h"

void Ant::AntInit(int x, int y, Color c)
{
	antX = x;
	antY = y;
	antColor = c;

}

void Ant::UpdateAnt(int in_x, int in_y, Color c)
{
}

void Ant::Draw(Graphics & gfx) const
{
	gfx.PutPixel(antX, antY, antColor);
}
