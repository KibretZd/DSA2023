// Demonstration of a single linked list with each node storing a single integer

// Definition of a node
struct Node
{
    int data; // Data stored in the node
    Node *link; // Pointer to the next node in the list
};

// Class implementation of single linked list
class List
{
private:
    Node *head; // Pointer to the first node in the list
    int count; // Number of nodes in the list

public:
    List();               // Constructor to initialize data members
    ~List();              // Destructor to delete all the nodes created dynamically
    bool isEmpty() const; // Checks whether the list is empty or not
    void insert(int data, int position); // Inserts a node with given data at the specified position
    void traverse() const; // Traverses and prints the list
    void remove(int data); // Removes the node with the given data
    void destroy(); // Deletes all nodes from the list
    bool search(int data); // Searches for a node with the given data
    int length(); // Returns the number of nodes in the list
};

// Constructor to initialize data members
List::List()
{
    head = NULL; // Initialize head to NULL
    count = 0; // Initialize count to 0
}

// Destructor to delete all the nodes created dynamically
List::~List()
{
    destroy(); // Call destroy to clean up the list
}

// Checks whether the list is empty or not
bool List::isEmpty() const
{
    return head == NULL; // Return true if head is NULL, indicating the list is empty
}

// Deletes all nodes from the list
void List::destroy()
{
    Node *temp;
    while (head != NULL)
    {
        temp = head;
        head = head->link;
        delete temp; // Delete each node
    }
    count = 0; // Reset count to 0
}

// Inserts a node with given data at the specified position
void List ::insert(int data, int position)
{
    Node *newNode = new Node; // Create a new node
    newNode->data = data; // Set the data
    newNode->link = NULL; // Initialize the link to NULL

    if (position == 0)
    {
        newNode->link = head; // Link the new node to the current head
        head = newNode; // Update head to the new node
        cout << data << " is inserted successfully." << endl;
        count++; // Increment the count of nodes
    }
    else
    {
        int countNode = 1;
        Node *curNode = head;
        while (curNode && countNode < position)
        {
            curNode = curNode->link; // Traverse to the position
            countNode++;
        }
        if (curNode)
        {
            newNode->link = curNode->link; // Link the new node to the next node
            curNode->link = newNode; // Link the current node to the new node
            cout << data << " is inserted successfully." << endl;
            count++; // Increment the count of nodes
        }
        else
        {
            cout << data << " is NOT inserted! Position " << position << " is too large!" << endl;
            delete newNode; // Delete the new node if position is invalid
        }
    }
}

// Traverses and prints the list
void List ::traverse() const
{
    Node *curNode = head;
    cout << endl;
    while (curNode)
    {
        cout << curNode->data << " "; // Print the data of each node
        curNode = curNode->link; // Move to the next node
    }
    cout << endl;
}

// Removes the node with the given data
void List ::remove(int data)
{
    if (!isEmpty())
    {
        // Traverse to find the node to be deleted
        Node *curNode = head;
        Node *prev = NULL;

        while (curNode && curNode->data != data)
        {
            prev = curNode;
            curNode = curNode->link; 
        }
        if (curNode)
        {
            if (head == curNode)
            {
                head = head->link; // Update head if the node to be deleted is the first node
            }
            else
            {
                prev->link = curNode->link; // Link the previous node to the next node
            }
            cout << curNode->data << " is deleted." << endl;
            delete curNode; // Delete the node
            count--; // Decrement the count of nodes
        }
        else
        {
            cout << data << " is not found!" << endl; // Print if the data is not found
        }
    }
    else
    {
        cout << "List is empty!" << endl; // Print if the list is empty
    }
}

// Searches for a node with the given data
bool List ::search(int data)
{
    Node *curNode = head;
    while (curNode)
    {
        if (curNode->data == data)
            return true; // Return true if data is found
        curNode = curNode->link; // Move to the next node
    }
    return false; // Return false if data is not found
}

// Returns the number of nodes in the list
int List ::length()
{
    return count; // Return the count of nodes
}