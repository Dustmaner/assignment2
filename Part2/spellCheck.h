#ifndef SPELLCHECK_H
#define SPELLCHECK_H

#include <string.h>
#include <iostream>
#include <fstream>
#include <stdlib.h>

#include "HashTable.h"

using namespace std;

class spellCheck
{
private:
    HashTable dictionary;

public:

    spellCheck();
    ~spellCheck();

    void dictFromFile(HashTable &dictionary);
    void checkWord(char* word, HashTable& dictionary);

    void spellCheckFile(string filename);

    HashTable& getTable();

};


#endif // SPELLCHECK_H
