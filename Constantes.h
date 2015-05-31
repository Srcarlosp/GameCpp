#pragma once
#include <cmath>

//Constates de ventana
#define WWW 800.0F
#define HHH 600.0F
#define PI 3.14159F
#define MAXBARCOS 50

//Constantes del mundo
#define WORLDSIZE 101			//Define el tama�o de la matriz del mundo y los perimetros a generar
#define PERIFERIASIZE(X) (6 * X)

//Definicion de tipos
typedef unsigned char BYTE;

//Enums utiles
enum RGB { rojo, verde, azul };
enum ejes { x, y, z };
enum ShipClasses {AircraftCarrier, Battleship, BattleCrusier, Crusier, Destroller, Frigate, FastAttackCraft, MisileSubmarine, AttackSubmarine};
enum Subsistems {Hull, Engines, Power, Armament, Crew};
enum Medios { Air, Water, Underwater };

//Ejes equivalente para el dibujo de la matriz de casillas
const float dirx[] = { sin(2.0F*3.1416F / 3.0F), cos(2.0F*3.1416F / 3.0F) };
const float diry[] = { 1, 0 };