#include "book.h"

int Book::getISBN()
{
    return ISBN;
}
string Book::getbookname()
{
    return bookname;
}
double Book::getprice()
{
    return price;
}
int Book::getstock()
{
    return stock;
}
bool Book::setISBN(int isbn)
{
    int size = trunc(log10(isbn)) + 1; //checks the size of isbn
    if(size == 5) //ISBN is 5 digits long
    {
        ISBN = isbn;
        return true;
    }
    else
    {
        return false;
    }
}
bool Book::setbookname(string bookname)
{
    this->bookname = bookname;
    return true;
}
bool Book::setprice(double price)
{
    if(price > 0)
    {
        this->price = price;
        return true;
    }
    else
    {
        return false;
    }
    
}
bool Book::setstock(int stock)
{
    if(stock > 0)
    {
        this->stock = stock;
        return true;
    }
    else
    {
        return false;
    }
}
