#include <iostream>
#include<istream>
#include<fstream>
#include<stdlib.h>
#include<string.h>
void login();
void create_account();

using namespace std;

int main()
{
    int choice;
    cout << "MENU\n";
    cout << "1.LOGIN" << endl;
    cout << "2.Create Account" << endl;
    cout << "3.Exit" << endl;
    cout << "\nEnter your choice:";
    cin >> choice;
    cout << endl;
    switch (choice)
    {
    case 1:
        login();
        break;
    case 2:
        create_account();
        break;
    case 3:
        cout << "Thanks\n\n";
        break;
    default:
        system("cls");
        cout << "Invalid Choice, try again.\n" << endl;
        main();
    }

}

void login()
{
    int count;
    string user, pass, u, p;
    system("cls");
    cout << "Enter in your Login details" << endl;
    cout << "USERNAME:";
    cin >> user;
    cout << "PASSWORD:";
    cin >> pass;

    ifstream input("database.txt");
    while (input >> u >> p)
    {
        if (u == user && p == pass)

        {
            count = 1;
            system("cls");
        }
    }
    input.close();
    bool again = true;
    while (again) {
        again = false;

        if (count == 1)
        {
            int choice;
            cout << "MENU\n";
            cout << "1. Account Information" << endl;
            cout << "    Username" << endl;
            cout << "    Password" << endl;
            cout << "    Shipping address" << endl;
            cout << "    Payment information" << endl;
            cout << "    Go back" << endl;
            cout << "2. Cart Information" << endl;
            cout << "    Go back" << endl;
            cout << "    View Cart" << endl;
            cout << "    Remove Item from Cart" << endl;
            cout << "    Add item to cart" << endl;
            cout << "    Checkout" << endl;
            cout << "3. Order History" << endl;
            cout << "    Go back" << endl;
            cout << "4. Inventory" << endl;
            cout << "    Categories" << endl;
            cout << "    Go back" << endl;
            cout << "5. Exit Program (logout)" << endl;
            cout << "\nWhat would you like to do? ";
            cin >> choice;
            cout << endl;
            switch (choice)
            {
            case 1:
                int choice;
                cout << "Account Information" << endl;
                cout << "1. Username" << endl;
                cout << "2. Password" << endl;
                cout << "3. Shipping address" << endl;
                cout << "4. Payment information" << endl;
                cout << "5. Go back" << endl;
                cout << "\nWhat would you like to do? ";
                cin >> choice;
                cout << endl;
                switch (choice)
                {
                case 1:
                    cout << "Change user name";
                case 2:
                    cout << "Change user name";
                case 3:
                    cout << "Change user name";
                case 4:
                    cout << "Change user name";
                case 5:
                    again = true;
                }
                break;
            case 2:
                cout << "Cart Information" << endl;
                cout << "1. View Cart" << endl;
                cout << "2. Remove Item from Cart" << endl;
                cout << "3. Add item to cart" << endl;
                cout << "4. Checkout" << endl;
                cout << "5. Go back" << endl;
                cout << "\nWhat would you like to do? ";
                break;
            case 3:
                cout << "Order History" << endl;
                cout << "1. View Order History" << endl;
                cout << "2. Go back" << endl;
                cout << "\nWhat would you like to do? ";
                break;
            case 4:
                cout << "Inventory" << endl;
                cout << "1. Categories" << endl;
                cout << "2. Go back" << endl;
                cout << "\nWhat would you like to do? ";
                break;
            case 5:
                cout << "Thanks\n\n";
                break;
            default:
                system("cls");
                cout << "Invalid Choice, try again.\n" << endl;
            }

        }
        else
        {
            cout << "\nLOGIN ERROR\nPlease check your username and password\n";
            main();
        }
    }
}

void create_account()
{

    string reguser, regpass, ru, rp;
    system("cls");
    cout << "Enter the username: ";
    cin >> reguser;
    cout << "\nEnter the password: ";
    cin >> regpass;

    ofstream reg("database.txt", ios::app);
    reg << reguser << ' ' << regpass << endl;
    system("cls");
    cout << "\nRegistration Sucessful\n";
    main();


}

