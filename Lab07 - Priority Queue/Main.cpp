
// Array implementation of circular array
#include <iostream>
using namespace std;
#include "person.h"
#include "Queue.h"
#include "priorityQueue.h"

Person readPersonInfo(){

    string firstName,lastName,gender;
    // int age;
    cout<<"Enter the first name of the person: ";
    cin>>firstName;
    cout<<"Enter the last name of the person: ";
    cin>>lastName;
    cout<<"Enter the gender of the person: ";
    cin>>gender;
    
    Person person(firstName,lastName,gender);
    return person;
}
int main()
{

    PriorityQueue pq;
    Person person;
    person = readPersonInfo();
    pq.enqueue(person);

    person = readPersonInfo();
    pq.enqueue(person);

    
    person = readPersonInfo();
    pq.enqueue(person);

    person = pq.dequeue();
    cout<<"The dequeued person is: "<<person.getFirstName()<<" "<<person.getLastName()<<endl;

    cout<<"Total person in the queue is "<<pq.length()<<endl;
    person = pq.getFront();
    cout<<"The front person is: "<<person.getFirstName()<<" "<<person.getLastName()<<endl;
    return 0;
}