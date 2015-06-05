#pragma once
#include <cmath>

//////////////////////////////////////////////////////////////////
//						ctes de ventana							//
//////////////////////////////////////////////////////////////////
#define WWW 800.0F
#define HHH 600.0F
#define PI 3.14159F

//////////////////////////////////////////////////////////////////
//						ctes del mundo							//
//////////////////////////////////////////////////////////////////
#define WORLDSIZE 101			//Define el tama�o de la matriz del mundo y los perimetros a generar
#define PERIFERIASIZE(X) (6 * X)
//Ejes equivalente para el dibujo de la matriz de casillas
const float dirx[] = { sin(2.0F*3.1416F / 3.0F), cos(2.0F*3.1416F / 3.0F) };
const float diry[] = { 1, 0 };

//////////////////////////////////////////////////////////////////
//						tipos definidos							//
//////////////////////////////////////////////////////////////////
typedef unsigned char BYTE;

//////////////////////////////////////////////////////////////////
//						Enumeraciones							//
//////////////////////////////////////////////////////////////////
enum RGB { rojo, verde, azul };
enum ejes { x, y, z };
enum ShipClasses {lightCrusier, Crusier, battleCrusier};
enum Medios { Air, Water, Underwater };
enum accsLv { Admin, ePlayer, Viewer };