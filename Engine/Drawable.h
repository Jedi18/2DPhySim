#pragma once

#include "Graphics.h"
#include <vector>
#include "Vec2.h"

class Drawable
{
public:
	Drawable(const std::vector<Vec2>& verts_in);
	void Scale(float scale_in);
	void ScaleIndependent(float scale_x, float scale_y);
	void Translate(const Vec2& translation_in);
	void Render(Graphics& gfx) const;
private:
	const std::vector<Vec2>& verts;
	Vec2 translation = { 0.0f, 0.0f };
	float scale_x = 1.0f;
	float scale_y = 1.0f;
};