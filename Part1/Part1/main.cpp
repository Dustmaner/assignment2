#include <iostream>
#include "minimalSpanTreeType.h"

using namespace std;

int main()
{
    msTreeType<int, 50> spanTree;

    cout << "----Prims Algorithm----" << endl;

    spanTree.createSpanningGraph();
    spanTree.prim2(0);
    spanTree.printTreeAndWeight();

    return 0;
}
