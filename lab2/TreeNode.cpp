#include "pch.h"
#include "TreeNode.h"


TreeNode::TreeNode()
{
	value = 0;
	left = nullptr;
	right = nullptr;
}

TreeNode::TreeNode(int val)
{
	this->value = val;
	left = nullptr;
	right = nullptr;
}

int TreeNode::getValue() 
{ 
	return value; 
}

void TreeNode::setValue(int val) 
{ 
	value = val; 
}

TreeNode* TreeNode::getLeft() 
{
	return left; 
}

void TreeNode::setLeft(TreeNode* lef) 
{ 
	left = lef; 
}

TreeNode* TreeNode::getRight() 
{ 
	return right; 
}

void TreeNode::setRight(TreeNode* rig) 
{ 
	right = rig; 
}
