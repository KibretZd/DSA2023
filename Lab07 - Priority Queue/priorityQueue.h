class PriorityQueue
{
    Queue malesQueue;
    Queue femalesQueue;
    int size;

public:
    PriorityQueue(){
        malesQueue = Queue();
        femalesQueue = Queue();
        size = 0;
    }
    void enqueue(Person person);
    Person dequeue();
    int length();
    Person getFront() const;
};

void PriorityQueue::enqueue(Person person)
{
    if (person.getGender() == "male")
    {
        malesQueue.enqueue(person);
    }
    else if (person.getGender() == "female")
    {
        femalesQueue.enqueue(person);
    }
    size++;
}
Person PriorityQueue::dequeue()
{
    //Female have high priority than males
    if(femalesQueue.isEmpty() && malesQueue.isEmpty())
    {
        cout<<"Queue is empty!"<<endl;
        return Person();
    }
    // Females have high priority
    else if (femalesQueue.isEmpty())
        return malesQueue.dequeue();
    else
        return femalesQueue.dequeue();
    size--;
}
int PriorityQueue::length(){
    return size;
}
Person PriorityQueue::getFront() const{
    if(femalesQueue.isEmpty() && malesQueue.isEmpty())
    {
        cout<<"Queue is empty!"<<endl;
        return Person();
    }
    // Females have high priority
    else if (femalesQueue.isEmpty())
        return malesQueue.getFront();
    else
        return femalesQueue.getFront();
}