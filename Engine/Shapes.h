#pragma once

#include <vector>
#include "Vec2.h"

class Shapes
{
public:
	static std::vector<Vec2> MakeStar(float innerRadius, float outerRadius, int nFlares = 5)
	{
		std::vector<Vec2> star;
		star.reserve(nFlares * 2);
		const float dtheta = 2 * 3.141493f / float(nFlares * 2);
		
		for (int i = 0; i < nFlares*2; i++)
		{
			const float rad = (i % 2 == 0) ? outerRadius : innerRadius;
			star.emplace_back(rad * cos(float(i) * dtheta), rad * sin(float(i) * dtheta));
		}

		return star;
	}
};