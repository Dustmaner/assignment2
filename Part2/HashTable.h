#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <iostream>
#include <cassert>

using namespace std;

template<class Type>
class HashTable
{
    private:
        Type *HTable;
        int *indexStatusList;
        int length;
        int HTSize;

    public:
        HashTable(int size = 101);
        ~HashTable();

        void insert(int hashIndex, const Type& rec);
        void search(int& hashIndex, const Type& rec, bool&found);
        bool isItemAtEqual(int hashIndex, const Type& rec);
        void retrieve(int hasIndex, Type& rec);
        void remove(int hashIndex, const Type& rec);
        void print() const;
};

template<class Type>
void HashTable<Type>::insert(int hashIndex, const Type& rec)
{
    int pCount = 0;
    int inc= 1;

    while(indexStatusList[hashIndex] == 1 && HTable[hashIndex] != rec && pCount < HTSize / 2)
    {
        pCount++;
        hashIndex=(hashIndex + inc) % HTSize;
        inc = inc + 2;
    }

    if(indexStatusList[hashIndex] != 1)
    {
        HTable[hashIndex] = rec;
        indexStatusList[hashIndex] = 1;
        length++;
    }
    else if(HTable[hashIndex] == rec)
        cerr << "Error: No duplicates allowed" << endl;
    else
        cerr << "Error: the Table is Full" << endl;
}

template<class Type>
void HashTable<Type>::search(int& hashIndex, const Type& rec, bool& found)
{
    int pCount = 0;
    int inc = 1;

    while(indexStatusList[hashIndex] != 0 && HTable[hashIndex] != rec && pCount < HTSize /2)
    {
        pCount++;
        hashIndex = (hashIndex + inc) % HTSize;
        inc = inc + 2;
    }

    if(indexStatusList[hashIndex] == 1 && HTable[hashIndex] == rec)
    {
        hashIndex = hashIndex;
        found = true;
    }
    else
        found = false;
}

template<class Type>
bool HashTable<Type>::isItemAtEqual(int hashIndex, const Type& rec)
{
    return(HTable[hashIndex] == rec);
}

template<class Type>
void HashTable<Type>::retrieve(int hashIndex, Type& rec)
{
    if(indexStatusList[hashIndex] == 1)
        rec = HTable[hashIndex];
}

template<class Type>
void HashTable<Type>::remove(int hashIndex, const Type& rec)
{
    bool found;

    search(hashIndex, rec, found);

    if(found)
    {
        indexStatusList[hashIndex] = -1;
        length--;
    }
    else
        cerr << "The item to be deleted is not in the list" << endl;
}

template<class Type>
void HashTable<Type>::print() const
{
    for(int i = 0; i < HTSize; i++)
    {
        if(indexStatusList[i] != 0)
        {
            cout << i << " " << indexStatusList[i] << " " << HTable[i] << endl;
        }
    }
}

template<class Type>
HashTable<Type>::HashTable(int size)
{
    assert(size > 0);

    HTable = new Type[size];
    indexStatusList = new int[size];
    length = 0;
    HTSize = size;
    for(int i = 0; i <size; i++)
        indexStatusList[i] = 0;
}

template<class Type>
HashTable<Type>::~HashTable()
{
    delete [] HTable;
    delete [] indexStatusList;
}

#endif // HASHTABLE_H
