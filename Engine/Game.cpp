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
	for (int i = 0; i < max; i++) {
		antArray[i].setDirection(direction(rng));		//set direction the ant will move next
		antArray[i].UpdateAnt();
	}

	
}

void Game::ComposeFrame()
{
	for (int i = 0; i < max; i++) {
		antArray[i].Draw(gfx);			//Draw the Ants on the screen
	}
}
