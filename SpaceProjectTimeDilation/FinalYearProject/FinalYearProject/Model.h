#ifndef MODEL_H
#define MODEL_H
#include <Windows.h>
#include <iostream>
#include <string>
#include <GL/gl.h>
#include <GL/glu.h>
#include "glut.h"
#include "Structures.h"

using namespace std;


class Model
{

private:
	string fileName;
	string texture;
	circle * vertices;
	polygon * indices;
	int NUM_VERTS;
	int NUM_POLY;
protected: int Model_Texture_Num;


public:

	Model(string Model_fileName, string Model_texture, int ModlTextNum)
		: fileName(Model_fileName), texture(Model_texture), Model_Texture_Num(ModlTextNum)
	{

	}

	Model()
	{

	}

	~Model();
	int read_file(const string fileName);
	int loadTexture(const string fileName);
	int getPolyCount();

	void drawPolygon(int pointA, int pointB, int pointC);
	void drawObject();

};
#endif