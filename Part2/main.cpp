#include <iostream>
#include <string>
#include <string.h>
#include <cstdio>
#include <stdio.h>

#include "searchTree.h"
#include "fileScanner.h"
#include "spellCheck.h"

using namespace std;

int main()
{
    char start;
    fileScanner* reader = new fileScanner; //Initialise class for file reading

    cout << "-------Data Structures and Algorithms-------" << endl;
    cout << "----------Assignment Part 2----------" << endl;
    cout << "What part would you like to view? Insert a or b. Press f to quit" << endl;
    cout << "**********WARNING IT IS RECOMMENDED THAT PART A BE RUN FIRST***********" << endl;
    cin >> start;

    if(start != 'f' && start != 'a' && start != 'b')
    {
        cout << "\nInvalid input. Quitting program\n";
        return 0;
    }
    else
    {
    while(start != 'f')
    {
        if(start == 'a')
        {
            searchTree* testSearch = new searchTree; //Initialise tree



            reader->populateTree(testSearch); //Populate the AVL tree from Ass2Dictionary.txt

            start = 'p';
            cout << "What part would you like to view?"
            << "Insert a or b. Press f key to quit" << endl;
            cin >> start;
        }
        else if(start == 'b')
        {
            spellCheck* dictCheck = new spellCheck;

            dictCheck->dictFromFile(dictCheck->getTable());

            reader->storeSpell(dictCheck->getTable());


            start = 'p';
            cout << "What part would you like to view? Insert a or b. Press f key to quit" << endl;
            cin >> start;
        }
    }
    }
	return 0;
}
