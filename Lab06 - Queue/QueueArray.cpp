
// Array implementation of circular queue
#include <iostream>
using namespace std;

#define MAX_SIZE 5
class QueueArray
{
    int queue[MAX_SIZE];
    int front; // To store the index of front element
    int rear;  // To store the index of rear element
    int size;  // To count the number of elements in the queue
public:
    QueueArray()
    {
        front = -1;
        rear = -1;
        size = 0;
    }
    int isEmpty() const;
    int isFull() const;
    int length() const; // Returns the number of elements in the queue
    void enqueue(int data);
    void dequeue();
    void getFront() const; // Return the front element
};

int QueueArray ::isEmpty() const
{
    return (size == 0);
}

int QueueArray::isFull() const
{
    return (size == MAX_SIZE);
}

// Returns the number of elements in the queue
int QueueArray::length() const
{
    return size;
}
void QueueArray::enqueue(int data)
{
    if (!isFull())
    {
        rear = (rear + 1) % MAX_SIZE;
        queue[rear] = data;
        size++;
        cout << data << " Enqueued Successfully" << endl;
    }
    else
    {
        throw overflow_error("Queue is full!");
    }
}
int QueueArray::dequeue()
{
    if (!isEmpty())
    {
        front = (front + 1) % MAX_SIZE;
        size--;
        return queue[front];
    }
    else
        throw underflow_error("Queue is empty!");
}

int QueueArray::getFront() const
{
    if (!isEmpty())
    {
        int temp = (front + 1) % MAX_SIZE;
        return queue[temp];
    }
    else
    {
        throw underflow_error("Queue is empty!");
    }
}

int main()
{

    QueueArray q;
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(50);
    q.enqueue(75);

    q.getFront(); // 30
    q.getFront(); // 30
    q.dequeue();  // 30
    q.getFront(); // 40
    q.dequeue();  // 40
    q.dequeue();  // 10
    q.dequeue();  // 20
    q.dequeue();  // 50
    q.dequeue();  // queue is empty()

    return 0;
}