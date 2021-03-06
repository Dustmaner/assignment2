#pragma once
#ifndef FILESCANNER_H_
#define FILESCANNER_H_


#include <iostream>
#include <stdio.h>
#include <string>

#include "searchTree.h"
#include "spellCheck.h"

using namespace std;

class fileScanner
{
private:
	void openFile(string fileName);

    void write(Node* treeNode, FILE* insertFile);
//	void fileWriter(Node &binaryTree, FILE* insertFile);

public:

	fileScanner();
	~fileScanner();

	void populateTree(searchTree* &popTree);

	void storeTree(Node* binaryTree);

	bool isValidChar(char c, char b);

    void storeSpell(HashTable dictionary);

};

#endif // FILESCANNER_H
