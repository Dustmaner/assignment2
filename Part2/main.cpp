#include <iostream>
#include <string>
#include <string.h>
#include <cstdio>
#include <stdio.h>

#include "searchTree.h"
#include "fileScanner.h"
//#include "spellCheck.h"

using namespace std;

int main()
{
	searchTree* testSearch = new searchTree;

	fileScanner* reader = new fileScanner;

    reader->populateTree(testSearch);

    reader->storeTree(testSearch->getRoot());

	return 0;
}
