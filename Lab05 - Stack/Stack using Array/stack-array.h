// Program for stack implementation using arrays.
#include <stdexcept>
class StackArray
{
private:
    int MAXSIZE;
    int top;
    int stack[100];

public:
    StackArray() //Constructor
    {
        top = -1;
        MAXSIZE = 100;
    }

    int isEmpty() const
    {
        return (top == -1);
    }

    int isFull() const
    {
        return (top == MAXSIZE - 1); //If top is equal to MAXSIZE - 1, then stack is full
    }
    void push(int data); // Inserts 'data' in the stack
    int pop();           // Removes the topmost element from the stack
    int getTop() const;  // Returns the topmost element from the stack
    void destroy();      // Deletes all elements from the stack
    void traverse() const; //Traverse the stack
    int length() const{
        return (top + 1);
    }
};

void StackArray::push(int data)
{
    if (isFull())
    {
        throw overflow_error("Stack is Overflow!");
    }

    //Otherwise if stack is not full, then do the following operations
    stack[++top] = data;
}
int StackArray::pop() {
    if (isEmpty())
    {
        throw underflow_error("Stack is Underflow!");
    }

    return stack[top--];
}
int StackArray::getTop() const
{
    if (isEmpty())
    {
        throw underflow_error("Stack is empty!");
    }

    //Otherwise if stack is not empty
    return stack[top];

}
void StackArray::destroy(){
    top = -1;
}

void StackArray :: traverse()const   //Traverse the stack
{
    if (isEmpty())
    {
        throw underflow_error("Stack is empty!");
    }

    for (int i = 0; i <= top; i++)
    {
        cout << stack[i] << " ";
    }
    cout << endl;
}