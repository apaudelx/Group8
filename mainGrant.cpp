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
#include <sstream>
#include <string>
#include <iomanip>
#include "user.h"
void login();
void create_account();
void order_history();
int add_to_cart(string username);
void view_inventory();
int view_cart(string username);

using namespace std;

int main()
{
  int choice;
  string productID;
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
      cout << "    Go back" << endl;                // needs attention!
      cout << "    View Cart" << endl;              // needs attention!
      cout << "    Remove Item from Cart" << endl;  // needs attention!
      cout << "    Checkout" << endl;               // needs attention!
      cout << "3. Order History" << endl;           // needs attention!
      cout << "    Go back" << endl;                // needs attention!
      cout << "4. Inventory" << endl;               // needs attention!
      cout << "    Categories" << endl;             // needs attention!
      cout << "    Add item to cart" << endl;
      cout << "    Go back" << endl;                // needs attention!
      cout << "5. Exit Program (logout)" << endl;
      cout << "\nWhat would you like to do?  ";
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
        cout << "\nWhat would you like to do?  ";
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
        //cout << "3. Add item to cart" << endl;
        cout << "3. Checkout" << endl;
        cout << "4. Go back" << endl;
        cout << "\nWhat would you like to do?  ";
        cin >> choice;
        cout << endl;
        switch (choice)
        {
        case 1:
          cout << "Items in your cart: " << endl;
          view_cart(usr.getData(1));
          cout << endl;
          cout << "\nEnter 1 to go back:  ";
          cin >> choice;
          cout << endl;
          switch (choice)
          {
          case 1:
            again = true;
            system("cls");
            break;

          default:
            system("cls");
            cout << "Invalid choice, relogin.\n" << endl;
          }

          break;

        case 2:
          cout << "Enter the item number:";
          // delete the specific item from cart, like deleting the user from users
          cout << endl;
          break;

        case 3:
          cout << "Enter the item number: ";
          add_to_cart(usr.getData(1));
          cout << endl;
          break;

        case 4:
          // display the total price of the items from the cart
          cout << "You just checked out, the items will be delivered within 24 hours." << endl;
          break;

        case 5:
          again = true;
          system("cls");
          break;

        default:
          system("cls");
          cout << "Invalid Choice, try again.\n" << endl;
          break;
        }
        break;
      case 3:
        cout << "Order History" << endl;
        cout << "1. View Order History" << endl;
        cout << "2. Go back" << endl;
        cout << "\nWhat would you like to do?  ";
        cin >> choice;
        cout << endl;
        switch (choice)
        {
        case 1:
          // check the order history of user and output the information on screen
          cout << "This is what you have ordered." << endl;
          break;

        case 2:
          again = true;
          system("cls");
          break;

        default:
          system("cls");
          cout << "Invalid Choice, try again.\n" << endl;
          break;
        }
        break;
      case 4:
        int addproductid;
        cout << "Inventory" << endl;
        cout << "1. Categories" << endl;
        cout << "2. Go back" << endl;
        cout << "\nWhat would you like to do?  ";
        cin >> choice;
        cout << endl;
        switch (choice)
        {
        case 1:
          cout << "List of products in inventory: " << endl << endl;
          view_inventory();
          cout << endl;
          cout << " 1. Add item to cart" << endl;
          cout << " 2. Go back" << endl;
          cout << "\nWhat would you like to do?  ";
          cin >> choice;
          cout << endl;
          switch (choice)
          {
          case 1:
            // Add item to the present userName, we can either create a new text file and add the orders there
            add_to_cart(usr.getData(1));
            cout << "Item successfully added to cart";
            cout << "\nDo you want to add more items? " << endl;
            cout << "1. Yes" << endl;
            cout << "2. No, go back" << endl;

            cin >> choice;
            switch (choice)
            {
            case 1:
              add_to_cart(usr.getData(1));
              break;

            case 2:
              again = true;
              system("cls");
              break;

            default:
              break;
            }
            break;

          default:
            //system("cls");
            break;
          }

        case 2:
          again = true;
          break;

        default:
          cout << "Invalid Choice, try again.\n" << endl;
          break;
        }
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
  while (cin >> reguser) {
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

void view_inventory()
{
  string line;
  int totalLines = 0;
  ifstream myfile("inventory.txt");
  if (myfile.is_open())
  {
    while (getline(myfile, line))
    {
      totalLines++;
    }
    myfile.close();
  }
  else cout << "Unable to open file" << endl;

  // array to hold the values
  string* holdValues = new string[totalLines];
  int counter = 0;

  ifstream myfile1("inventory.txt");
  if (myfile1.is_open())
  {
    while (getline(myfile1, line))
    {
      holdValues[counter++] = line;
    }
    myfile1.close();
  }
  cout << "Product_ID" << setw(15) << "Product_Name" << setw(15) << "Price" << setw(25) << "Stock" << endl;
  cout << "---------------------------------------------------------------------------------" << endl;
  string word, id, pn, pp, ps;
  for (int i = 0; i < totalLines; i++)
  {
    istringstream iss(holdValues[i]);
    int col = 0;
    while (iss >> word)
    {
      switch (col)
      {
      case 0:
        id = word;
        break;
      case 1:
        pn = word;
        break;
      case 2:
        pp = word;
        break;
      case 3:
        ps = word;
        break;
      default:
        break;
      }
      col++;
    }
    cout << id << setw(20) << pn << setw(20) << pp << setw(20) << ps << endl;
  }

}

int add_to_cart(string username)
{
  string finduser;
  string product_id;
  cout << "Which item would you like to add (ENTER PRODUCT ID)? ";
  cin >> product_id;
  ifstream ifs("inventory.txt");
  string line;
  fstream out(username += "cart.txt", std::ios_base::app);
  while (getline(ifs, line))
  {
    size_t pos = line.find(product_id);
    if (pos != string::npos) {
      istringstream item(line);
      int col = 0;
      string word;
      while (item >> word) {
        switch (col) {
          case 0:
            cout << word << " ";
            out << word << " ";
            break;
          case 1:
            cout << word << " ";
            out << word << " ";
            break;
          case 2:
            break;
          case 3:
            cout << word << endl;
            out << word << endl;
            break;
          default:
            break;
        }
        col++;
      }
      out.close();
    }
  }
  ofstream tmp("tmpInv.txt");
  ifs.close();
  ifs.open("inventory.txt");
  bool first = true;
  int stk = 0;
  while (getline(ifs, line)) {
    if (line.substr(0, line.find(" ")) == product_id) {
      istringstream ln(line);
      int col = 0;
      string word;
      while (ln >> word) {
        switch (col) {
          case 0:
            if (first) {
              first = false;
              tmp << word << " ";
            }
            else {
              tmp << endl << word << " ";
            }
            break;
          case 1:
            tmp << word << " ";
            break;
          case 2:
            stk = stoi(word);
            stk = stk - 1;
            word = to_string(stk);
            tmp << word << " ";
            break;
          case 3:
            tmp << word << " ";
            break;
        }
        col++;
      }
    }
    else {
      if (first) {
        first = false;
        tmp << line;
      }
      else {
        tmp << endl << line;
      }
    }
  }
  ifs.close();
  tmp.close();
  remove("inventory.txt");
  int err = rename("tmpInv.txt", "inventory.txt");
  return 0;
}


int view_cart(string username)
{
  ifstream f(username += "cart.txt");
  if (f.is_open())
    cout << f.rdbuf();
  f.close();
  string s;
  int sum = 0;
  ifstream openfile(username);
  while (openfile >> s && openfile >> s && openfile >> s && openfile >> s)
  {
    sum = sum + stoi(s);
  }
  cout << "\n" << "Total : $" << sum;
  return 0;
}

void order_history()
{
  ifstream infile;
  string pid;
  system("cls");
}
