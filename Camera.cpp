#include "Camera.h"

Camera::Camera() :_o(20,0,20)
{
	newDir();
}

void Camera::orbit(float d)
{
	_o[x] -= _v[x];
	_o[y] -= _v[y];

	_o[x] = _o[x] * cosf(step_dif*d) - _o[y] * sinf(step_dif*d);
	_o[y] = _o[x] * sinf(step_dif*d) + _o[y] * cosf(step_dif*d);
	
	_o[x] += _v[x];
	_o[y] += _v[y];

	turnAngle = step_dif*d;

	this->newDir();
}

void Camera::moveCamera(float _x, float _y, float _z)
{
	_o[x] += _x * dir[0] * vmove + _y * dir[1] * vmove;
	_v[x] += _x * dir[0] * vmove + _y * dir[1] * vmove;
	_o[y] += _x * dir[1] * vmove - _y * dir[0] * vmove;
	_v[y] += _x * dir[1] * vmove - _y * dir[0] * vmove;
	_o[z] += _z * vmove;
	_v[z] += _z * vmove;
}

void Camera::teleportCamera(float _x, float _y, float _z)
{
	_o[x] -= _v[x];
	_v[x] = _x;
	_o[x] += _v[x];
	_o[y] -= _v[y];
	_v[y] = _y;
	_o[y] += _v[y];
	_o[z] -= _v[z];
	_v[z] = _z;
	_o[z] += _v[z];
}

void Camera::zoomCamera(float d)
{
	_o = (vectorPosLine() - vectorPosLine().normaUnitario()*d) + vectorPosMira();
}

void Camera::setPV(float _x, float _y, float _z)
{
	_v[x] = _x, _v[y] = _y, _v[z] = _z;
}

void Camera::setCamera(float _x, float _y, float _z)
{
	_o[x] = _x, _o[y] = _y, _o[z] = _z;
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
	v[0] = _o[x];
	v[1] = _o[y];
	v[2] = _o[z];
	v[3] = _v[x];
	v[4] = _v[y];
	v[5] = _v[z];
	v[6] = 0;
	v[7] = 0;
	v[8] = 1;
}

void Camera::newDir()
{

	float v[2];

	v[0] = _v[x] - _o[x];
	v[1] = _v[y] - _o[y];

	norma(v, true, 2);

	dir[0] = v[0];
	dir[1] = v[1];
}

Vector Camera::vectorPosOjos()
{
	return _o;
}
Vector Camera::vectorPosMira()
{;
	return _v;
}
Vector Camera::vectorPosLine()
{
	return _o-_v;
}
float Camera::anguloAbsolutoPosLineXY()
{
	Vector vTemp = vectorPosLine();
	return atan2(vTemp[x], vTemp[y]);
}
float Camera::anguloAbsolutoPosElevacion()
{
	Vector vTemp = vectorPosLine();
	return acos(vTemp.norma2D() / vTemp.norma3D());
}

Vector Camera::posicionCursor(int _x, int _y)
{
	//Corregimos el offset
	float x_ = ((float)_x - WWW / 2) / (820.2438662F/vectorPosLine().norma3D());
	float y_ = ((float)_y - HHH / 2) / (820.2438662F/vectorPosLine().norma3D());
	Vector vTemp;
	//Primera aproximacion trabajando sobre el plano virtual
	float cx = cos(-anguloAbsolutoPosElevacion())*y_;
	float cy = x_;
	vTemp[z] = sin(-anguloAbsolutoPosElevacion())*y_;
	//Ahora tratamos de alinear la proyeccion girada en trs ejes con el sistema de referencia base, tenemos en cuenta que la possicion relativa de los puntos debe mantenerse, solo hay que hace el cambio de seistema de referencia en el plano XY
	vTemp[x] = cx * cos(-anguloAbsolutoPosLineXY() + PI / 2) - cy * sin(-anguloAbsolutoPosLineXY() + PI / 2);
	vTemp[y] = cy * cos(-anguloAbsolutoPosLineXY() + PI / 2) + cx * sin(-anguloAbsolutoPosLineXY() + PI / 2);
	//Ahora convertimos los puntos en una recta y hallamos la interseccion con el plano
	Vector proyeccionOjo = vectorPosOjos() - (vTemp + vectorPosMira());
	Vector planoMundo(0, 0, 1);
	float lamda = -(planoMundo*vectorPosOjos()).sumaElmentos() / (planoMundo*proyeccionOjo).sumaElmentos();
	//return vectorPosOjos() + proyeccionOjo*lamda;
	return vTemp + vectorPosMira();
}