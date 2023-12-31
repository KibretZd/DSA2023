#include<iostream>
using namespace std;

struct Student{
    string fisrtName, lastName, department;
    int age, idNumber;
    char sex;

    void display(){
        cout<<fisrtName<<" "<<lastName<<" "
            <<" "<<age<<" "<<idNumber<<" "<<sex<<department<<endl;
    }

    void setStudent(string fn, string ln, int a, int id, char s, string d){
        fisrtName = fn;
        lastName = ln;
        age = a;
        idNumber = id;
        sex = s;
        department = d;
    }

    void setFirstName(string fn){
        fisrtName = fn;
    }

    void setLastName(string ln){
        lastName = ln;
    }

    void setAgae(int a){
        age = a;
    }

    void setIdNumber(int id){
        idNumber = id;
    }

    void setSex(char s){
        sex = s;
    }

    void setDepartment(string d){
        department = d;
    }

    string getFirstName() {
        return fisrtName;
    }
    string getLastName() {
        return lastName;
    }
    string getDepartment() {
        return department;
    }
    int getAge() {
        return age;
    }
    int getIdNumber() {
        return idNumber;
    }

    char getSex() {
        return sex;
    }
};