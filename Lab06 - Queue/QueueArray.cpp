
// Array implementation of circular array
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
    if (size == 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int QueueArray::isFull() const
{
    if (size == MAX_SIZE)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int QueueArray::length() const
{
    return size;
} // Returns the number of elements in the queue
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
        cout << "Queue is full!" << endl;
    }
}
void QueueArray::dequeue()
{
    if (!isEmpty())
    {
        front = (front + 1) % MAX_SIZE;
        size--;
        // return queue[front];
        cout << queue[front] << " Dequeued Successfully" << endl;
    }
    else
        cout << "Queue is empty!" << endl;
    // return -1;
}
void QueueArray::getFront() const
{
    if (!isEmpty())
    {
        int temp = (front + 1) % MAX_SIZE;
        // return queue[temp];
        cout << "The front element is: " << queue[temp] << endl;
    }
    else
    {
        cout << "The queue is empty!" << endl;
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