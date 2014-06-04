#include <iostream>
#include <string>
#include <string.h>
#include <cstdio>
#include <stdio.h>

#include "searchTree.h"
#include "fileScanner.h"

using namespace std;

int main()
{
	searchTree* testSearch = new searchTree;

	fileScanner* reader = new fileScanner;

    reader->populateTree(testSearch);

    reader->storeTree(testSearch->getRoot());

    cout << \n << (testSearch->getRoot())->word;

	return 0;
}
