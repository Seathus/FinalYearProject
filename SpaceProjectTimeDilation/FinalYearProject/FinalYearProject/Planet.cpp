#include "Planet.h"


Planet::~Planet()
{
	cout << "Planet Destroyed.";
	delete[] loop;
}

string Planet::getname()
{
	return name;
}

position Planet::getPosition()
{
	return pos;
}


float Planet::getRot()
{
	return rot;
}

float Planet::getradius()
{
	return radius;
}

float Planet::getRotIndex()
{
	return rotIndex;
}

float Planet::getScale()
{
	return scale;
}

circle Planet::getPlanetPos()
{
	circle loopPos;
	loopPos.x = loop[(int)(ceil(speed))].x;
	loopPos.y = loop[(int)(ceil(speed))].y;
	loopPos.z = loop[(int)(ceil(speed))].z;
	return loopPos;
}

void Planet::getCalcPlanetCircle()
{

	for (int i = 0; i < 600; i++)
	{
		loop[i].x = radius * sin(i / 100.0);
		loop[i].y = 0;
		loop[i].z = radius * cos(i / 100.0);
	}
}


void Planet::update()
{

	speed += rotIndex;
	if (speed >= 600)
	{
		speed = 0;
	}

	getCalcPlanetCircle();

}

void Planet::Draw()
{

	glPushMatrix();
	glColor3f(1.0, 0.0, 0.0);
//	if (this->GetParentNode() != NULL)
//	{
//		glTranslated(loop[(int)(ceil(speed))].x, loop[(int)(ceil(speed))].y, loop[(int)(ceil(speed))].z);
//		glRotated(60, 0, 0, 1);
//	}
//	else
//	{
	glTranslated(this->pos.posx + 5, this->pos.posy + 5, this->pos.posz + 5);
	glRotated(60, 0, 0, 1);
	//glTranslated(loop[(int)(ceil(speed))].x, loop[(int)(ceil(speed))].y, loop[(int)(ceil(speed))].z);
	//	glRotated(60, 0, 0, 1);
//	}
	
	glScalef(scale, scale, scale);
	drawObject();
	glPopMatrix();

}
