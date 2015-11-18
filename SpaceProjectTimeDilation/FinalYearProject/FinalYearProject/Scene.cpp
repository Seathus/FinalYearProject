#include "Scene.h"
#include <tchar.h>
#include <string>
#include <string.h>

Scene::Scene()
{
	
	position sunPos;
	sunPos.posx = 0;
	sunPos.posy = 0;
	sunPos.posz = 0;
	this->root = new Node("planet.txt", "Textures/Planets/Planet5.raw", 1, "Sun", 4.0f, sunPos, 1.0f, 1.0f, 1.0f, 0.0f, 0.10f);
	this->root->SetNodeName("Sun");
	//Node* wierdNode = this->root->GetParentNode();
	//cout << wierdNode->GetNodeName() << std::endl;
	position temp;
	temp.posx = 0;
	temp.posy = 0;
	temp.posz = 0;
	Node* planet = new Node("planet.txt", "Textures/Planets/Planet5.raw", 1, "Earth", 4.0f, temp, 1.0f, 1.0f, 1.0f, 0.0f, 0.6f);
	planet->SetNodeName("earth");
	planet->SetParentNode(this->root);
	
	//planet->SetParentNode(this->root);

	//Planet* moon = new Planet("PlanetModel.obj", "", 1, "");
	


	
	this->root->AddChildNode(planet);
	int fice = 5;
}


Scene::~Scene()
{

}

void Scene::initialize()
{
	/*can move this to planet constructor once it's working.*/
	
	
}

void Scene::draw()
{
	
	//this->root->getPlanetPos();
	this->root->Draw();
	root->DrawChildren();
	
}