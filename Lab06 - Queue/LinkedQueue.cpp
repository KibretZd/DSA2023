
// Array implementation of circular array
#include <iostream>
using namespace std;

struct QNode
{
    int data;
    QNode *link;
};

class LinkedQueue
{
    QNode *front; // To store the address of front node
    QNode *rear;  // To store the address of last node
    int size;     // To count the number of elements in the queue
public:
    LinkedQueue()
    {
        front = rear = NULL;
        size = 0;
    }
    int isEmpty() const;
    int length() const; // Returns the number of elements in the queue
    void enqueue(int data);
    void dequeue();
    void getFront() const; // Return the front element
};

int LinkedQueue ::isEmpty() const
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

int LinkedQueue::length() const
{
    return size;
} // Returns the number of elements in the queue
void LinkedQueue::enqueue(int data)
{
    QNode *insNode = new QNode;
    insNode->data = data;
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

    size++;
    cout << data << " is enqueued Successfully" << endl;
}
void LinkedQueue::dequeue()
{
    if (!isEmpty())
    {
        QNode *temp = front;

        front = front->link;
        if (front == NULL)
        {
            rear = NULL;
        }
        size--;
        cout << temp->data << " is dequeued Successfully" << endl;
        delete temp;
    }
    else
        cout << "Queue is empty!" << endl;
    // return -1;
}
void LinkedQueue::getFront() const
{
    if (!isEmpty())
    {

        cout << "The front element is: " << front->data << endl;
    }
    else
    {
        cout << "The queue is empty!" << endl;
    }
}

int main()
{

    LinkedQueue q;
    q.enqueue(30); // 30 is enqueued successfully
    q.enqueue(40); // 40 is enqueued successfully
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(50);
    q.enqueue(75); // 75 is enqueued successfully
    cout << "The size of the queue is " << q.length() << endl;
    q.getFront(); // 30
    q.getFront(); // 30
    q.dequeue();  // 30
    q.getFront(); // 40
    q.dequeue();  // 40
    cout << "The size of the queue is " << q.length() << endl;
    q.dequeue(); // 10
    q.dequeue(); // 20
    q.dequeue(); // 50
    q.dequeue(); // 75 is dequeued successfully
    q.dequeue(); // queue is empty()
    cout << "The size of the queue is " << q.length() << endl;

    return 0;
}