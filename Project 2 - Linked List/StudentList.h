// Implementation of student list using single linked list
#include "student.h"

struct Node
{
    Student student;
    Node *link;
};

class StudentList
{
private:
    Node *head; // Stores the address of first node from the list
    int count;
    void sortByFirstName();
    void sortByLastName();

public:
    StudentList();
    ~StudentList();
    bool isEmpty() const;
    void addStudent(Student newStudent, int position);
    void traverse() const;
    void removeStudentByIdNumber(int value);
    int length() const; // return number of nodes in the list
    int searchByIdNumber(int idNumber) const;
    void destroyList(); // Deletes all nodes from the list

    void searchByFirstName(string firstName) const;
    void searchByLastName(string lastName) const;
    void searchByDepartment(string department) const;
    void femaleStudents() const;
    void maleStudents() const;

    void updateStudent(int idNumber, Student student);
    void sortByName();
    void sortByDepartment(); // Sort students by department
    void sortByAge();        // Sort students by age
    void sortByIdNumber();   // Sort students by id
};

// Define the member functions here
StudentList ::StudentList()
{
    head = NULL;
    count = 0;
}

bool StudentList ::isEmpty() const
{
    return head == NULL;
}

void StudentList ::traverse() const
{
    if (!isEmpty())
    {
        Node *temp;
        cout << "Students list are as follows. " << endl;
        temp = head;
        int counter = 1;
        while (temp != NULL)
        {
            cout << counter++ << ". ";
            temp->student.printStudent();
            temp = temp->link;
        }
        cout << endl;
    }
    else
    {
        cout << "Student list  is empty!" << endl;
    }
    cout << endl;
}

void StudentList ::destroyList()
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

StudentList ::~StudentList()
{
    destroyList();
}

void StudentList ::addStudent(Student newStudent, int position)
{
    if (position < 0)
    {
        cout << "Invalid position" << endl;
        return;
    }

    Node *insNode = new Node;
    insNode->student = newStudent;

    if (position == 0)
    {
        insNode->link = head;
        head = insNode;
        count++;
    }
    else
    {
        // Locate the node after which the newNode to be inserted
        Node *temp = head;
        int counter = 1;
        while (temp != NULL && counter < position)
        {
            temp = temp->link;
            counter++;
        }
        if (temp)
        {
            insNode->link = temp->link;
            temp->link = insNode;
        }
        else
        {
            cout << "Invalid position" << endl;
            delete insNode;
        }
        count++;
    }
}

void StudentList ::removeStudentByIdNumber(int idNumber)
{

    if (isEmpty())
    {
        cout << "List is empty!" << endl;
        return;
    }

    Node *temp = head;
    Node *prevNode = NULL;
    while (temp && temp->student.getIdNumber() != idNumber)
    {
        prevNode = temp;
        temp = temp->link;
    }
    if (temp != NULL)
    {
        if (prevNode)
            prevNode->link = temp->link;
        else
            head = temp->link;
        cout << "Student with id " << idNumber << " deleted successfully!" << endl;
        delete temp;
        count--;
    }
    else
    {
        cout << "No student with id of " << idNumber << " is not found!" << endl;
    }
}

int StudentList ::length() const
{
    return count;
}

int StudentList ::searchByIdNumber(int idNumber) const
{
    if (!isEmpty())
    {
        Node *temp = head;
        int counter = 1;
        while (temp != NULL)
        {
            if (temp->student.getIdNumber() == idNumber)
            {
                temp->student.printStudent();
                return counter;
            }
            temp = temp->link;
            counter++;
        }
    }
    return -1;
}

void StudentList ::searchByFirstName(string firstName) const
{
    // search all student by their firstname that matches the given string
    bool ifFound = false;
    Node *temp = head;
    int index = 0;
    while (temp)
    {
        if (temp->student.getFirstName() == firstName)
        {
            cout << (++index) << ". ";
            temp->student.printStudent();
            ifFound = true;
        }
        temp = temp->link;
    }
    if (!ifFound)
    {
        cout << "No student found with first name: " << firstName << endl;
    }
}
void StudentList ::searchByLastName(string lastName) const
{
    // Write your code here
}
void StudentList ::searchByDepartment(string department) const
{
    //Write your code here
}
void StudentList ::femaleStudents() const
{

    // Write your code here to print all female students only
    int countFemales = 0;
    Node *temp = head;
    while (temp)
    {
        if (temp->student.getSex() == 'F')
        {
            cout << (++countFemales) << ". ";
            temp->student.printStudent();
        }
        temp = temp->link;
    }
    if (countFemales != 0)
    {
        cout << "Found " << countFemales << " females from a total of " << count << " students." << endl;
    }
}
void StudentList ::maleStudents() const
{
    // Write your code here to print all male students only
}

void StudentList ::updateStudent(int idNumber, Student student)
{
    // Write your code here to update the student with given id number
    Node *temp = head;
    while (temp)
    {
        if (temp->student.getIdNumber() == idNumber)
        {
            temp->student = student;
            cout << "Student with id " << idNumber << " updated successfully!" << endl;
            return;
        }
        temp = temp->link;
    }
    cout << "No student with id of " << idNumber << " is not found!" << endl;
}

void StudentList ::sortByFirstName()
{
    // use selection sort algorithm
    Node *outer, *inner, *minNode;
    for (outer = head; outer->link; outer = outer->link)
    {
        minNode = outer;
        for (inner = outer->link; inner; inner = inner->link)
        {
            if (inner->student.getFirstName() < minNode->student.getFirstName())
            {
                minNode = inner;
            }
        }
        // swap outer->student and minNode->student
        Student tempStudent = outer->student;
        outer->student = minNode->student;
        minNode->student = tempStudent;
    }
}
void StudentList ::sortByLastName()
{
    // use selection sort algorithm
    Node *outer, *inner, *minNode;
    for (outer = head; outer->link; outer = outer->link)
    {
        minNode = outer;
        for (inner = outer->link; inner; inner = inner->link)
        {
            if (inner->student.getLastName() < minNode->student.getLastName())
            {
                minNode = inner;
            }
        }
        // swap outer->student and minNode->student
        Student tempStudent = outer->student;
        outer->student = minNode->student;
        minNode->student = tempStudent;
    }
}

void StudentList ::sortByName()
{
    sortByLastName();
    sortByFirstName();
}
void StudentList ::sortByDepartment()
{
    //Write your code here
}
void StudentList ::sortByAge()
{
    //Write your code here
}
void StudentList ::sortByIdNumber()
{
    //Write your code here
}