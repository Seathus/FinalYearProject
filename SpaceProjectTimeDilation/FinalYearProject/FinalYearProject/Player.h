#ifndef PLAYER_H
#define PLAYER_H
#include <Windows.h>
#include <iostream>
#include <string>
#include "Structures.h"
#include "Model.h"
#include "GameObject.h"

using namespace std;


class Player : public Model, public GameObject
{

private:
	string name;
	fposition pos;
	float scale;
	fposition pitch;


public:



	Player(string modelFileName, string modelTextureName, int txturefiles, string Pname, fposition Playerpos, float Pscale)
		: Model(modelFileName, modelTextureName, txturefiles),
		name(Pname), pos(Playerpos), scale(Pscale)
	{

	}

	~Player();
	fposition * getPlayerPos();
	void Pitch(string sign, string posType);
	void MovePlayerPos(string target, string type);
	void update();
	void draw();

};
#endif