#pragma once
#include <string>
#include <vector>
#include "Planet.h"
class Node : public Planet
{
private:
	Node* parent;
	std::string name;
	std::vector<Node*> children;

public:
	Node(string modelFileName, string modelTextureName, int txturefiles, string Pname, float Pradius, position Ppos, float ProtIndex, int Pr, int Pg, int Pb, float Pscale) 
		: Planet(modelFileName, modelTextureName, txturefiles, Pname, Pradius, Ppos, ProtIndex, Pr, Pg,Pb, Pscale)
	{
		parent = NULL;
		
		//name = NULL;
	}
	~Node();

	Node* GetParentNode(void) const;
	void SetParentNode(Node* newParent);

	std::vector<Node*>* GetChildNodes();

	void AddChildNode(Node* childNode);
	void RemoveChildNode(Node* childNode);

	void SetNodeName(std::string name);
	std::string GetNodeName() const;
	const size_t CountChildNodes(const bool& RecursiveCount = false) const;

	void DrawChildren();
	void Draw() override;
};

