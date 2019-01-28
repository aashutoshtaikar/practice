#include<iostream>
#include "BTree.h"
using namespace std;

int main()
{
    BTree myTree;
    myTree.insert(1);
    myTree.insert(2);
    myTree.insert(3);

    BTree* temp = nullptr;
    temp = myTree.search(2);
    cout << temp->getVal();
    delete temp;

    return 0;
}
