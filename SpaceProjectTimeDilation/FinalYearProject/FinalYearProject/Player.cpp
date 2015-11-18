#include <Windows.h>
#include "Player.h"
#include <GL/gl.h>
#include <GL/glu.h>
#include "glut.h"
#include <fstream>
#include <sstream>


Player::~Player()
{
	cout << name << " Destroyed.";
}

fposition * Player::getPlayerPos()
{
	return &pos;
}

void Player::Pitch(string sign, string posType)
{
	if (posType == "x" && sign == "-")
	{
		pitch.posx -= 5;

	}
	else if (posType == "y" && sign == "-")
	{
		if (!pitch.posy <= -30)
		{
			pitch.posy -= 30;

			if (pitch.posy < -30)
			{
				//cout << "DERP TOO LOW" << endl;
			}
		}
	}
	else if (posType == "z" && sign == "-")
	{
		pitch.posz -= 0.5;
	}
	else if (posType == "x" && sign == "+")
	{
		pitch.posx += 55;
	}
	else if (posType == "y" && sign == "+")
	{
		pitch.posy += 30;

		if (pitch.posy > 90)
		{
			//cout << "DERP TOO HIGH" << endl;
		}
	}
	else if (posType == "z" && sign == "+")
	{
		pitch.posz += 0.5;
	}
	else
	{
		cout << "ERROR: Unable to move pos" << endl;
	}

}

void Player::MovePlayerPos(string sign, string posType)
{
	if (posType == "x" && sign == "-")
	{
		pos.posx -= 0.5;

	}
	else if (posType == "y" && sign == "-")
	{
		pos.posy -= 0.5;

	}
	else if (posType == "z" && sign == "-")
	{
		pos.posz -= 0.5;
	}
	else if (posType == "x" && sign == "+")
	{
		pos.posx += 0.5;
	}
	else if (posType == "y" && sign == "+")
	{
		pos.posy += 0.5;
	}
	else if (posType == "z" && sign == "+")
	{
		pos.posz += 0.5;
	}
	else
	{
		cout << "ERROR: Unable to move pos" << endl;
	}
}

void Player::update()
{

	pos.posx;
	pos.posy;
	pos.posz;

}

void Player::draw()
{
	//glBindTexture(GL_TEXTURE_2D, image_Array[val]);
	glPushMatrix();
	glColor3f(1.0, 0.0, 0.0);
	glTranslated(pos.posx, pos.posy, pos.posz);
	glScalef(scale, scale, scale);
	drawObject();
	glPopMatrix();
}