#include <iostream>
#include <bits/stdc++.h>
#include "student.h"

using namespace std;
class StudentList
{
private:
    Student list[100];      // set maximum number of students to register 100 students
    int count;              // used to count the number of students registered in the list
    void sortByFirstName(); // Sort students by firstName
    void sortByLastName();  // Sort students by lastName

public:
    StudentList()
    {
        count = 0;
    }
    bool isEmpty() const;
    bool isFull() const;
    void addStudent(Student student);
    void removeStudentByIdNumber(int id);
    void printStudents() const;
    int getCount() const;
    int searchByIdNumber(int id) const;
    void searchByFirstName(string firstName)const;
    void searchByLastName(string lastName)const;
    void searchByDepartment(string department)const;
    void femaleStudents() const;
    void maleStudents() const;

    void updateStudent(int index, Student student);
    void sortByName();
    void sortByDepartment(); // Sort students by department
    void sortByAge();        // Sort students by age
    void sortByIdNumber();   // Sort students by id
};

// Check if the student list is empty
bool StudentList::isEmpty() const
{
    return count == 0;
}

// check if the student list is full
bool StudentList::isFull() const
{
    return count == 100;
}

// add a new student to the list
void StudentList::addStudent(Student student)
{
    if (!isFull()) // Add a student if the array is not full
    {
        list[count] = student;
        count++;
        cout << "Student added successfully!" << endl;
    }
    else // The array is full and insertion is faileds
    {
        cout << "The list is full. Student cannot be added!" << endl;
    }
}

// The following function is to remove/delete a student from the list
void StudentList::removeStudentByIdNumber(int id)
{
    if (!isEmpty())
    {
        bool isFound = false;
        for (int i = 0; i < count; i++)
        {
            if (list[i].getIdNumber() == id)
            {
                for (int j = i; j < count - 1; j++)
                {
                    list[j] = list[j + 1];
                }
                count--;
                cout << "Student is removed successfully!" << endl;
                isFound = true; //Set that the student is found true.
                break;
            }
        }
        if(!isFound)
            cout << "Student is not found!" << endl;
    }
    else
    {
        cout << "The list is empty!" << endl;
    }
}

// To display all the students registered
void StudentList::printStudents() const
{
    cout << endl;
    if (!isEmpty())
    {
        for (int i = 0; i < count; i++)
        {
            cout<<(i+1)<<". ";
            list[i].printStudent();
        }
    }
    else
    {
        cout << "The list is empty!" << endl;
    }
    cout << endl;
}

// To get the number of students currently registered.
int StudentList::getCount() const
{
    // return the number of students added to the list;
    return count;
}

// This following function will search for a student by id number
int StudentList::searchByIdNumber(int id) const
{
    // Here I have used linear search implementation
    for (int i = 0; i < count; i++)
    {
        if (list[i].getIdNumber() == id)
        {
            return i; // i is the index where the student is found in the list
        }
    }

    return -1; // Student is not found, return -1
}

// This following function will print all students whose first name is given
void StudentList::searchByFirstName(string firstName)const
{
    // search all student by their firstname that matches the given firstname
    bool ifFound = false;
    for (int i = 0; i < count; i++)
    {
        if (list[i].getFirstName() == firstName)
        {
            list[i].printStudent(); // print the student
            ifFound = true;
        }
    }
    if (!ifFound)
    {
        cout << "No student found with first name: " << firstName << endl;
    }
}

// This following function will print all students whose last name is given
void StudentList::searchByLastName(string lastName)const
{

    // Write your code here to search all student by their lastname that matches the given lastname
}
void StudentList::searchByDepartment(string department)const
{

    // Write your code here to search all student by their department that matches the given department
}

// The following function will print all female students
void StudentList::femaleStudents() const
{

    // Write your code here to print all female students only
    int countFemales = 0;
    for (int i = 0; i < count; i++)
    {
        if (list[i].getSex() == 'F')
        {
            cout << (++countFemales) << ". ";
            list[i].printStudent();
        }
    }
    if (countFemales != 0)
    {
        cout << "Found "<<countFemales << " females from a total of " 
            << count <<" students!"<< endl;
    }
    else
    {
        cout << "No female students found!" << endl;
    }
}

// The following function will print all female students
void StudentList::maleStudents() const
{
    // Write your code here to print all male students only
    // hint: see the code above for females and modify it to print all male students

    // your code must also print the number of male students as like the above
}

// Update a student information using index
void StudentList::updateStudent(int index, Student student)
{
    list[index] = student;
}

// This function is used to convert a sring to uppercase string
string toUppercase(string str)
{
    transform(str.begin(), str.end(), str.begin(), ::toupper);
    return str;
}

void StudentList::sortByFirstName()
{
    // Write your code here to sort students by firstName
    // Here we will use the insertion sort as it is fast algorithm as compared to bubbke and selection sort method
    if (!isEmpty())
    {
        int outer, inner;
        Student temp;
        for (outer = 1; outer < count; outer++)
        {
            temp = list[outer];
            inner = outer - 1;
            while (inner >= 0 && toUppercase(list[inner].getFirstName()) > toUppercase(temp.getFirstName()))
            {
                list[inner + 1] = list[inner];
                inner = inner - 1;
            }
            list[inner + 1] = temp;
        }
    }
    else
    {
        cout << "The list is empty!" << endl;
    }
}

// The following function is to sort students by lastName
void StudentList::sortByLastName()
{
    if (!isEmpty())
    {
        int outer, inner;
        Student temp;
        for (outer = 1; outer < count; outer++)
        {
            temp = list[outer];
            inner = outer - 1;
            while (inner >= 0 && toUppercase(list[inner].getLastName()) > toUppercase(temp.getLastName()))
            {
                list[inner + 1] = list[inner];
                inner = inner - 1;
            }
            list[inner + 1] = temp;
        }
    }
    else
    {
        cout << "The list is empty!" << endl;
    }
}

// The following function is to sort students by department
void StudentList::sortByDepartment()
{
    // write your code here to sort students by their department
}

// The following function is to sort students by age
void StudentList::sortByAge()
{
    // Write your code here to sort students by their age
}

// The following function sorts students by their firstName followed by their last Name
void StudentList::sortByName()
{
    // First call sortByLastName to sort students by their last Name
    sortByLastName();

    // First call sortByFirstName to sort students by their first Name
    sortByFirstName();

}

void StudentList::sortByIdNumber()
{

    // Write your code here to sort students by their id number
}