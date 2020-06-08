#include "pch.h"
#include <iostream>
#include "BinaryTree.h"
#include "TreeNode.h"

using namespace std;

TreeNode* BinaryTree::CreateMinimalBST(int start[], int first, int last)
{
	if (last < first)
		return nullptr;

	const int mid = (first + last) / 2;
	auto treeN = new TreeNode(start[mid]);

	treeN->setLeft(CreateMinimalBST(start, first, mid - 1));
	treeN->setRight(CreateMinimalBST(start, mid + 1, last));

	return treeN;
}

int main() 
{
	//Task 1
	BinaryTree *tree = new BinaryTree();
	tree->Insert(9);
	tree->Insert(11);
	tree->Insert(7);
	tree->Insert(8);
	tree->Insert(10);
	tree->Insert(2);
	tree->Insert(1);
	tree->Insert(13);
	tree->PrintValue();
	cout << tree->Search(8)-> getValue() << "\n";
	cout << tree->Search(9)-> getRight() -> getValue() << "\n";
	delete tree;

	//Task 2
	BinaryTree tree2;
	int start[9] = { 1,5,6,8,11,14,18,36,97 };
	tree2.SetRoot(tree2.CreateMinimalBST(start, 0, 8));
	tree2.PrintValue(); 
}