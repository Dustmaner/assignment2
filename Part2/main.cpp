#include <iostream>
#include <string>
#include <string.h>
#include <cstdio>
#include <stdio.h>

#include "searchTree.h"
#include "fileScanner.h"
#include "HashTable.h"

using namespace std;

int hashFunc(int num)
{
    return (num % 19);
}

int main()
{
	searchTree* testSearch = new searchTree;

	fileScanner* reader = new fileScanner;

    reader->populateTree(testSearch);

    reader->storeTree(testSearch->getRoot());

    HashTable<string> testHash(200);

    int keyNum;
    string newString;

    cout << "Insert 16 nums and a string" << endl;
    for(int i = 0; i < 16; i++)
    {
        cin >> keyNum;
        int key = hashFunc(keyNum);
        cout << "New String" << endl;
        cin >> newString;
        testHash.insert(key, newString);
    }

	return 0;
}
