#include<iostream>
#include"student.h"

using namespace std;

int main()
{
    Student st1;
    // cout<<"\nEnter first Name: ";
    // cin>>st1.firstName;

    // cout<<"\nEnter last Name: ";
    // cin>>st1.lastName;

    // cout<<"\nEnter age : ";
    // cin>>st1.age;

    // cout<<"\nEnter Department: ";
    // cin>>st1.department;

    // cout<<"\nEnter ID number: ";
    // cin>>st1.idNumber;

    // cout<<"\nEnter sex of the student: ";
    // cin>>st1.sex;

    // //print the student info
    // st1.display();
    

    Student st[3];
    for (int i = 0; i < 3; i++)
    {
        cout<<"\nEnter first Name: ";
        cin>>st[i].firstName;

        cout<<"\nEnter last Name: ";
        cin>>st[i].lastName;

        cout<<"\nEnter age : ";
        cin>>st[i].age;

        cout<<"\nEnter Department: ";
        cin>>st[i].department;

        cout<<"\nEnter ID number: ";
        cin>>st[i].idNumber;

        cout<<"\nEnter sex of the student: ";
        cin>>st[i].sex;
    }

    //Print students
    cout<<"FirstName  LastName   Age IDNo.  sex Department"<<endl;
    for(int j = 0; j< 3;j++){ 
        st[j].printStudent();
    }

    return 0;
}