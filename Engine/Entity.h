#pragma once

#include "Graphics.h"
#include <vector>
#include "Vec2.h"
#include "Drawable.h"

class Entity
{
public:
	Entity(const Vec2& pos_in, std::vector<Vec2> verts_in, Color c);
	void TranslateBy(const Vec2& trans);
	void MoveTo(const Vec2& move_pos);
	void ScaleBy(float scale_in);
	Drawable GetDrawable() const;
private:
	Vec2 pos;
	float scale = 1.0f;
	std::vector<Vec2> verts;
	Color c;
};