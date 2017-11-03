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
		if(antX > 0)
			antX--;
	}
	else
		if (antDirection == Ant::Direction::RIGHT) {
			if (antX < Graphics::ScreenWidth-1 )
				antX++;
		}
	else
		if (antDirection == Ant::Direction::UP) {
			if (antY > 0)
				antY--;
		}
	else
		if (antDirection == Ant::Direction::DOWN) {
			if (antY < Graphics::ScreenHeight-1)
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

Color Ant::GetColor() const
{
	return antColor;
}

Color Ant::getPixelColor(Graphics& gfx,Ant& ant) const
{
	Color c;
	switch (Ant::antDirection) {
		case 0:
		{
			if(antX > 0)
			{ 
				c = gfx.GetPixel(antX - 1, antY);
			}
			
			break;
		}
		case 1:
		{
			if (antX < gfx.ScreenWidth-1)
			{
				c = gfx.GetPixel(antX + 1, antY);
			}
			break;
		}
		case 2:
		{
			if (antY > 0)
			{
				c = gfx.GetPixel(antX, antY - 1); 
			}
			break;
		}
		case 3:
		{
			if (antY < gfx.ScreenHeight-1)
			{
				c = gfx.GetPixel(antX, antY + 1);
			}
			break;
		}
	}
	return c;
}
