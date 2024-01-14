#include <iostream>
using namespace std;

class Student
{
    string firstName, lastName, department;
    int age, idNumber;
    char sex;

public:
    Student();  //Default Constructor
    
    Student(string fn, string ln, int a, int id, char s, string d); //Parameterized Constructor

    void readStudent(); // To read the information of a student
    void printStudent() const; // To print the information of a student
    void setFirstName(string fn); // To change the first name of a student

    void setLastName(string ln);    // To change the last name of a student

    void setAgae(int a);    //To change the age of a student

    void setIdNumber(int id);// to change the id of a student

    void setSex(char s); //To change the sex of a student

    void setDepartment(string d); // To change the department of a student

    string getFirstName() const;    // To retrive the first name of a student

    string getLastName() const; // To retrive the last name of a student

    string getDepartment() const;   // To retrive the department of a student

    int getAge() const; // To retrive the age of a student

    int getIdNumber() const;    // To retrive the id of a student

    char getSex() const;    // To retrive the sex of a student
};

Student ::Student()
{
    firstName = " ";
    lastName = " ";
    age = 0;
    idNumber = 0;
    sex = ' ';
    department = " ";
}

void Student::printStudent() const
{
    cout << firstName << " " << lastName << " "
         << "\t" << age << "\t" << idNumber << "\t" << sex << "\t" << department << endl;
}

Student::Student(string fn, string ln, int a, int id, char s, string d)
{
    firstName = fn;
    lastName = ln;
    age = a;
    idNumber = id;
    sex = s;
    department = d;
}

void Student::setFirstName(string fn)
{
    firstName = fn;
}

void Student::setLastName(string ln)
{
    lastName = ln;
}

void Student::setAgae(int a)
{
    age = a;
}

void Student::setIdNumber(int id)
{
    idNumber = id;
}

void Student::setSex(char s)
{
    sex = s;
}

void Student::setDepartment(string d)
{
    department = d;
}

string Student::getFirstName() const
{
    return firstName;
}
string Student::getLastName() const
{
    return lastName;
}
string Student::getDepartment() const
{
    return department;
}
int Student::getAge() const
{
    return age;
}
int Student::getIdNumber() const
{
    return idNumber;
}

char Student::getSex() const
{
    return sex;
}

void Student::readStudent()
{
    cout << "\nEnter first Name: ";
    cin >> firstName;

    cout << "\nEnter last Name: ";
    cin >> lastName;

    cout << "\nEnter age : ";
    cin >> age;

    cout << "\nEnter Department: ";
    cin >> department;

    cout << "\nEnter ID number: ";
    cin >> idNumber;

    cout << "\nEnter sex of the student: ";
    cin >> sex;
}