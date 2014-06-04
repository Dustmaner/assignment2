#pragma once
#ifndef FILESCANNER_H_
#define FILESCANNER_H_


#include <iostream>
#include <stdio.h>
#include <string>

#include "searchTree.h"

using namespace std;

class fileScanner
{
private:
	void openFile(string fileName);

public:

	fileScanner();
	~fileScanner();

	void populateTree(searchTree* &popTree);

	void storeTree(Node* binaryTree);

	bool isValidChar(char c, char b);
};

#endif // FILESCANNER_H
