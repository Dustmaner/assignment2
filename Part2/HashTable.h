#ifndef HASHTABLE_H_
#define HASHTABLE_H_

#define BUCKETCOUNT 42

#include <iostream>
#include <cassert>
#include <list>

using namespace std;

class HashTable
{
public:
    HashTable();
    ~HashTable();

    void insert(char* word);

    char* suggestWord(char* word);

private:
    list<char*> buckets[BUCKETCOUNT];
    int hash(char* word);

};

#endif
