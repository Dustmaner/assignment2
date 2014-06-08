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
//    storeTree(popTree->getRoot());

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
    if(binaryTree != NULL)
    {
    FILE *storageFile = fopen("dict.txt", "a+");

    storeTree(binaryTree->leftNode);

    char *c = new char[binaryTree->word.size() + 1];
    c[binaryTree->word.size()] = '\0';
//    memcpy(c, binaryTree->word.c_str(), binaryTree->word.size());
    strcpy(c, binaryTree->word.c_str());

    fputs(c, storageFile);
    fputs("\n", storageFile);

    storeTree(binaryTree->rightNode);

	fclose(storageFile);
    }
}


void searchTree::inOrder(string& buffer)
{
    Node* node = this->getRoot();

    inOrder(buffer, node->leftNode);
    buffer += node->word + '\n';
    inOrder(buffer, node->rightNode);
}

void searchTree::inOrder(string& buffer, Node* node)
{
    if (node == NULL)
        return;

    inOrder(buffer, node->leftNode);
    buffer += node->word + '\n';
    inOrder(buffer, node->rightNode);
}
