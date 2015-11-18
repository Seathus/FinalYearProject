#pragma once
#include "Node.h"
#include "Planet.h"
#include <vector>
class Scene
{
private:
	Node* root;

public:
	Scene();
	~Scene();
	void initialize();
	void draw();
};

