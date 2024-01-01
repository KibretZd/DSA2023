# Project 1 - Student Information Management system using Arrays
This student management system has the following functions:
1. Registers a new student to the student list
2. Removes a student from the list using the ID of a student
3. Updates a student by ID number of a student
4. search a student/s by:
    * Searches a particular student by using ID number of a student
    * Search and prints all students by first name of the student
    * Search and prints all students by last name of the student
    * Search and prints all students by department

5. Sort students in ascending order using:
    - By student names
    - ID number
    - Department
6. Prints all students
7. Print the all the **female** students and number of female student
8. Print the all the **male** students and number of female student
9. Prints total Number of student already added to the list

## Instruction

* This project is a group assignment of maximum 5 students per each group.
* Code sharing accross groups is strictly forbidden
* Add appropriate comments on your code
* Each group member must participate equally on the project
* There will be presentation and there will be question and answering individually.
* You have to submit on time.
* **Deadline** for project submission will untill **January 14, 2024 @3:00PM**.

## About your task in this project
In this project I have already implemented most of the tasks for you. 
To start working on the project, 
1. download this project on your local machine and make sure that you have downloaded all the files in ***Project1*** directory.

2. Open ***`testStudent.cpp`*** file using your prefered IDE (Integrated Development Environment) usually code block.
3. Run this file
5. Once you run the program you can:
    - add a student
    - remove a student
    - update a student record
    - ... others which are implemented.
Next close the program and do your assignment as instructed below.

You are expected to write code for unimplemented functions from **```studentlist.h```** file.
Unimlemented function from the file **```studentlist.h```** are as follows:
1. **`searchByLastName(string lastName)`**
```
    void StudentList::searchByLastName(string lastName)const
    {
        // Write your code here to search all student by their lastname that matches the given lastname
    }
```

2. **`searchByDepartment(string department)`**
```
    void StudentList::searchByDepartment(string department)const{
        ...
    }
```
3. **`void StudentList::maleStudents() const`**
```
    void StudentList::maleStudents() const
    {
        // Write your code here to print all male students only
        // hint: see the code above for females and modify it to print all male students

        // your code must also print the number of male students as like the above
    }
```
4. **`sortByDepartment()`**
```void StudentList::sortByDepartment()
    {
        // write your code here to sort students by their department
    }
```
5. **`sortByAge()`**
```
    void StudentList::sortByAge()
    {
        // Write your code here to sort students by their age
    }
```

6. **`sortByIdNumber()`**
```
    void StudentList::sortByIdNumber()
    {

        // Write your code here to sort students by their id number
    }
```

## Finaly
After implementing those function, you can run your program to test if they are correctly working or not.
Remember always you have to run the ***`testStudent.cpp`*** file.

### If you have any question, I am available in office in the afternoon.