// Class implementation of single linked list

struct Node
{
    int data;
    Node *link;
};

class List
{
private:
    Node *head, *tail;
    int count;

public:
    List();
    ~List();
    bool isEmpty() const;
    void add(int data, int position);
    void traverse() const;
    void remove(int data);
    void destroy();
    bool search(int data);
    int length();
    void update(int data, int newdata);
};


List::List()
{
    head = tail = NULL;
    count = 0;
}

List::~List()
{
    destroy();
}


bool List::isEmpty() const
{
    return head != NULL;
}


void List::destroy()
{
    Node *curr;
    while (head != NULL)
    {
        curr = head;
        head = head->link;
        delete curr;
    }
    tail = NULL;
    count = 0;
}

void List ::add(int data, int position)
{
    Node *newNode = new Node;
    newNode->data = data;
    newNode->link = NULL;

    if (head == NULL)
    {
        head = tail = newNode;
        count++;
    }
    else
    {
        int count = 1;
        Node *curr = head;
        while (curr && count < position - 1)
        {
            curr = curr->link;
            count++;
        }
        if (curr)
        {
            newNode->link = curr->link;
            curr->link = newNode;
        }
        else
        {
            // position is greater than the number of nodes, insert at the end of the list
            tail->link = newNode;
            tail = newNode;
        }
        count++;
    }
    cout<<"Added: "<<data<<endl;
}

void List ::traverse() const
{
    Node *curr = head;
    cout << endl;
    while (curr)
    {
        cout << curr->data << " ";
        curr = curr->link;
    }
    cout << endl;
}


void List ::remove(int data)
{

    if (!isEmpty())
    {
        Node *curr = head;
        Node *prev = NULL;
        if (curr->data == data)
        {
            head = curr->link;
            cout << "Deleted: " << curr->data << endl;
            delete curr;
            count--;
        }
        else
        {
            while (curr && curr->data != data)
            {
                prev = curr;
                curr = curr->link;
            }
            if (curr)
            {
                prev->link = curr->link;
                cout << "Deleted: " << curr->data << endl;
                delete curr;
                count--;
            }
            else
            {
                cout << "Element not found" << endl;
            }
        }
    }
    else
    {
        cout << "List is empty!" << endl;
    }
}


bool List ::search(int data)
{
    Node *curr = head;
    while (curr)
    {
        if (curr->data == data)
            return true;
        curr = curr->link;
    }
    return false;
}


int List ::length()
{
    return count;
}

/*
 * This code defines a method called update in the List class.
 *It takes two int parameters, data and newdata.
 * It iterates through the linked list until it finds a node with data equal to the given value.
 * If found, it updates the data of that node with the newdata value.
 */
void List ::update(int data, int newdata)
{
    Node *curr = head;
    while (curr)
    {
        if (curr->data == data)
        {
            curr->data = newdata;
            cout<<"Updated: "<<curr->data<<endl;
            break;
        }
        curr = curr->link;
    }
}