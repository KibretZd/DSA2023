// Linked list implementation of stack data structure

struct Node
{
    int data;
    Node *next;
};

class Stack
{
private:
    Node *top;
    int count;

public:
    Stack();
    ~Stack();
    int isEmpty() const;
    void push(int item);
    int pop();
    int getTop() const;
    int length() const; // Returns the number of items/nodes in stack
    void destroy();
};

Stack ::Stack()
{
    top = NULL;
    count = 0;
}
Stack ::~Stack()
{
    destroy();
}

void Stack ::destroy()
{
    Node *temp;
    while (top != NULL)
    {
        temp = top;
        top = top->next;
        delete temp;
    }
}

int Stack ::isEmpty() const
{
    return top == NULL;
}
void Stack ::push(int item)
{
    Node *temp = new Node;
    temp->data = item;
    temp->next = top;
    top = temp;
    count++;
}
int Stack ::pop()
{
    if (isEmpty())
    {
        cout << "Stack underflow!" << endl;
        return -1;
    }
    Node *temp = top;
    int deletedItem = top->data;
    top = top->next;
    delete temp;
    count--;
    return deletedItem;
}
int Stack ::getTop() const
{
    if (!isEmpty())
    {
        return top->data;
    }
    else
    {
        cout << "Stack is empty!" << endl;
        return -1;
    }
}
int Stack ::length() const
{
    return count;
}
