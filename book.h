#include <string>
#include <iostream>
#include<cmath>

using namespace std;

#ifndef book_h
#define book_h

class Book
{
private:
    int ISBN;
    string bookname;
    double price;
    int stock;
    
public:
    Book() : ISBN(0), bookname(""), price(0), stock(0) {}
    Book(int ISBN, string bookname, double price, int stock) : ISBN(ISBN), bookname(bookname), price(price), stock(stock) {}
    int getISBN();
    string getbookname();
    double getprice();
    int getstock();
    bool setISBN(int isbn);
    bool setbookname(string bookname);
    bool setprice(double price);
    bool setstock(int stock);
    
};

#endif 
