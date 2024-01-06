#include <iostream>

using namespace std;
#include "double-linked-list.h"

int main()
{
    DoubleLinkedList dList;
    int item, position;
    dList.traverse(); 
    cout << "Enter an integer to add: ";
    cin >> item;
    cout << "Enter a position: ";
    cin >> position;
    dList.add(item, 0);
    dList.add(24, 1);
    dList.add(93, 2);
    dList.add(75, 0);
    dList.add(100, 8);
    dList.traverse();

    int sizeofList = dList.length();
    cout << "There are " << sizeofList << " nodes in the list." << endl;
    dList.remove(24);
    dList.traverse();

    dList.remove(25);
    dList.remove(100);
    dList.remove(75);
    sizeofList = dList.length();
    cout << "There are " << sizeofList << " nodes in the list." << endl;
    dList.traverse();

    return 0;
}