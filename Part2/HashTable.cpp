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

void HashTable::suggestWord(char* word, int hashValue, int bucket)
{
        cout << "Word was not found: " << word << endl;
        cout << "try these instead: "<< endl;

        list<char*>::const_iterator i;
        for(i = buckets[bucket].begin(); i != buckets[bucket].end(); i++)
        {
            cout << *i << endl;
        }
     //loop lists, loop buckets
}

void HashTable::findWord(char* word)
{
    bool found;
    int wordValue = hash(word);
    int i;
    int bucket = 0;

    for(i = 0; i < BUCKETCOUNT; i++)
    {
        list<char*>::iterator findIter = find(buckets[i].begin(), buckets[i].end(), word);
        if(findIter == buckets[i].end())
        {
            found = false;
            bucket = i;
        }

    }

    if(found == false)
         suggestWord(word, wordValue, i);



    //// SEARCH FOR THE HASH YOU IDIOT
}
