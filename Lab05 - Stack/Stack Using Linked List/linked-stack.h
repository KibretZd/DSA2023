// Linked list implementation of stack data structure
#include <stdexcept>

struct Node
{
    int data;
    Node *link;
};

class LinkedStack
{
private:
    Node *top; // Pointer to the top of the stack
    int count; // Number of items in the stack

public:
    LinkedStack();         // Constructor
    ~LinkedStack();        // Destructor
    int isEmpty() const;   // Check if the stack is empty
    void push(int item);   // Push an item onto the stack
    int pop();             // Pop an item from the stack
    int getTop() const;    // Get the top item from the stack
    int length() const;    // Returns the number of items/nodes in stack
    void destroy();        // Deletes all nodes from the stack
    void traverse() const; // Traverse and print the stack
};

LinkedStack ::LinkedStack()
{
    top = NULL; // Initialize top to NULL
    count = 0;  // Initialize count to 0
}
LinkedStack ::~LinkedStack()
{
    destroy(); // Call destroy to clean up the stack
}

void LinkedStack ::destroy()
{
    Node *temp; // Temporary pointer to node
    while (top != NULL)
    {
        temp = top;      // Store the address of top in temp
        top = top->link; // Move top to the next node
        delete temp;     // Delete the node
    }
}

int LinkedStack ::isEmpty() const
{
    return (top == NULL); // Return true if top is NULL, indicating the stack is empty
}
void LinkedStack ::push(int item)
{
    Node *temp = new Node; // Create a new node
    temp->data = item;     // Assign the item to the data field of the node
    temp->link = top;      // Link the new node to the top node
    top = temp;            // Move top to the new node
    count += 1;            // Increment the count
}
int LinkedStack ::pop()
{
    if (isEmpty())              // Check if the stack is empty
    {
        throw underflow_error("Stack underflow!");  //Throw an exception if the stack is empty
    }
    Node *temp = top;               // Store the address of top in temp
    int deletedItem = top->data;    // Store the data of top in deletedItem
    top = top->link;                // Move top to the next node
    delete temp;                    // Delete the node
    count--;                        // Decrement the count
    return deletedItem;             // Return the deleted item
}
int LinkedStack ::getTop() const
{
    if (!isEmpty())
    {
        return top->data;       // Return the data of the top node
    }
    else
    {
        throw underflow_error("Stack is empty!"); // Throw an exception if the stack is empty
    }
}
int LinkedStack ::length() const
{
    return count;       // Return the count
}

void LinkedStack ::traverse() const
{
    Node *temp = top;                   // Create a temporary pointer to node and initialize it with top
    while (temp != NULL)                // Traverse the stack
    {
        cout << temp->data << " ";      // Print the data of the node
        temp = temp->link;              // Move to the next node
    }
    cout << endl;                   // Print a new line
}