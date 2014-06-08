#include "HashTable.h"

using namespace std;

HashTable::HashTable()
{
    for(int i = 0; i < BUCKETCOUNT; i++)
    {
        buckets[*i] = new list<char*>;
    }
}

HashTable::~HashTable()
{
    for(int i = 0; i < BUCKETCOUNT; i++)
    {
        delete buckets[i];
    }
}

void HashTable::insert(char* word)
{
    int bucket = hash(word);
    buckets[bucket].push_back(word);
}

int HashTable::hash(char* word)
{
    int value = 0;
    char* c = word;

    for(int i = 0; i < 3 && *c != '\0' ; i++)
    {
        value += (int)*c;
    }

    unsigned int hashValue = hashvalue % BUCKETCOUNT;

    return hashValue;
}

char* HashTable::suggestWord(char* word)
{
    int bucket = hash(word);

    buckets[bucket]//search list for word, return suggestion if not found

    for(int i = 0; i < buckets.size; i++)
    {
        for(int j = 0; j < buckets[i].size; j++)
        {

        }
    }
                        //loop lists, loop buckets
}
