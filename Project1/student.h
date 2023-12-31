#include <iostream>
using namespace std;

struct Student
{
    string firstName, lastName, department;
    int age, idNumber;
    char sex;

    void printStudent() const
    {
        cout << firstName << " " << lastName << " "
             << " " << age << " " << idNumber << " " << sex << " " << department << endl;
    }

    void setStudent(string fn, string ln, int a, int id, char s, string d)
    {
        firstName = fn;
        lastName = ln;
        age = a;
        idNumber = id;
        sex = s;
        department = d;
    }

    void setFirstName(string fn)
    {
        firstName = fn;
    }

    void setLastName(string ln)
    {
        lastName = ln;
    }

    void setAgae(int a)
    {
        age = a;
    }

    void setIdNumber(int id)
    {
        idNumber = id;
    }

    void setSex(char s)
    {
        sex = s;
    }

    void setDepartment(string d)
    {
        department = d;
    }

    string getFirstName() const
    {
        return firstName;
    }
    string getLastName() const
    {
        return lastName;
    }
    string getDepartment() const
    {
        return department;
    }
    int getAge() const
    {
        return age;
    }
    int getIdNumber() const
    {
        return idNumber;
    }

    char getSex() const
    {
        return sex;
    }
};