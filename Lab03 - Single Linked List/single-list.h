// Demonstration a single linked list with each node storing a single integer

// Definition of a node
struct Node
{
    int data;
    Node *link;
};

// Class implementation of single linked list
class List
{
private:
    Node *head;
    int count;

public:
    List();               // Constructor to initialize data members
    ~List();              // Destructor to delete all the node created dynamically
    bool isEmpty() const; // Checks whether the list is empty or not
    void insert(int data, int position);
    void traverse() const;
    void remove(int data);
    void destroy();
    bool search(int data);
    int length();
};

List::List()
{
    head = NULL;
    count = 0;
}

List::~List()
{
    destroy();
}

bool List::isEmpty() const
{
    return head == NULL;
}

void List::destroy()
{
    Node *temp;
    while (head != NULL)
    {
        temp = head;
        head = head->link;
        delete temp;
    }
    count = 0;
}

void List ::insert(int data, int position)
{
    Node *newNode = new Node;
    newNode->data = data;
    newNode->link = NULL;

    if (position == 0)
    {
        newNode->link = head;
        head = newNode;
        cout << data << " is inserted successfully." << endl;
        count++;
    }
    else
    {
        int countNode = 1;
        Node *curNode = head;
        while (curNode && countNode < position)
        {
            curNode = curNode->link;
            countNode++;
        }
        if (curNode)
        {
            newNode->link = curNode->link;
            curNode->link = newNode;
            cout << data << " is inserted successfully." << endl;
            count++;
        }
        else
        {
            cout << data << " is NOT inserted! Position " << position << " is too large!" << endl;
            delete newNode;
        }
    }
}

void List ::traverse() const
{
    Node *curNode = head;
    cout << endl;
    while (curNode)
    {
        cout << curNode->data << " ";
        curNode = curNode->link;
    }
    cout << endl;
}

void List ::remove(int data)
{

    if (!isEmpty())
    {
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
                head = head->link;
            }
            else
            {
                prev->link = curNode->link;
            }
            cout << curNode->data << " is deleted." << endl;
            delete curNode;
            count--;
        }
        else
        {
            cout << data << " is not found!" << endl;
        }
    }
    else
    {
        cout << "List is empty!" << endl;
    }
}

bool List ::search(int data)
{
    Node *curNode = head;
    while (curNode)
    {
        if (curNode->data == data)
            return true;
        curNode = curNode->link;
    }
    return false;
}

int List ::length()
{
    return count;
}
