#include <math.h>

#include "Camera.h"
#include "funciones_inline.h"

Camera::Camera()
{
	newDir();
}

void Camera::orbit(float d)
{
	o_x -= v_x;
	o_y -= v_y;

	o_x = o_x*cosf(step_dif*d) - o_y*sinf(step_dif*d);
	o_y = o_x*sinf(step_dif*d) + o_y*cosf(step_dif*d);
	
	o_x += v_x;
	o_y += v_y;

	this->newDir();
}

void Camera::moveCamera(float x, float y, float z)
{
	o_x += x * dir[0] * vmove + y * dir[1] * vmove;
	v_x += x * dir[0] * vmove + y * dir[1] * vmove;
	o_y += x * dir[1] * vmove + y * dir[0] * -1 * vmove;
	v_y += x * dir[1] * vmove + y * dir[0] * -1 * vmove;
	o_z += z * vmove;
	v_z += z * vmove;
}

void Camera::teleportCamera(float x, float y, float z)
{
	o_x -= v_x;
	v_x = x;
	o_x += v_x;
	o_y -= v_y;
	v_y = y;
	o_y += v_y;
	o_z -= v_z;
	v_z = z;
	o_z += v_z;
}

void Camera::zoomCamera(float d)
{
	dim += d;
}

void Camera::setPV(float x, float y, float z)
{
	v_x = x, v_y = y, v_z = z;
}
void Camera::setCamera(float x, float y, float z)
{
	o_x = x, o_y = y, o_z = z;
}
void Camera::setSpeed(float s)
{
	vmove = s;
}
void Camera::setStepOrb(float s)
{
	step_dif = s;
}
void Camera::setDim(float d)
{
	dim = d;
}
void Camera::getBackCamera(float *v)
{
	v[0] = o_x;
	v[1] = o_y;
	v[2] = o_z;
	v[3] = v_x;
	v[4] = v_y;
	v[5] = v_z;
	v[6] = 0;
	v[7] = 0;
	v[8] = 1;
}
void Camera::newDir()
{

	float v[2];

	v[0] = v_x - o_x;
	v[1] = v_y - o_y;

	norma(v, true, 2);

	dir[0] = v[0];
	dir[1] = v[1];

}

