
#include <iostream>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>

#include "fileScanner.h"



using namespace std;

fileScanner::fileScanner()
{

}

fileScanner::~fileScanner()
{

}

void fileScanner::populateTree(searchTree* &popTree)
{
	FILE *insertFile;

    char insWord[16];
	insertFile = fopen("Ass2Dictionary.txt", "r");

    char c;

    do
    {
        char strippedWord[16];
        c = fscanf(insertFile, "%s", insWord);
        int c = 0; //iterator and char tracker
        for(int i = 0; i < strlen(insWord); i++)
        {
            if(isalpha(insWord[i]))
            {
                strippedWord[c] = insWord[i];
                c++;
            }
        }
        strippedWord[c] = '\0';
        popTree->insert(strippedWord);
    }
    while (c != EOF);
    fclose(insertFile);
    cout << "\nThe tree has finished populating";
    popTree->report();

}

void fileScanner::storeTree(Node* binaryTree)
{
    ofstream storageFile;
    storageFile.open("dict.txt");

	if(binaryTree == NULL)
		{
			return;
			cout << "end";
		}

	storeTree(binaryTree->leftNode);

    storageFile << (binaryTree->word);
    cout << binaryTree->word << " ";
//	cout << searchTree->word << endl;

	storeTree(binaryTree->rightNode);

	storageFile.close();
}


void fileScanner::checkshit()
{

}
