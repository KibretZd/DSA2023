void displayMenu()
{
    List list1;
    int num, position;
    char choice;
    do
    {

        cout << "\n\n\t\tLinked List Menu" << endl;
        cout << "1. Add an element to the list" << endl;
        cout << "2. Remove an element from the list" << endl;
        cout << "3. Traverse the list" << endl;
        cout << "4. Update an element in the list" << endl;
        cout << "5. Search an element in the list" << endl;
        cout << "6. Find the length of the list" << endl;
        cout << "7. Exit" << endl;
        cout << "Enter your choice:" << endl;
        cin >> choice;
        switch (choice)
        {
        case '1':
            cout << "\nEnter  number to be inserted:";
            cin >> num;
            cout << "\nEnter position:";
            cin >> position;
            list1.add(num, position);
            break;

        case '2':
            cout << "\nEnter  number to be removed:";
            cin >> num;
            list1.remove(num);
            cout << endl;
            break;

        case '3':
            cout << "\nTraversing the list:";
            list1.traverse();
            break;

        case '4':
            int old_data, new_Data;
            cout << "\nEnter  number to be updated:";
            cin >> old_data;
            cout << "\nEnter new number:";
            cin >> new_Data;
            list1.update(old_data, new_Data);
            cout << endl;
            break;

        case '5':
            cout << "\nEnter number to be searched:";
            cin >> num;
            if (list1.search(num))
            {
                cout << "\n"
                     << num << " Found" << endl;
                ;
            }
            else
            {
                cout << "\n"
                     << num << " Found" << endl;
            }
            break;
        case '6':
            cout << "\nThe length of the list: "
                 << list1.length() << endl;
            break;

        case '7':
            cout << "\nGood Bye!" << endl;
            break;

        default:
            cout << "\nInvalid choice!" << endl;
            break;
        }
    } while (choice != '7');
}