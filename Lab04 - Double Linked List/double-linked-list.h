//add comments to all my programs

struct Node
{
    int data; // Data stored in the node
    Node *next; // Pointer to the next node
    Node *prev; // Pointer to the previous node
};

class DoubleLinkedList
{
private:
    Node *head; // Stores the address of first node from the list
    Node *tail; // Stores the address of last node from the list
    int count; // Number of nodes in the list

public:
    DoubleLinkedList(); // Constructor to initialize the list
    ~DoubleLinkedList(); // Destructor to clean up the list
    bool isEmpty() const; // Check if the list is empty
    void add(int value, int position); // Add a node with given value at the specified position
    void traverse() const; // Traverse and print the list in both forward and backward directions
    void remove(int value); // Remove the node with the given value
    int length() const; // Return the number of nodes in the list
    bool search(int value) const; // Search for a node with the given value
    void destroy(); // Deletes all nodes from the list
};

// Define the member functions here
DoubleLinkedList ::DoubleLinkedList()
{
    head = tail = NULL; // Initialize head and tail to NULL
    count = 0; // Initialize count to 0
}

bool DoubleLinkedList ::isEmpty() const
{
    return head == NULL; // Return true if head is NULL, indicating the list is empty
}

void DoubleLinkedList ::traverse() const
{
    if (!isEmpty())
    {
        Node *temp;
        cout << "Items in forward direction are:";
        temp = head;
        while (temp != NULL)
        {
            cout << temp->data << " "; // Print data in forward direction
            temp = temp->next;
        }
        cout << endl;
        cout << "Items in backward direction are:";
        temp = tail;
        while (temp)
        {
            cout << temp->data << " "; // Print data in backward direction
            temp = temp->prev;
        }
    }
    else
    {
        cout << "List is empty!" << endl; // Print if the list is empty
    }
    cout << endl;
}

void DoubleLinkedList ::destroy()
{
    Node *temp;
    while (head != NULL)
    {
        temp = head;
        head = head->next;
        delete temp; // Delete each node
    }
    tail = NULL; // Set tail to NULL
    count = 0; // Reset count to 0
}

DoubleLinkedList ::~DoubleLinkedList()
{
    destroy(); // Call destroy to clean up the list
}

void DoubleLinkedList ::add(int value, int position)
{
    if (position < 0)
    {
        cout << "Invalid position" << endl; // Check for invalid position
        return;
    }

    Node *NewNode = new Node;
    NewNode->data = value;

    if (position == 0)
    {
        NewNode->next = head;
        NewNode->prev = NULL;
        if (head) // head!=NULL
            head->prev = NewNode;
        else // If list is empty
            tail = NewNode;
        head = NewNode;
    }
    else
    {
        // Locate the node after which the newNode to be inserted
        Node *curNode = head;
        int countNode = 1;
        while (curNode != NULL && countNode < position)
        {
            curNode = curNode->next;
            countNode = countNode + 1;
        }
        if (curNode)
        {
            NewNode->prev = curNode;
            NewNode->next = curNode->next;
            if (curNode->next)
                curNode->next->prev = NewNode;
            else
                tail = NewNode;
            curNode->next = NewNode;
        }
        else
        {
            // Lets insert newNode at the end of the list for position greater than the length of the list
            NewNode->next = NULL;
            NewNode->prev = tail;
            tail->next = NewNode;
            tail = NewNode;
        }
    }
    count++; // Increment the count of nodes
}

void DoubleLinkedList ::remove(int data)
{
    if (isEmpty())
    {
        cout << "List is empty!" << endl; // Check if the list is empty
        return;
    }

    Node *deleteNode = head;
    while (deleteNode && deleteNode->data != data)
        deleteNode = deleteNode->next; // Locate the node to be deleted
    if (deleteNode != NULL)
    {
        if (deleteNode == head)
        {
            head = head->next;
            if (head)
            {
                // If the list has more than one node
                head->prev = NULL;
            }
            else
            { // If list has only one node
                tail = NULL;
            }
        }
        else
        {
            deleteNode->prev->next = deleteNode->next;
            if (deleteNode->next)
            {
                // Delete middle node
                deleteNode->next->prev = deleteNode->prev;
            }
            else
            {
                // Delete last node
                tail = deleteNode->prev;
            }
        }
        cout << "Element " << data << " is deleted successfully!" << endl;
        delete deleteNode; // Delete the node
        count--; // Decrement the count of nodes
    }
    else
    {
        cout << "Element " << data << " is not found!" << endl; // Print if the element is not found
    }
}

int DoubleLinkedList ::length() const
{
    return count; // Return the count of nodes
}