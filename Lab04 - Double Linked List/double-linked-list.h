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
    head = NULL;
    tail = NULL;
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
    }else{
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

    Node *insNode = new Node;
    insNode->data = value;

    if (position == 0)
    {
        insNode->next = head;
        insNode->prev = NULL;
        if (head) // head!=NULL
            head->prev = insNode;
        else // If list is empty
            tail = insNode;
        head = insNode;
        count++;
    }
    else
    {
        // Locate the node after which the newNode to be inserted
        Node *temp = head;
        int i = 1;
        while (temp != NULL && i < position)
        {
            temp = temp->next;
            i++;
        }
        if (temp)
        {
            insNode->prev = temp;
            insNode->next = temp->next;
            if (temp->next)
                temp->next->prev = insNode;
            else
                tail = insNode;
            temp->next = insNode;
        }
        else
        {
            // cout<<"Invalid position"<<endl;
            // delete insNode;

            insNode->next = NULL;
            insNode->prev = tail;
            tail->next = insNode;
            tail = insNode;
        }
        count++;
    }
}

void DoubleLinkedList :: remove(int value){

    if (isEmpty())
    {
        cout << "List is empty!" << endl;
        return;
    }
    Node *delNode = head;
    if(head->data == value)
    {
        if(head->next){ //If the list has more than node
            head = head->next;
            head->prev = NULL;
        }
        else{ //If list has only one node
            head = NULL;
            tail = NULL;
        }
        cout<<"Value "<<value<<" deleted successfully!"<<endl;
        delete delNode;
        count--;
    } else{
        Node *temp = head;
        while(temp && temp->data != value)
            temp = temp->next;
        if(temp != NULL){
            if(temp->next){
                //Delete middle node
                temp->prev->next = temp->next;
                temp->next->prev = temp->prev;
            }
            else{
                //Delete last node
                temp->prev->next = NULL;
                tail = temp->prev;
            }
            cout<<"Value "<<value<<" deleted successfully!"<<endl;
            delete temp;
            count--;
        }
        else{
            cout<<"Value "<<value<<" not found!"<<endl;
        }
    }
}

int DoubleLinkedList ::length() const
{
    return count;
}