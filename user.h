/*#########################
Author: Grant Doty td1131
Purpose: This file contains the class declaration and method
         definitions for the user class (user.h).
#########################*/

#ifndef USER_H
#define USER_H

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class User{
  public:
    User(string usrName = "", string pwd = "");
    void setPayment(string cardNum = "");
    void setShipping(string address = "");
    void setUsername(string usrName = "");
    void setPassword(string pwd = "");
    string getData(int choice);
    void deleteUser();
    ~User();
  protected:
    string username;
    string password;
    string paymentInfo;
    string shippingInfo;
    //Orderhistory
    //cart
};

// Methods

// Constructor Method
User::User(string usrName, string pwd){
  username = usrName;
  password = pwd;
  // Get shipping and payment from database
  ifstream infile;
  string line;
  infile.open("userDB.txt");
  while (getline(infile, line)) {
    if (line == username) {
      getline(infile, line);
      getline(infile, line);
      paymentInfo = line;
      getline(infile, line);
      shippingInfo = line;
      break;
    }
    getline(infile, line);
    getline(infile, line);
    getline(infile, line);
    getline(infile, line);
  }
  infile.close();
}

// setPayment Method
void User::setPayment(string cardNum){
  paymentInfo = cardNum;
  // add paymentInfo to database
  string line;
  ifstream infile("userDB.txt");
  ofstream outfile("userTMP.txt");
  while (getline(infile, line)) {
    if (line == username) {
      outfile << line << '\n';
      getline(infile, line);
      outfile << line << '\n';
      getline(infile, line);
      outfile << paymentInfo << '\n';
    }
    else {
      if (line == "\n")
        outfile << line;
      else
        outfile << line << '\n';
    }
  }
  infile.close();
  outfile.close();
  remove("userDB.txt");
  int err = rename("userTMP.txt", "userDB.txt");
  cout << "Set payment to: " << paymentInfo << endl;
}

// setAddress Method
void User::setShipping(string address){
  shippingInfo = address;
  // add shippingInfo to database
  string line;
  ifstream infile("userDB.txt");
  ofstream outfile("userTMP.txt");
  while (getline(infile, line)) {
    if (line == username) {
      outfile << line << '\n';
      getline(infile, line);
      outfile << line << '\n';
      getline(infile, line);
      outfile << line << '\n';
      getline(infile, line);
      outfile << shippingInfo << '\n';
    }
    else {
      if (line == "\n")
        outfile << line;
      else
        outfile << line << '\n';
    }
  }
  infile.close();
  outfile.close();
  remove("userDB.txt");
  int err = rename("userTMP.txt", "userDB.txt");
  cout << "Set shipping to: " << shippingInfo << endl;
}

// setUsername Method
void User::setUsername(string usrName){
  // add username to database
  string line;
  ifstream infile("userDB.txt");
  ofstream outfile("userTMP.txt");
  while (getline(infile, line)) {
    if (line == username) {
      outfile << usrName << '\n';
    }
    else {
      if (line == "\n")
        outfile << line;
      else
        outfile << line << '\n';
    }
  }
  infile.close();
  outfile.close();
  remove("userDB.txt");
  int err = rename("userTMP.txt", "userDB.txt");
  username = usrName;
  cout << "Set username to: " << username << endl;
}

// setPassword Method
void User::setPassword(string pwd){
  password = pwd;
  // add password to database
  string line;
  ifstream infile("userDB.txt");
  ofstream outfile("userTMP.txt");
  while (getline(infile, line)) {
    if (line == username) {
      outfile << line << '\n';
      getline(infile, line);
      outfile << password << '\n';
    }
    else {
      if (line == "\n")
        outfile << line;
      else
        outfile << line << '\n';
    }
  }
  infile.close();
  outfile.close();
  remove("userDB.txt");
  int err = rename("userTMP.txt", "userDB.txt");
  cout << "Set password to: " << password << endl;
}

// deleteUser Method
void User::deleteUser(){
  // delete all user information from database
  string line;
  ifstream infile("userDB.txt");
  ofstream outfile("userTMP.txt");
  while (getline(infile, line)) {
    if (line == username) {
      getline(infile, line);
      getline(infile, line);
      getline(infile, line);
      getline(infile, line);
    }
    else {
      if (line == "\n")
        outfile << line;
      else
        outfile << line << '\n';
    }
  }
  infile.close();
  outfile.close();
  remove("userDB.txt");
  int err = rename("userTMP.txt", "userDB.txt");
}

// getData Method
string User::getData(int choice) {
  if (choice == 1) {
    return username;
  }
  else if (choice == 2) {
    return password;
  }
  else if (choice == 3) {
    return shippingInfo;
  }
  else if (choice == 4) {
    return paymentInfo;
  }
  else
    return "NULL";
}

// Destructor Method
User::~User(){
}

#endif