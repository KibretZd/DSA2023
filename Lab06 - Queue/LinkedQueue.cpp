
// Queue implementation using linked list
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
    QNode *rear;  // To store the address of last node from the rear end
    int size;     // To count the number of elements in the queue
public:
    LinkedQueue()
    {
        front = rear = NULL;
        size = 0;
    }
    int isEmpty() const;    // Checks whether the queue is empty or not
    int length() const;     // Returns the number of elements in the queue
    void enqueue(int data); // Add an elelment into the queue
    int dequeue();          // Deletes the front element from the queue
    int getFront() const;   // Return the front element
};

// Checks whether the queue is empty or not
int LinkedQueue ::isEmpty() const
{
    return (front == NULL);
}

// Returns the number of elements in the queue
int LinkedQueue::length() const
{
    return size;
}

// Enqueue : Adds new item in to the queue
void LinkedQueue::enqueue(int data)
{
    QNode *insNode = new QNode;
    insNode->data = data;
    insNode->link = NULL;

    if (isEmpty())
        front = insNode;
    else
        rear->link = insNode;

    rear = insNode;
    size++;
    cout << data << " is enqueued Successfully." << endl;
}

int LinkedQueue::dequeue()
{
    if (!isEmpty())
    {
        QNode *temp = front;
        int data = front->data;
        front = front->link;
        if (front == NULL)
        {
            rear = NULL;
        }
        size--;
        cout << temp->data << " is dequeued Successfully." << endl;
        delete temp;
        return data;
    }
    else
        throw underflow_error("Queue is empty!");
}

int LinkedQueue::getFront() const
{
    if (isEmpty())
    {
        throw underflow_error("The queue is empty!");
    }
    else
    {
        return front->data;
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