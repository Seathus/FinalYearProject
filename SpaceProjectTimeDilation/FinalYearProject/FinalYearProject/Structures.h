#ifndef STRUCTURES_H
#define STRUCTURES_H
#include <Windows.h>

typedef struct 
	{
		int posx;
		int posy;
		int posz;
	} position;

typedef struct 
	{
		float posx;
		float posy;
		float posz;
	} fposition;

typedef struct 
	{
		float x;
		float y;
		float z;
	} circle;
typedef struct 
{
	float a;
	float b;
	float c;
	float d;
} polygon;
typedef struct
{
	float ambient[4];
	float diffuse[4];
	float specular[4];
} lighting;
typedef struct
{
	float ambient[4];
	float diffuse[4];
	float specular[4];
	float shininess;
} material;

#endif