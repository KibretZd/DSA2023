// Program for stack implementation using arrays.
#include <stdexcept>
class Stack
{
private:
    int MAXSIZE;
    int top;
    int stack[100];

public:
    Stack()
    {
        top = -1;
        MAXSIZE = 100;
    }

    int isEmpty() const
    {
        return top == -1;
    }

    int isFull() const
    {
        return top == MAXSIZE - 1;
    }
    void push(int data); // Inserts 'data' in the stack
    int pop();           // Removes the topmost element from the stack
    int getTop() const;  // Returns the topmost element from the stack
    void destroy();      // Deletes all elements from the stack

    int length() const{
        return top + 1;
    }
};

void Stack::push(int data)
{
    if (isFull())
    {
        throw overflow_error("Stack Overflow!");
    }

    //Otherwise if stack is not full, then do the following operations
    top++;
    stack[top] = data;
}
int Stack::pop() {
    if (isEmpty())
    {
        throw underflow_error("Stack Underflow!");
    }

    // int poppedElement = stack[top];
    // top--;
    // return poppedElement;

    return stack[top--];
}
int Stack::getTop() const
{
    if (isEmpty())
    {
        throw underflow_error("Stack is empty!");
    }

    //Otherwise if stack is not empty
    return stack[top];

}
void Stack::destroy(){
    top = -1;
}