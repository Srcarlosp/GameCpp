#pragma once

#include "Camera.h"
#include "Elemento.h"

typedef unsigned char Byte;

void InterfazTeclado(Byte key, Camera *, Elemento *);
void pintarHexagono(float x, float y, Camera camera);
void pintarPlanos();
