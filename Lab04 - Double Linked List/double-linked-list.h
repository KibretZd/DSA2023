struct Node
{
    int data;
    Node *next;
    Node *prev;
};

class DoubleLinkedList
{
private:
    Node *head; // Stores the address of first node from the list
    Node *tail; // Stores the address of last node from the list
    int count;

public:
    DoubleLinkedList();
    ~DoubleLinkedList();
    bool isEmpty() const;
    void add(int value, int position);
    void traverse() const;
    void remove(int value);
    int length() const; // return number of nodes in the list
    bool search(int value) const;
    void destroy(); // Deletes all nodes from the list
};

// Define the member functions here
DoubleLinkedList ::DoubleLinkedList()
{
    head = tail = NULL;
    count = 0;
}

bool DoubleLinkedList ::isEmpty() const
{
    return head == NULL;
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
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
        cout << "Items in backward direction are:";
        temp = tail;
        while (temp)
        {
            cout << temp->data << " ";
            temp = temp->prev;
        }
    }
    else
    {
        cout << "List is empty!" << endl;
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
        delete temp;
    }
    tail = NULL;
    count = 0;
}

DoubleLinkedList ::~DoubleLinkedList()
{
    destroy();
}

void DoubleLinkedList ::add(int value, int position)
{
    if (position < 0)
    {
        cout << "Invalid position" << endl;
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
            // cout<<"Invalid position"<<endl;
            // Lets insert newNode at the end of the list for position greater than the length of the list
            NewNode->next = NULL;
            NewNode->prev = tail;
            tail->next = NewNode;
            tail = NewNode;
        }
    }
    count++;
}

void DoubleLinkedList ::remove(int data)
{

    if (isEmpty())
    {
        cout << "List is empty!" << endl;
        return;
    }

    Node *deleteNode = head;
    while (deleteNode && deleteNode->data != data)
        deleteNode = deleteNode->next;
    if (deleteNode != NULL)
    {
        if (deleteNode == head)
        {
            head = head->next;
            if (head)
            {
                // If the list has more than node
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
        delete deleteNode;
        count--;
    }
    else
    {
        cout << "Element " << data << " is not found!" << endl;
    }
}

int DoubleLinkedList ::length() const
{
    return count;
}