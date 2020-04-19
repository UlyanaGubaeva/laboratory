#pragma once
#include "TreeNode.h"
class BinaryTree
{
public:
	BinaryTree();
	BinaryTree(int value);
	~BinaryTree();

	TreeNode* Search(int key);
	void Insert(int key);
	void DeleteNodesTree();
	void PrintValue();

private:
	TreeNode* root;
	void Insert(int key, TreeNode* leaf);
	TreeNode* Search(int key, TreeNode* leaf);
	void DeleteNodesTree(TreeNode* leàf);
	void PrintValue(TreeNode* leaf);
};