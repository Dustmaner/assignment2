#include <iostream>
#include <fstream>
#include <stdio.h>
#include <cstdio>
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
            if(insWord[i] == '-' && insWord[i + 1] == '-')
            {
                i++;
            }
            else if(isValidChar(insWord[i], insWord[i+1]))
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
    storeTree(popTree->getRoot());

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
            if(b != ' ')
                isValid = true;
            break;
    default:
            if(isalpha(c))
                isValid = true;
                break;
    }

    return isValid;
}

void fileScanner::storeTree(Node* binaryTree)
{
    FILE *storageFile = fopen("dict.txt", "w");
    write(binaryTree, storageFile);
	fclose(storageFile);
	cout << "\nDictionary stored in dict.txt" << endl;
}

void fileScanner::write(Node* fileNode, FILE* insertFile)
{
    if(!fileNode)
        return;

    write(fileNode->leftNode, insertFile);

    char *c = new char[fileNode->word.size() + 1];
    c[fileNode->word.size()] = '\0';
    strcpy(c, fileNode->word.c_str());

    fputs(c, insertFile);
    fputs("\n", insertFile);

    write(fileNode->rightNode, insertFile);
}

void fileScanner::storeSpell(HashTable dictionary)
{
    ifstream inputFile("Eisenhowerspell.txt");

    while(inputFile.good())
    {
        char cstr [20];
        inputFile.get(cstr, 20);
    cout << "ceh";
        dictionary.findWord(cstr);
    }
}
