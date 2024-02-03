#include <iostream>
using namespace std;
#include "bstree.h"

void displayMenu()
{
    cout << "\n\t\tBINARY SEARCH TREE CODE IMPLEMENTATION"<<endl;
    cout<<"Main Menu" << endl;
    cout << "1. Add Item into binary search tree" << endl;
    cout << "2. Delete Item from binary search tree" << endl;
    cout << "3. Search Item from binary search tree" << endl;
    cout << "4. Find the height of the binary search tree." << endl;
    cout << "5. Find the number of nodes in the binary search tree" << endl;
    cout << "6. Find the number of leaves in the binary search tree" << endl;
    cout << "7. Traverse the binary search tree" << endl;
    cout << "8. Destroy the binary search tree" << endl;
    cout << "9. Exit the program" << endl;
    cout << "\tEnter your choice here: ";
}
int main()
{
    char ch;
    int item;
    BinarySearchTree T;
    do
    {
        displayMenu();
        cin >> ch;
        cout << endl;
        switch (ch)
        {
        case '1':
            cout << "Enter the item you want to add: ";
            cin >> item;
            T.insert(item);
            break;
        case '2':
            cout << "Enter the item you want to delete: ";
            cin >> item;
            T.remove(item);
            break;

        case '3':
            cout << "Enter the item you want to search: ";
            cin >> item;
            if (T.search(item))
                cout << "<<\n"
                     << item << " exist in the tree." << endl;
            else
                cout << "<<\n"
                     << item << " doen't exist in the tree." << endl;

            break;
        case '4':
            cout << "\nThe height of the binary search tree is: " << T.treeHeight() << endl;
            break;
        case '5':
            cout << "\nTotal number of nodes in the binary search tree: " << T.treeNodeCount() << endl;
            break;

        case '6':
            cout << "\nTotal number of leaves in the binary search tree: " << T.leavesCount() << endl;
            break;

        case '7':
            if (T.isEmpty())
            {
                cout << "The tree is empty!" << endl;
            }
            else
            {
                cout << "\nTraverse the binary search tree using: " << endl;
                cout << "a) Inorder Traversal: \n\t\t";
                T.inorderTraversal();

                cout << "\nb) Preorder Traversal: \n\t\t";
                T.preorderTraversal();

                cout << "\nc) Postorder Traversal: \n\t\t";
                T.postorderTraversal();
            }
            break;

        case '8':
            char confirm;
            cout << "\n\tAre you sure you want to destroy? Type 'y' to confirm: ";
            cin >> confirm;
            if (confirm == 'y' or confirm == 'Y')
            {
                T.destroyTree();
                cout << "\n\tNow the tree is destroyed!" << endl;
            }
            break;
        case '9':
            // Program exits;
            break;

        default:
            cout << "You have entered invalid choice! Try again." << endl;
            break;
        }
    } while (ch != '9');

    return 0;
}