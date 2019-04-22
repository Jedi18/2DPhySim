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
#include "Shapes.h"

Game::Game(MainWindow& wnd)
	:
	wnd(wnd),
	gfx(wnd),
	ct(),
	cam(Vec2(0.0f, 0.0f), 1.0f, ct, gfx),
	e(Vec2(0.0f, 0.0f), rectangle1, Colors::Blue),
	e2(Vec2(-200.0f, -200.0f), rectangle2, Colors::Green),
	ball(Vec2(-300.0f, -200.0f), Shapes::MakeStar(30, 30, 10), Colors::Cyan)
{
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
	const float speed = 5.0f;

	if (wnd.kbd.KeyIsPressed('W'))
	{
		cam.TranslateBy(Vec2(0.0f, -1.0f) * speed);
	}
	if (wnd.kbd.KeyIsPressed('A'))
	{
		cam.TranslateBy(Vec2(1.0f, 0.0f) * speed);
	}
	if (wnd.kbd.KeyIsPressed('S'))
	{
		cam.TranslateBy(Vec2(0.0f, 1.0f) * speed);
	}
	if (wnd.kbd.KeyIsPressed('D'))
	{
		cam.TranslateBy(Vec2(-1.0f, 0.0f) * speed);
	}

	if (!wnd.mouse.IsEmpty())
	{
		const auto e = wnd.mouse.Read();

		if (e.GetType() == Mouse::Event::Type::WheelUp)
		{
			cam.ScaleBy(1.05f);
		}
		if (e.GetType() == Mouse::Event::Type::WheelDown)
		{
			cam.ScaleBy(0.95f);
		}
	}

	ball.TranslateBy(Vec2(1.0f, 1.0f) * speed/2);
}

void Game::ComposeFrame()
{
	if (wnd.mouse.LeftIsPressed())
	{
		gfx.DrawLine(Vec2(300, 300), Vec2((float)wnd.mouse.GetPosX(), (float)wnd.mouse.GetPosY()), Colors::Red);
	}
	cam.Draw(e.GetDrawable());
	cam.Draw(e2.GetDrawable());
	cam.Draw(ball.GetDrawable());
}
