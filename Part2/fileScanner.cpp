
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

    char insWord[20];
	insertFile = fopen("Ass2Dictionary.txt", "r");

    char c;

    do
    {
        char strippedWord[20];
        c = fscanf(insertFile, "%s", insWord);
        int c = 0; //iterator and char tracker
        for(unsigned int i = 0; i < strlen(insWord); i++)
        {
            if(isValidChar(insWord[i], insWord[i+1]))
            {
                strippedWord[c] = insWord[i];
                c++;
            }
            else
                break;
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
    FILE *storageFile;
    storageFile = fopen("dict.txt", "a");

	if(binaryTree == NULL)
		{
			cout << "No Nodes";
			return;
		}

	storeTree(binaryTree->leftNode);

    fputs(binaryTree->word, 'storageFile');
    storageFile << (binaryTree->word);
    cout << binaryTree->word << " ";
//	cout << searchTree->word << endl;

	storeTree(binaryTree->rightNode);

	fclose(storageFile);
}


bool fileScanner::isValidChar(char c, char b)
{
    bool isValid = false;

    switch(c)
    {
    case '-':
            if(b != '-')
                isValid = true;
            break;
    case '\'':
            isValid = true;
            break;
    default:
            if(isalpha(c))
                isValid = true;
                break;
    }


    return isValid;
}
