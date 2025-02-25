//To test stack data structure defined in stack-array.h file

#include <iostream>

using namespace std;

#include "stack-array.h"

int main(){
    StackArray s;
    s.push(21);
    s.push(35);
    cout<<"The topmost element is: "<<s.getTop()<<endl;     // 35
    cout<<"The popped element is: "<<s.pop() <<endl;        // 35
    cout<<"The topmost element is: "<<s.getTop()<<endl;     //21
    cout<<"Is stack is empty? : "<<s.isEmpty()<<endl;    //False
    cout<<"Is stack is full? : "<<s.isFull()<<endl;     //False
    s.push(27);
    s.push(12);
    cout<<"The popped element is: "<<s.pop() <<endl;       // 12
    cout<<"The popped element is: "<<s.pop() <<endl;
    cout<<"The popped element is: "<<s.pop() <<endl;
    cout<<"Is stack is empty? : "<< s.isEmpty()<<endl;    //true
    return 0;
}