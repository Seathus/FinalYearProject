#include <Windows.h>
#include "Model.h"
#include <GL/gl.h>
#include <GL/glu.h>
#include "glut.h"
#include <fstream>
#include <sstream>


Model::~Model()
{
	cout << "Model Destroyed.";
}

int Model::read_file(const string fileName)
{
	ifstream inFile;
	inFile.open(fileName.c_str());

	if (!inFile.good())
	{
		cerr << "Can't open file" << endl;
		NUM_POLY = 0;
		return 1;
	}

	string check = "";
	inFile >> NUM_VERTS;

	vertices = new circle[NUM_VERTS];

	for (int i = 0; i < NUM_VERTS; i++)
	{
		inFile >> check;

		if (check == "v")
		{
			inFile >> vertices[i].x;
			inFile >> vertices[i].y;
			inFile >> vertices[i].z;
		}
	}




	// read in the number of polygons

	string check2 = "";
	inFile >> NUM_POLY;

	// create an array of polygons

	indices = new polygon[NUM_POLY];

	// read in the a b c d indices for each polygon

	for (int i = 0; i < NUM_POLY; i++)
	{
		inFile >> check2;

		if (check2 == "f")
		{
			inFile >> indices[i].a;
			indices[i].a -= 1;
			inFile >> indices[i].b;
			indices[i].b -= 1;
			inFile >> indices[i].c;
			indices[i].c -= 1;
		}

	}


	cout << "Model " << fileName << " loaded, " << endl;

	inFile.close();
	return 0;
}

int Model::loadTexture(const string fileName)
{
	char* data;
	ifstream inFile;

	inFile.open(fileName.c_str(), ios::binary);

	if (!inFile.good())
	{
		cerr << "Can't open texture file " << fileName << endl;
		return 1;
	}

	inFile.seekg(0, ios::end);

	int size = inFile.tellg();

	data = new char[size];
	cout << fileName << " loaded." << endl;
	inFile.seekg(0, ios::beg);
	inFile.read(data, size);
	inFile.close();


	glBindTexture(GL_TEXTURE_2D, Model_Texture_Num);



	// select modulate to mix texture with color for shading
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_DECAL);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_DECAL);

	// when texture area is small, bilinear filter the closest mipmap
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_NEAREST);
	// when texture area is large, bilinear filter the first mipmap
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	// texture should tile
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

	//build our texture mipmaps
	gluBuild2DMipmaps(GL_TEXTURE_2D, 3, 512, 512, GL_RGB, GL_UNSIGNED_BYTE, data);

	delete[] data;

	return 1;

}


int Model::getPolyCount()
{
	return NUM_POLY;
}

void Model::drawPolygon(int a, int b, int c)
{
	glBegin(GL_TRIANGLES);

	glTexCoord2f(0.0f, 0.0f);
	glVertex3fv(&vertices[a].x);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3fv(&vertices[b].x);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3fv(&vertices[c].x);
	glTexCoord2f(1.0f, 0.0f);

	glEnd();
}
void Model::drawObject()
{
	glBindTexture(GL_TEXTURE_2D, Model_Texture_Num);
	for (int i = 0; i < NUM_POLY; i++)
	{

		glColor3f(122, 65, 34);
		drawPolygon(indices[i].a, indices[i].b, indices[i].c);
	}
}
