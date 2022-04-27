
#include <iostream>
#include "book.h"
#include <stdlib.h>
#include <string>

using namespace std;

int main()
{
    Book example(12345, "booktitle", 5.55, 100);
    cout << "ISBN: " << example.getISBN() << " Bookname: " << example.getbookname() << " Price: " << example.getprice() << " Stock: " << example.getstock() << endl<<endl<<endl;
  
    int testisbn;
    cout << "Enter ISBN: ";
    cin >> testisbn;
    if(example.setISBN(testisbn) == true)
    {cout << "works" << endl;}
    else if(example.setISBN(testisbn) == false)
    {cout << "not work" << endl;}
    
    cout << endl << endl;
    
    string testbookname;
    cout << "Enter Bookname: ";
    cin >> testbookname;
    example.setbookname(testbookname);
    cout << "New Bookname is: " << example.getbookname() << endl << endl;
    
    double testprice;
    cout << "Enter Price: ";
    cin >> testprice;
    if(example.setprice(testprice) == true)
    {cout << "works" << endl;}
    else if(example.setprice(testprice) == false)
    {cout << "not work" << endl;}
    
    cout << endl << endl;
    
    int teststock;
    cout << "Enter Stock: ";
    cin >> teststock;
    if(example.setstock(teststock) == true)
    {cout << "works" << endl;}
    else if(example.setstock(teststock) == false)
    {cout << "not work" << endl;}
    
    cout << endl << endl;

    cout << "Final Book: " << example.getISBN() << " " << example.getbookname() <<" " << example.getprice() <<" " << example.getstock() << endl;
    
    
}
    
