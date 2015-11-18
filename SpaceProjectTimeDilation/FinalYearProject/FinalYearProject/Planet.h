#pragma once
#include "Model.h"
#include "GameObject.h"
#include <string>

class Planet : public Model, public GameObject
{
private:
	string name;
	position pos;
	
	float scale;
	int r;
	int g;
	int b;
	
	float x;
	float y;
	float z;

public:
	Planet(string modelFileName, string modelTextureName, int txturefiles, string Pname, float Pradius, position Ppos, float ProtIndex, int Pr, int Pg, int Pb, float Pscale)
		: Model(modelFileName, modelTextureName, txturefiles),
		name(Pname), radius(Pradius), pos(Ppos), rotIndex(ProtIndex), r(Pr), g(Pg), b(Pb), scale(Pscale)
	{
		cout << "Planet " << Pname << " created" << endl;
		speed = 0;
		loop = new circle[600];
		read_file(modelFileName);
		loadTexture(modelTextureName);
		pos.posx = Ppos.posx;
		pos.posy = Ppos.posy;
		pos.posz = Ppos.posz;
		scale = Pscale;
	}
	Planet()
	{

	}
	~Planet();

	circle *loop;
	float rot;
	float radius;
	float rotIndex;
	float speed;

	string getname();

	position getPosition();

	float getRot();
	float getradius();
	float getslices();
	float getstacks();
	float getRotIndex();
	float getScale();

	circle getPlanetPos();

	void getCalcPlanetCircle();
	void update();
	virtual void Draw();
	
};

