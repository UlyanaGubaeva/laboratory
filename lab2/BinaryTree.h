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
	TreeNode* CreateMinimalBST(int start[], int first, int last);
	void SetRoot(TreeNode* root); 
private:
	TreeNode* root;
	void Insert(int key, TreeNode* leaf);
	TreeNode* Search(int key, TreeNode* leaf);
	void DeleteNodesTree(TreeNode* le�f);
	void PrintValue(TreeNode* leaf);
	
};