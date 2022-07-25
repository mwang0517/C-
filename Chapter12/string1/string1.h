#include <iostream>
#ifndef STRING1_H_
#define STRING1_H_

using std::ostream;
using std::istream;

class String{
    
private:
    char * str;
    int len;
    static int num_strings;
    static const int CINLIM = 80;
    
public:
//constructors and other methods
    String(const char * s); //constructor
    String();
    String(const String &); //copy constructor
    ~String();
    int length() const {return len;}
//overload operator methods
    String & operator=(const String &); //assignment operator
    String & operator=(const char *);
    char & operator[](int i); //accessing characters by using bracket notation
    const char & operator[](int i) const; //C++ distinguishes between const and non-const function signatures when overloading
//overload operator friends
    friend bool operator<(const String &st, const String &st2);
    friend bool operator>(const String &st1, const String &st2);
    friend bool operator==(const String &st, const String &st2);
    friend ostream & operator<<(ostream & os, const String &st);
    friend istream & operator>>(istream & is, String &st);
//static function
    static int HowMany();
};
#endif