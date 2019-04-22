#include "Entity.h"

Entity::Entity(const Vec2 & pos_in, std::vector<Vec2> verts_in, Color c)
	:
	pos(pos_in),
	verts(std::move(verts_in)),
	c(c)
{
}

void Entity::TranslateBy(const Vec2 & trans)
{
	pos += trans;
}

void Entity::MoveTo(const Vec2 & move_pos)
{
	pos = move_pos;
}

void Entity::ScaleBy(float scale_in)
{
	scale *= scale_in;
}

Drawable Entity::GetDrawable() const
{
	Drawable d(verts);
	d.Scale(scale);
	d.Translate(pos);
	return d;
}


