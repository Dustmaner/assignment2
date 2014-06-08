#include "HashTable.h"

using namespace std;

HashTable::HashTable()
{
    for(int i = 0; i < BUCKETCOUNT; i++)
    {
        list<char*> newList;
        buckets[i].assign(newList.begin(), newList.end());
    }
}

HashTable::~HashTable()
{
    for(int i = 0; i < BUCKETCOUNT; i++)
    {
        delete &buckets[i];
    }
}

void HashTable::insert(char* word)
{
    int bucket = hash(word);
    printf("%s ...... %i", word, bucket);
    cout << "\n";
    buckets[bucket].push_back(word);
}

int HashTable::hash(char* word)
{
    char* c = word;
    unsigned int hashValue = 0;

    for(int i = 0; i < 3 && *c != '\0' ; i++)
    {
        hashValue += (int)*c;
    }

    hashValue = hashValue % BUCKETCOUNT;

    return hashValue;
}

char* HashTable::suggestWord(char* word)
{

       char* c = '\0';

       return c;             //loop lists, loop buckets
}

void HashTable::findWord(char* word)
{
    bool found = false;
    int wordValue = hash(word);

    list<char*>::iterator findIter = find(buckets->begin(), buckets->end(), word);

    //// SEARCH FOR THE HASH YOU IDIOT
}
