#pragma once
#ifndef SEARCHTREE_H_
#define SEARCHTREE_H_

#include <string>
#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <string.h>

using namespace std;

struct Node
{
	int balanceFactor; //AVL Tree Balance Factor
	string word;
	Node* leftNode;
	Node* rightNode;
};

class searchTree
{
protected:
	Node* root;
	Node* leftNode;
	Node* rightNode;

	void insertNode(Node* &rootPtr, Node* newNode, bool &isTaller);

    void deleteTree(Node* delNode);

	string caseConvert(string word);

	void rotateLeft(Node* &root);
	void rotateRight(Node* &root);

	void balanceFromLeft(Node* &root);
	void balanceFromRight(Node* &root);

	int maxDepth(Node* checkNode);

public:
	int nodeCount;

	searchTree();
	~searchTree();

	void insert(string insertWord);

	void printTree(Node* searchTree);

	Node* getRoot();

	void report();

	void findWord(string word);
};



#endif // SEARCHTREE_H
