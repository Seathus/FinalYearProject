#include "Node.h"


Node::~Node()
{
}

std::vector<Node*>* Node::GetChildNodes()
{
	if (!children.empty())
	{
		return &(this->children);
	}
}

Node* Node::GetParentNode(void) const
{
	return(parent);
}; // GetParentNode()

void Node::SetParentNode(Node* NewParent)
{
	if (NULL != parent)
	{
		parent->RemoveChildNode(this);
	}
	parent = NewParent;
}; // SetParentNode()

void Node::AddChildNode(Node* ChildNode)
{
	//checks if child node exists
	if (NULL != ChildNode)
	{
		//checks if the new child already has a parent node.
		if (ChildNode->GetParentNode() != NULL)
		{
			ChildNode->SetParentNode(this);
		}
		children.push_back(ChildNode);
	}
}; // AddChildNode()

void Node::RemoveChildNode(Node* ChildNode)
{
	if (NULL != ChildNode && !children.empty())
	{
		for (int i = 0; i < children.size(); ++i)
		{
			if (children[i] == ChildNode)
			{
				children.erase(children.begin() + i);
				break; // break the for loop
			}
		}
	}
}; // RemoveChildNode()

void Node::SetNodeName(std::string name)
{
	this->name = name;
}

std::string Node::GetNodeName() const
{
	return(name);
}; 


const size_t Node::CountChildNodes(const bool &RecursiveCount) const
{
	if (!RecursiveCount)
	{
		return(children.size());
	}
	else
	{
		size_t Retval = children.size();
		for (size_t i = 0; i <children.size(); ++i)
		{
			Retval += children[i]->CountChildNodes(true);
		}
		return(Retval);
	}
}; // CountChildNodes()

void Node::DrawChildren()
{
	for (int i = 0; i < children.size(); i++)
	{
		children[i]->Draw();
		children[i]->DrawChildren();
	}
}

void Node::Draw()
{
	glPushMatrix();
	glColor3f(1.0, 0.0, 0.0);
		if (this->GetParentNode() != NULL)
		{
			//glTranslated(loop[(int)(ceil(speed))].x, loop[(int)(ceil(speed))].y, loop[(int)(ceil(speed))].z);
			glTranslated(parent->getPosition().posx + 25, parent->getPosition().posy + 25, parent->getPosition().posz + 25);
			//glRotated(60, 0, 0, 1);
		}
		else
		{
			glTranslated(this->getPosition().posx, this->getPosition().posy, this->getPosition().posz);
			//glRotated(60, 0, 0, 1);
			//glTranslated(loop[(int)(ceil(speed))].x, loop[(int)(ceil(speed))].y, loop[(int)(ceil(speed))].z);
			//	glRotated(60, 0, 0, 1);
		}

		glScalef(this->getScale(), this->getScale(), this->getScale());
	drawObject();
	glPopMatrix();
}

