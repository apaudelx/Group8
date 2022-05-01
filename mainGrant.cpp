/*#########################
Authors: Grant Doty (td1131)
         Ashtanyrein Duncan (add485)
         Benny Jiang (bj962)
         Ashim Paudel (ap2737)
Purpose: 
#########################*/
#include <iostream>
#include <fstream>
#include <istream>
#include <stdlib.h>
#include <string>
#include "user.h"
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
    cout << "Come Again\n\n";
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
  string u, pass, p, line;
  ifstream infile;
  system("cls");
  cout << "Enter in your Login details" << endl;
  cout << "USERNAME: ";
  // Get Username
  while (cin >> u) {
    infile.open("userDB.txt");
    bool found = false;
    while (getline(infile, line)) {
      if (u == line) {
        found = true;
        break;
      }
      getline(infile, line);
      getline(infile, line);
      getline(infile, line);
      getline(infile, line);
    }
    if (found)
      break;
    else {
      infile.close();
      cout << endl << "User not found. Try again: ";
    }
  }
  // Get password
  cout << "PASSWORD: ";
  getline(infile, p);
  while (cin >> pass) {
    if (pass == p)
      break;
    else
      cout << endl << "Password does not match. Try again: ";
  }

  // set user
  User usr(u, pass);
  
  
  count = 1;
  system("cls");
  infile.close();
  bool again = true;
  string ans, shipp, pay;
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
      cout << "    Delete account" << endl;
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
      system("cls");
      switch (choice)
      {
      case 1:
        int choice;
        cout << "Account Information" << endl;
        cout << "1. Username" << endl;
        cout << "2. Password" << endl;
        cout << "3. Shipping address" << endl;
        cout << "4. Payment information" << endl;
        cout << "5. Delete account" << endl;
        cout << "6. Go back" << endl;
        cout << "\nWhat would you like to do? ";
        cin >> choice;
        cout << endl;
        switch (choice)
        {

        // Username
        case 1:
          cout << endl << "Your username is: " << usr.getData(choice) << endl;
          cout << "Change your username? (y/n): ";
          while (cin >> ans) {
            if (ans == "y" || ans == "Y") {
              cout << "Enter new username (3-9 characters): ";
              while (getline(cin, u)) {
                if (u.length() < 3 || u.length() > 9) {
                  cout << endl << "Enter a username between 3 and 9 character: ";
                }
                else {
                  usr.setUsername(u);
                  break;
                }
              }
              again = true;
              system("cls");
              cout << "Username changed to: " << usr.getData(1) << endl << endl;
              break;
            }
            else if (ans == "n" || ans == "N") {
              again = true;
              system("cls");
              break;
            }
            else {
              cout << endl << "Enter y/Y for yes or n/N for no: ";
            }
          }
          break;

        // Password
        case 2:
          cout << endl << "Your password is: " << usr.getData(choice) << endl;
          cout << "Change your password? (y/n): ";
          while (cin >> ans) {
            if (ans == "y" || ans == "Y") {
              cout << "Enter new username (6-12 characters): ";
              while (getline(cin, pass)) {
                if (pass.length() < 6 || pass.length() > 12) {
                  cout << endl << "Enter a password between 3 and 9 character: ";
                }
                else {
                  usr.setPassword(pass);
                  break;
                }
              }
              again = true;
              system("cls");
              cout << "Password changed to: " << usr.getData(2) << endl << endl;
              break;
            }
            else if (ans == "n" || ans == "N") {
              again = true;
              system("cls");
              break;
            }
            else {
              cout << endl << "Enter y/Y for yes or n/N for no: ";
            }
          }
          break;

        // Shipping
        case 3:
          if (usr.getData(choice) == "NULL") {
            cout << endl << "You have not entered a shipping address." << endl;
          }
          else
            cout << endl << "Your shipping address is: " << usr.getData(choice) << endl;
          cout << "Change your address? (y/n): ";
          while (cin >> ans) {
            if (ans == "y" || ans == "Y") {
              cout << "Enter new address: ";
              while (getline(cin, shipp)) {
                if (shipp.length() < 7 || shipp.length() > 25) {
                  cout << endl << "Enter valid address (ex - 123 main st): ";
                }
                else {
                  usr.setShipping(shipp);
                  break;
                }
              }
              again = true;
              system("cls");
              cout << "Shipping changed to: " << usr.getData(3) << endl << endl;
              break;
            }
            else if (ans == "n" || ans == "N") {
              again = true;
              system("cls");
              break;
            }
            else {
              cout << endl << "Enter y/Y for yes or n/N for no: ";
            }
          }
          break;

        // Payment
        case 4:
          if (usr.getData(choice) == "NULL") {
            cout << endl << "You have not entered a card number." << endl;
          }
          else
            cout << endl << "Your card number is: " << usr.getData(choice) << endl;
          cout << "Change your card number? (y/n): ";
          while (cin >> ans) {
            if (ans == "y" || ans == "Y") {
              cout << "Enter new card number: ";
              while (getline(cin, pay)) {
                if (pay.length() < 16 || pay.length() > 20) {
                  cout << endl << "Enter valid card number (ex - xxxx xxxx xxxx xxxx: ";
                }
                else {
                  usr.setPayment(pay);
                  break;
                }
              }
              again = true;
              system("cls");
              cout << "Card number changed to: " << usr.getData(4) << endl << endl;
              break;
            }
            else if (ans == "n" || ans == "N") {
              again = true;
              system("cls");
              break;
            }
            else {
              cout << endl << "Enter y/Y for yes or n/N for no: ";
            }
          }
          break;

        // Delete
        case 5:
          cout << "Are you sure you want to delete your account? This cannot be undone. (y/n): ";
          while (cin >> ans) {
            if (ans == "y" || ans == "Y") {
              usr.deleteUser();
              system("cls");
              cout << "Account deleted." << endl << endl;
              choice = 6;
              break;
            }
            else if (ans == "n" || ans == "N") {
              again = true;
              system("cls");
              break;
            }
            else {
              cout << endl << "Enter y/Y for yes or n/N for no: ";
            }
          }
          break;

        // Go back
        case 6:
          again = true;
          system("cls");
          break;
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
        main();
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
  ifstream infile;
  string reguser, regpass, ru, rp, line;
  system("cls");
  cout << "Enter the username (3-9 characters): ";
  while(cin >> reguser){
    // check for correct length
    if (reguser.length() < 3 || reguser.length() > 9)
      cout << endl << "Enter a username between 3 and 9 characters: ";
    else {
      // check if user already exists
      infile.open("userDB.txt");
      bool good = true;
      while (getline(infile, line)) {
        if (line == reguser) {
          cout << endl << "Username already taken. Try another: ";
          good = false;
          infile.close();
          break;
        } 
        getline(infile, line);
        getline(infile, line);
        getline(infile, line);
        getline(infile, line);
      }
      infile.close();
      if (good)
        break;
    }
  }
  cout << "\nEnter the password (6-12 characters): ";
  while (cin >> regpass) {
    if (regpass.length() < 6 || regpass.length() > 12)
      cout << endl << "Enter a password between 6 and 12 characters: ";
    else
      break;
  }

  ofstream reg("userDB.txt", ios::app);
  reg << reguser << "\n" << regpass << "\n" << "NULL" << "\n" << "NULL" << "\n" << "\n";
  reg.close();
  system("cls");
  cout << "\nRegistration Sucessful\n";
  main();


}
