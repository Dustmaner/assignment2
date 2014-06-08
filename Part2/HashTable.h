#ifndef HASHTABLE_H_
#define HASHTABLE_H_

#define BUCKETCOUNT 42

#include <iostream>
#include <stdio.h>
#include <cassert>
#include <list>
#include <algorithm>

using namespace std;

class HashTable
{
public:
    HashTable();
    ~HashTable();

    void insert(char* word);

    void findWord(char* word);



private:
    list<char*> buckets[BUCKETCOUNT];
    int hash(char* word);

    void deleteTable();

    char* suggestWord(char* word);
};

#endif
