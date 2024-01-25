//To test stack data structure defined in stack-array.h file

#include <iostream>

using namespace std;

#include "linked-stack.h"

int main(){
    Stack stack;
    stack.push(95);
    stack.push(25);    
    stack.push(55);
    cout<<stack.getTop()<<endl;     //55  
    cout<<stack.pop()<<endl;        //55  
    cout<<stack.getTop()<<endl;     //25  
    cout<<stack.isEmpty()<<endl;    //0
    
    stack.push(75);
    
    cout<<stack.pop()<<endl;        //75
    cout<<stack.isEmpty()<<endl;    //0
    cout<<stack.getTop()<<endl;     //  
    cout<<stack.pop()<<endl;        // 
    cout<<stack.getTop()<<endl;     //  
    cout<<stack.pop()<<endl;        // 
    cout<<stack.getTop()<<endl;     //  
    cout<<stack.pop()<<endl;        //
    
    return 0;
}