

struct QNode
{
    Person person;
    QNode *link;
};

class Queue
{
    QNode *front; // To store the address of front node
    QNode *rear;  // To store the address of last node
    int size;     // To count the number of elements in the queue
public:
    Queue()
    {
        front = rear = NULL;
        size = 0;
    }
    int isEmpty() const;
    int length() const; // Returns the number of elements in the queue
    void enqueue(Person person);
    Person dequeue();
    Person getFront() const; // Return the front element
};

int Queue ::isEmpty() const
{
    if (size == 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int Queue::length() const
{
    return size;
} // Returns the number of elements in the queue
void Queue::enqueue(Person person)
{
    QNode *insNode = new QNode;
    insNode->person = person;
    insNode->link = NULL;

    if (isEmpty())
    {
        front = rear = insNode;
    }
    else
    {
        rear->link = insNode;
        rear = insNode;
    }
    cout << "Enqueued Successfully" << endl;
    size++;
}
Person Queue::dequeue()
{
    if (!isEmpty())
    {
        QNode *temp = front;
        Person removedPerson = front->person;
        front = front->link;
        if (front == NULL)
        {
            rear = NULL;
        }
        size--;

        delete temp;
        return removedPerson;
    }
    else
    {
        cout << "Queue is empty!" << endl;
        return Person();
    }
    // return -1;
}
Person Queue::getFront() const
{
    if (!isEmpty())
    {
        return front->person;
    }
    else
    {
        cout << "The queue is empty!" << endl;
        return Person();
    }
}
