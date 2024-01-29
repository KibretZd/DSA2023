// This file is to construct menu driven program

#include"StudentList.h"

void displaySearchMenu(StudentList *stList)
{
    char my_choice;
    string strName;

    cout << "a. Search by first name" << endl
         << "b. Search by last name" << endl
         << "c. Search by department" << endl
         << "d. Search by ID number" << endl
         << "\n\tEnter your choice: ";
    cin >> my_choice;
    switch (my_choice)
    {
    case 'a':
        cout << "\nEnter the student first name: ";
        cin >> strName;
        stList->searchByFirstName(strName);
        
        break;

    case 'b':
        cout << "\nEnter the student last name: ";
        cin >> strName;
        stList->searchByLastName(strName);
        
        break;

    case 'c':
        cout << "\nEnter the student department: ";
        cin >> strName;
        stList->searchByDepartment(strName);
        
        break;

    case 'd':
        int id, position;
        cout << "\nEnter the student ID number: ";
        cin >> id;
        position = stList->searchByIdNumber(id);
        if(position != -1)
        {
            cout << "Student is found at position " << position << endl;
        }
        else
        {
            cout << "No student is found!" << endl;
        }
        break;

    default:
        cout << "Invalid choice! Try again!" << endl;
        
        break;
    }
}

void dislaySortMenu(StudentList *stList)
{
    char sort_choice;
    
        cout << "a. To sort by their name." << endl
             << "b. To sort by department." << endl
             << "c. To sort by ID number." << endl
             << "\n\tEnter your choice: ";
        cin >> sort_choice;
        switch (sort_choice)
        {
        case 'a':
            stList->sortByName();
            
            break;

        case 'b':
            stList->sortByDepartment();
            
            break;

        case 'c':
            stList->sortByIdNumber();
            
            break;

        default:
            cout << "Invalid choice! Try again!" << endl;
            
            break;
        }
    
}
void displayMainMenu()
{
    StudentList stList;
    Student student;
    char choice;
    int index;
    int id;
    do
    {
        cout << "\n\n"
             << "1. To register new student" << endl
             << "2. To remove a student" << endl
             << "3. To update a student information" << endl
             << "4. To search a student." << endl
             << "5. To sort students in the list." << endl
             << "6. To print all students." << endl
             << "7. To print all female students." << endl
             << "8. To print all male students." << endl
             << "9. Number of students registered." << endl
             << "0. To terminate the program." << endl
             << "\n\tEnter your choice: ";
        cin >> choice;
        switch (choice)
        {
        case '1':
            student.readStudent();
            cout<<"Enter the position where to insert this student? ";
            cin>>index;
            stList.addStudent(student, index);
            break;

        case '2':
            cout << "Enter the id of the student to be removed: ";
            cin >> id;
            stList.removeStudentByIdNumber(id);
            break;

        case '3':
            cout << "Enter the id of the student to be updated: ";
            cin >> id;
            index = stList.searchByIdNumber(id);
            if (index != -1)
            {
                student.readStudent();
                stList.updateStudent(index, student);
                cout << "Student updated successfully!" << endl;
            }
            else
            {
                cout << "Student not found!" << endl;
            }
            break;

        case '4':
            displaySearchMenu(&stList);
            break;

        case '5':
            dislaySortMenu(&stList);
            break;

        case '6':
            stList.traverse();
            break;

        case '7':
            stList.femaleStudents();
            break;

        case '8':
            stList.maleStudents();
            break;
        
        case '9':
            cout<<"The number of Students: "<<stList.length()<<endl;
            break;

        case '0':
            cout << "Press any key to exit the program!" << endl;
            break;

        default:
            cout << "Invalid choice! Try again!" << endl;
            break;
        }
    } while (choice != '0');
}