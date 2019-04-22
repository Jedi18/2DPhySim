#pragma once

#include "Vec2.h"
#include "Drawable.h"
#include "Graphics.h"

class CoordinateTransformer
{
public:
	CoordinateTransformer()
	{
		screenOffset = Vec2{ (float)Graphics::ScreenWidth / 2, (float)Graphics::ScreenHeight / 2 };
	}
	void Draw(Drawable& d, Graphics& gfx)
	{
		d.ScaleIndependent(1.0f, -1.0f);
		d.Translate(screenOffset);
		d.Render(gfx);
	}
private:
	Vec2 screenOffset;
};