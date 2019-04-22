#pragma once

#include "Vec2.h"
#include "Drawable.h"
#include "CoordinateTransformer.h"
#include "Graphics.h"

class Camera
{
public:
	Camera(const Vec2& camTrans_in, float camScale_in, CoordinateTransformer& ct_in, Graphics& gfx_in);
	void Draw(Drawable& d) const;
	void TranslateBy(const Vec2& trans);
	void ScaleBy(float scal);
	const Vec2& GetCameraTranslation() const;
	float GetCameraScale() const;

private:
	Vec2 camTranslation = { 0.0f, 0.0f };
	float camScale = 1.0f;
	CoordinateTransformer& ct;
	Graphics& gfx;
};