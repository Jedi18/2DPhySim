#include "Drawable.h"

Drawable::Drawable(const std::vector<Vec2> verts_in)
	:
	verts(std::move(verts_in))
{}

void Drawable::Scale(float scale_in)
{
	scale_x *= scale_in;
	scale_y *= scale_in;
	translation *= scale_in;
}

void Drawable::ScaleIndependent(float scale_xi, float scale_yi)
{
	scale_x *= scale_xi;
	scale_y *= scale_yi;
	translation.x *= scale_xi;
	translation.y *= scale_yi;
}

void Drawable::Translate(const Vec2 & translation_in)
{
	translation += translation_in;
}

void Drawable::Render(Graphics & gfx)
{
	for (auto& vert : verts)
	{
		vert.x *= scale_x;
		vert.y *= scale_y;
		vert += translation;
	}
	gfx.DrawPolyline(verts, Colors::Red);
}
