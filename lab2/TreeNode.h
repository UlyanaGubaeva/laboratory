#pragma once
class TreeNode
{
public:

	TreeNode();
	TreeNode(int value);

	int getValue();
	void setValue(int val);
	TreeNode* getLeft();
	void setLeft(TreeNode* lef);
	TreeNode* getRight();
	void setRight(TreeNode* rig);

private:
	int value;
	TreeNode *left;
	TreeNode *right;
};

