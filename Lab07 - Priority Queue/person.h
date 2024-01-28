class Person
{
    string firstName, lastName;
    string gender;
    // int age;

public:
    // Person(string firstName, string lastName, string gender, int age)
    Person(string firstName, string lastName, string gender)
    {
        this->firstName = firstName;
        this->lastName = lastName;
        this->gender = gender;
        // this->age = age;
    }
    // write a default constructor here
    Person()
    {
        firstName = "";
        lastName = "";
        gender = "";
        // age = 0;
    }

    void setFirstName(string firstName)
    {
        this->firstName = firstName;
    }

    void setLastName(string lastName)
    {
        this->lastName = lastName;
    }

    void setGender(string gender)
    {
        this->gender = gender;
    }

    // void setAge(int age)
    // {
    //     this->age = age;
    // }

    string getFirstName()
    {
        return firstName;
    }

    string getLastName()
    {
        return lastName;
    }

    string getGender()
    {
        return gender;
    }

    // int getAge()
    // {
    //     return age;
    // }

    void print()
    {
        cout << "First Name: " << firstName << endl;
        cout << "Last Name: " << lastName << endl;
        cout << "Gender: " << gender << endl;
        // cout << "Age: " << age << endl;
    }
};