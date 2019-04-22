#include "Camera.h"

Camera::Camera(const Vec2 & camTrans_in, float camScale_in, CoordinateTransformer& ct_in, Graphics& gfx_in)
	:
	camTranslation(camTrans_in),
	camScale(camScale_in),
	ct(ct_in),
	gfx(gfx_in)
{
}

void Camera::Draw(Drawable & d) const
{
	d.Translate(camTranslation);
	d.Scale(camScale);
	ct.Draw(d, gfx);
}

void Camera::TranslateBy(const Vec2 & trans)
{
	camTranslation += trans;
}

void Camera::ScaleBy(float scal)
{
	camScale *= scal;
}
