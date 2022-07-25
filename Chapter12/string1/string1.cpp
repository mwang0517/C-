#include <cstring>
#include "string1.h"
using std::cin;
using std::cout;

//initializing static class member.
int String::num_strings = 0;

//static method
int String::HowMany(){
    return num_strings;
}

//class methods
String::String(const char * s){     //construct string from C string
    len = std::strlen(s);
    str = new char[len + 1];
    std::strcpy(str, s);
    num_strings ++;
    //cout << num_strings << ": \"" << str << "\" object created \n";
}

String::String(){         //default constructor
    len = 4;
    str = new char[1];
    str[0] = '\n';
    num_strings++;
    //cout << num_strings << ": \"" << str << "\" object created \n";
}

String::String(const String & st){   //copy constructor
    num_strings++;
    len = st.len;
    str = new char [len+1];
    std::strcpy(str, st.str);
}

String::~String(){        //necessary destructor
    //cout << "\"" << str << "\" object deleted, ";
    --num_strings;
    //cout << num_strings << " left\n";
    delete [] str;
}

//overload operator methods.
String & String::operator=(const String & st){ //assign a String to String
    if (this == &st)
        return *this;
    delete [] str;
    len = st.len;
    str = new char[len + 1];
    std::strcpy(str, st.str);
    return *this;
}

String & String::operator=(const char * s){ //assign a C string to String
    delete [] str;
    len = std::strlen(s);
    str = new char[len+1];
    std::strcpy(str, s);
    return *this;
}

char & String::operator[](int i){ //read-write char access for non-const String
    return str[i];
}

const char & String::operator[](int i) const{ //read-write char access for const String
    return str[i];
}

//overload operator friends
bool operator<(const String &st1, const String &st2){
    return (std::strcmp(st1.str, st2.str) < 0);
}

bool operator>(const String &st1, const String &st2){
    return (st2<st1);
}

bool operator==(const String &st1, const String &st2){
    return (std::strcmp(st1.str, st2.str)==0);
}

ostream & operator<<(std::ostream & os, const String & st){
    os << st.str;
    return os;
}

istream & operator>>(istream & is, String & st){
    char temp[String::CINLIM];
    is.get(temp, String::CINLIM);
    if (is)
        st = temp;
    while (is && is.get()!= '\n')
        continue;
    return is;
}