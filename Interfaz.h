#pragma once

#include "Elemento.h"
#include "Camera.h"
#include "windows.h"
#include "glut.h"

typedef unsigned char Byte;

void InterfazTeclado(Byte key, Camera *, Elemento *);
void pintarHexagono(float x, float y, Camera camera);
void pintarPlanos();
