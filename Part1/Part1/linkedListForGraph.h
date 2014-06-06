#ifndef H_LinkedListForGraph
#define H_LinkedListForGraph

#include <iostream>
#include <list>

using namespace std;

template<class vType>
class linkedListGraph: public linkedListType<vType>
{
public:
    void getAdjacentVertices(vType adjacencyList[], int& length);
};

template<class vType>
void linkedListGraph<vType>::getAdjacentVertices(vType adjacencyList[], int& length)
{
    nodeType<vType> *current;

    length = 0;
    current = first;

    while(current != NULL)
    {
        adjacencyList[length++] = current->info;
        current = current->link;
    }
}

#endif
