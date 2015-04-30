#pragma once
#include <cmath>

//Constates de ventana
#define WWW 1600
#define HHH 1000

//Constantes del mundo
#define WORLDSIZE 101			//Define el tamaño de la matriz del mundo y los perimetros a generar
#define PERIFERIASIZE(X) (6 * X)
//Enums utiles
enum RGB { rojo, verde, azul };
enum ejes { x, y, z };
enum ShipClasses {AircraftCarrier, Battleship, BattleCrusier, Crusier, Destroller, Frigate, FastAttackCraft, MisileSubmarine, AttackSubmarine};
enum Subsistems {Hull, Engines, Power, Armament, Crew};
enum Medios { Air, Water, Underwater };

//Ejes coordenados del sistema
const float dirx[] = { 1, 0 };
const float diry[] = { sin(2.0F*3.1416F / 3.0F), cos(2.0F*3.1416F / 3.0F) };
