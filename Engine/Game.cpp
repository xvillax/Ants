/****************************************************************************************** 
 *	Chili DirectX Framework Version 16.07.20											  *	
 *	Game.cpp																			  *
 *	Copyright 2016 PlanetChili.net <http://www.planetchili.net>							  *
 *																						  *
 *	This file is part of The Chili DirectX Framework.									  *
 *																						  *
 *	The Chili DirectX Framework is free software: you can redistribute it and/or modify	  *
 *	it under the terms of the GNU General Public License as published by				  *
 *	the Free Software Foundation, either version 3 of the License, or					  *
 *	(at your option) any later version.													  *
 *																						  *
 *	The Chili DirectX Framework is distributed in the hope that it will be useful,		  *
 *	but WITHOUT ANY WARRANTY; without even the implied warranty of						  *
 *	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the						  *
 *	GNU General Public License for more details.										  *
 *																						  *
 *	You should have received a copy of the GNU General Public License					  *
 *	along with The Chili DirectX Framework.  If not, see <http://www.gnu.org/licenses/>.  *
 ******************************************************************************************/
#include "MainWindow.h"
#include "Game.h"



Game::Game( MainWindow& wnd )
	:
	wnd( wnd ),
	gfx( wnd ),
	rng(rd()),
	xDist(0, 799),
	yDist(0, 599),
	direction(0,3)


{
	for (int i = 0; i < max; i++)
	{
		if (i < (max / 2))
			antArray[i].AntInit(xDist(rng), yDist(rng), Colors::Red); // make ants half RED and half Blue....
		else
			antArray[i].AntInit(xDist(rng), yDist(rng), Colors::Cyan);
		antArray[i].setDirection(direction(rng)); // set the ants initial direction
	 }
	for (int y = 0; y < Graphics::ScreenHeight; y++)
		for (int x = 0; x < Graphics::ScreenWidth; x++)
			gfx.PutPixel(x, y, Colors::Black);

}

void Game::Go()
{
	
	gfx.BeginFrame();	
	UpdateModel();
	ComposeFrame();
	gfx.EndFrame();
	
}

void Game::UpdateModel()
{
	Color c;
	bool Moved = false;

	for (int i = 0; i < max; i++) {
		Moved = false;
		//loop till a valid move is performed
		while (!Moved) {

			antArray[i].setDirection(direction(rng));		//set direction the ant will move next
			c = antArray[i].getPixelColor(gfx, antArray[i]); //get the color of the square the ant wants to move too

			//Test to see if the ant can move or not
			if ( c != Colors::Red && antArray[i].GetColor() == Colors::Cyan)
				{
					antArray[i].UpdateAnt();
					Moved = true;
				}
			else
			if (c != Colors::Cyan && antArray[i].GetColor() == Colors::Red)// if its a valid move for a Red ant
				{
					antArray[i].UpdateAnt();
					Moved = true;
				}
			else
			if (antArray[i].GetColor() == Colors::Magenta)// if its a super ant just move
				{
					antArray[i].UpdateAnt();
					Moved = true;
				}
		}//end while
		//if(antArray[i].isSuperAnt(antArray[i], antArray[i+1]))
	}//end for
}

void Game::ComposeFrame()
{
	
	for (int i = 0; i < max; i++) {
		antArray[i].Draw(gfx);			//Draw the Ants on the screen
	}
}
