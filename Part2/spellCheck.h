#ifndef SPELLCHECK_H
#define SPELLCHECK_H

#include <string.h>
#include <iostream>
#include <stdlib.h>

#include "HashTable.h"

using namespace std;

class spellCheck
{
private:
    HashTable spellTable();

public:

    spellCheck();
    ~spellCheck();

    void dictFromFile(string fileName);
    void checkWord(char* word);

    void spellCheckFile(string filename);

};


#endif // SPELLCHECK_H
