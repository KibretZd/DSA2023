#include <iostream>
#include "student.h"

using namespace std;
class StudentList
{
private:
    Student list[100];  //set maximum number of students to register 100 students
    int count; // used to count the number of students registered in the list
    

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
    int searchByIdNumber(int id);
    void searchByFirstName(string firstName);
    void searchByLastName(string lastName);
    void searchByDepartment(string department);
    void femaleStudents() const;
    void maleStudents() const;

    void updateStudent(int index, Student student);
    void sortByFirstName();//Sort students by firstName
    void sortByLastName();//Sort students by lastName
    void sortByDepartment();//Sort students by department
    void sortByAge();//Sort students by age
};


//Check if the student list is empty
bool StudentList::isEmpty() const
{
    return count == 0;
}

//check if the student list is full
bool StudentList::isFull() const
{
    return count == 100;
}


//add a new student to the list
void StudentList::addStudent(Student student)
{
    if (!isFull()) // Add a student if the array is not full
    {
        list[count] = student;
        count++;
    }
}

// The following function is to remove/delete a student from the list
void StudentList::removeStudentByIdNumber(int id)
{
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
            break;
        }
    }

    cout << "\nStudent is not found!" << endl;
}

//To display all the students registered
void StudentList::printStudents() const
{
    for (int i = 0; i < count; i++)
    {
        list[i].printStudent();
    }
}

//To get the number of students currently registered.
int StudentList::getCount() const
{
    // return the number of students added to the list;
    return count;
}

// This following function will search for a student by id number
int StudentList::searchByIdNumber(int id)
{
    //Here I have used linear search implementation
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
void StudentList::searchByFirstName(string firstName)
{
    // search all student by their firstname that matches the given firstname
    for (int i = 0; i < count; i++)
    {
        if (list[i].getFirstName() == firstName)
        {
            list[i].printStudent(); // print the student
        }
    }
}

// This following function will print all students whose last name is given
void StudentList::searchByLastName(string lastName)
{

    // Write your code here to search all student by their lastname that matches the given lastname


}
void StudentList::searchByDepartment(string department)
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
            list[i].printStudent();
            countFemales++;
        }
    }
    if(countFemales == 0)
    {
        cout<<"There are "<<countFemales<<" females students found from"<<count<<endl;
    }
    else{
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

void StudentList::sortByFirstName()
{
    // Write your code here to sort students by firstName
    // Here we will use the insertion sort as it is fast algorithm as compared to bubbke and selection sort method
    int outer, inner;
    Student temp;
    for (outer = 1; outer < count; outer++)
    {
        temp = list[outer];
        inner = outer - 1;
        while (inner >= 0 && list[inner].getFirstName() > temp.getFirstName())
        {
            list[inner + 1] = list[inner];
            inner = inner - 1;
        }
        list[inner + 1] = temp;
    }
}

//The following function is to sort students by lastName
void StudentList::sortByLastName()
{
    
    // write your code here to sort students by their last name
    // hint: you can see how I implemmented the sortByFirstName method


}

//The following function is to sort students by department
void StudentList::sortByDepartment()
{
    // write your code here to sort students by their department


}


//The following function is to sort students by age
void StudentList::sortByAge(){
    // Write your code here to sort students by their age


}