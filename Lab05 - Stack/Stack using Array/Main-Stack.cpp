//To test stack data structure defined in stack-array.h file

#include <iostream>

using namespace std;

#include "stack-array.h"

int main(){
    Stack s;
    s.push(21);
    s.push(35);
    cout<<s.getTop()<<endl; //35
    cout<<s.pop()<<endl;//35
    cout<<s.getTop()<<endl;//21
    cout<<s.isEmpty()<<endl; //False
    cout<<s.isFull()<<endl; //false
    
    cout<<s.pop()<<endl; //21
    cout<<s.isEmpty()<<endl;//true
    return 0;
}