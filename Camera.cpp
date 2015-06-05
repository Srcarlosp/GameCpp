#include "Camera.h"

//////////////////////////////////////////////////////////////////
//						Gestion de Interfaz						//
//////////////////////////////////////////////////////////////////

Vector Camera::posicionCursor(int _x, int _y)
{
	//Corregimos el offset
	double x_ = ((double)_x - WWW / 2) / (820.2438662 / vectorPosLine().norma3D());
	double y_ = ((double)_y - HHH / 2) / (820.2438662 / vectorPosLine().norma3D());
	Vector vTemp;
	//Primera aproximacion trabajando sobre el plano virtual
	double cx = cos(-anguloAbsolutoPosElevacion())*y_;
	double cy = x_;
	vTemp[z] = sin(-anguloAbsolutoPosElevacion())*y_;
	//Ahora tratamos de alinear la proyeccion girada en trs ejes con el sistema de referencia base, tenemos en cuenta que la possicion
	//relativa de los puntos debe mantenerse, solo hay que hace el cambio de seistema de referencia en el plano XY
	vTemp[x] = cx * cos(-anguloAbsolutoPosLineXY() + PI / 2) - cy * sin(-anguloAbsolutoPosLineXY() + PI / 2);
	vTemp[y] = cy * cos(-anguloAbsolutoPosLineXY() + PI / 2) + cx * sin(-anguloAbsolutoPosLineXY() + PI / 2);
	//Ahora convertimos los puntos en una recta y hallamos la interseccion con el plano
	Vector proyeccionOjo = vectorPosOjos() - (vTemp + vectorPosMira());
	Vector planoMundo(0, 0, 1);
	float lamda = -((planoMundo*vectorPosOjos()) / (planoMundo*proyeccionOjo));
	return vectorPosOjos() + proyeccionOjo*lamda;
	//return vTemp + vectorPosMira();
}

void Camera::orbit(float d)
{
	float step_dif = 0.001 + vectorPosLine().norma3D() / 1000;
	_o[x] = vectorPosLine()[x] * cosf(step_dif*d) - vectorPosLine()[y] * sinf(step_dif*d) + _v[x];
	_o[y] = vectorPosLine()[x] * sinf(step_dif*d) + vectorPosLine()[y] * cosf(step_dif*d) + _v[y];
}

void Camera::moveCamera(float _x, float _y, float _z)
{
	Vector dir = vectorPosLine().normaUnitario(2);

	float vmove = vectorPosLine().norma3D() / 50;

	_o[x] += _x * dir[x] * vmove + _y * dir[y] * vmove;
	_v[x] += _x * dir[x] * vmove + _y * dir[y] * vmove;
	_o[y] += _x * dir[y] * vmove - _y * dir[x] * vmove;
	_v[y] += _x * dir[y] * vmove - _y * dir[x] * vmove;
	_o[z] += _z * vmove;
	_v[z] += _z * vmove;
}

void Camera::zoomCamera(float d)
{
	if (5<vectorPosLine().norma3D() || d<0) _o = (vectorPosLine() - vectorPosLine().normaUnitario()*d) + vectorPosMira();
}

void Camera::elevationCamera(float d)
{
	_o[z] += d;
}

void Camera::changeVertical(float h, bool diff)
{
	if (diff)	_o[z] += h;
	else		_o[z] = h;
}

void Camera::changePerspective(float g, float _x, float _y, float _z)
{
	orbit(g);
	moveCamera(_x, _y, 0);
}

void Camera::setPV(float _x, float _y, float _z)
{
	_v = Vector(_x, _y, _z);
}

void Camera::setCamera(float _x, float _y, float _z)
{
	_o = Vector(_x, _y, _z);
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

//////////////////////////////////////////////////////////////////
//							Constructor							//
//////////////////////////////////////////////////////////////////

Camera::Camera(float _x, float _y, float _z) :_o(_x, _y, _z) {}

//////////////////////////////////////////////////////////////////
//						Metodos	privados						//
//////////////////////////////////////////////////////////////////

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
double Camera::anguloAbsolutoPosLineXY()
{
	Vector vTemp = vectorPosLine();
	return atan2(vTemp[x], vTemp[y]);
}
double Camera::anguloAbsolutoPosElevacion()
{
	Vector vTemp = vectorPosLine();
	return asin(vTemp.norma2D()/vTemp.norma3D());
}