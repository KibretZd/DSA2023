void displayMenu()
{
    List list1;
    int num, position;
    char choice;
    do
    {

        cout << "\n\n\t\t Linked List Menu" << endl;
        cout << "1. Add an element to the list" << endl;
        cout << "2. Delete an element from the list" << endl;
        cout << "3. Traverse the list" << endl;
        cout << "4. Search an element from the list" << endl;
        cout << "5. Find the length of the list" << endl;
        cout << "6. Make the list empty" << endl;
        cout << "7. Exit" << endl;
        cout << "Enter your choice:  " << endl;
        cin >> choice;
        switch (choice)
        {
        case '1':
            cout << "\nEnter a number to be inserted:";
            cin >> num;
            cout << "\nEnter position:";
            cin >> position;
            list1.insert(num, position);
            break;

        case '2':
            cout << "\nEnter the element to be deleted: ";
            cin >> num;
            list1.remove(num);
            cout << endl;
            break;

        case '3':
            if (list1.isEmpty())
            {
                cout << "\nThe list is empty!" << endl;
            }
            else
            {
                cout << "\nTraversing the list: ";
                list1.traverse();
            }
            break;

        case '4':
            cout << "\nEnter an element search: ";
            cin >> num;
            if (list1.search(num))
            {
                cout << "\n"
                     << num << " is found." << endl;
            }
            else
            {
                cout << "\n"
                     << num << " is not found!" << endl;
            }
            break;
        case '5':
            cout << "\nThe length of the list: "
                 << list1.length() << endl;
            break;

        case '6':
            char confirm;
            cout << "Are you you want to destroy the list? [Y|N]: ";
            cin >> confirm;
            if (confirm == 'y' || confirm == 'Y')
            {
                list1.destroy();
                cout << "\nAll the elements of the list are deleted. The list is now empty." << endl;
            }
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