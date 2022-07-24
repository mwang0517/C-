#include <iostream>
using std::cout;
#include "strngbad.h"

void callme1(StringBad &); //pass by reference
void callme2(StringBad);   //pass by value

int main(){
    using std::endl;
    {
        cout << "Start an inner block.\n";
        StringBad headline1("Celery Stalks at Midnight");
        StringBad headline2("Lettuce Prey");
        StringBad sports("Spinach Leaves Bowl for Dollars");
        
        cout << "headline1: " << headline1 << endl;
        cout << "headline2: " << headline2 << endl;
        cout << "sports: " << sports << endl;
        
        callme1(headline1);
        cout << "headline1: " << headline1 << endl;
        
        callme2(headline2);
        cout << "headline2: " << headline2 << endl; //ERROR OCCURS
        
        cout << "Initialize one object to another:\n";
        StringBad sailor = sports;
        cout << "sailor: " << sailor << endl;
        
        cout << "Assign one object to another:\n";
        StringBad Knot;
        Knot = headline1;
        cout << "knot: " << Knot << endl;
        cout << "Exiting the block.\n";
    }
}

void callme1(StringBad & rsb){
    cout << "String passed by reference:\n";
    cout << " \"" << rsb << "\"\n";
}

void callme2(StringBad sb){
    cout << "String passed by value:\n";
    cout << " \"" << sb << "\"\n";
}

/*Start an inner block.
1: "Celery Stalks at Midnight" object created 
2: "Lettuce Prey" object created 
3: "Spinach Leaves Bowl for Dollars" object created 
headline1: Celery Stalks at Midnight
headline2: Lettuce Prey
sports: Spinach Leaves Bowl for Dollars

String passed by reference:
 "Celery Stalks at Midnight"
headline1: Celery Stalks at Midnight
 
String passed by value:
 "Lettuce Prey"
"Lettuce Prey" object deleted, 2 left
headline2: Duo //error here
 
Initialize one object to another:
sailor: Spinach Leaves Bowl for Dollars
Assign one object to another:
3: "c++" object created 
knot: Celery Stalks at Midnight
Exiting the block.
 
"Celery Stalks at Midnight" object deleted, 2 left
"Spinach Leaves Bowl for Dollars" object deleted, 1 left
"Spinach Leaves Bowl for Doll8" object deleted, 0 left  //error here
TextbookProject(4814,0x115cd0e00) malloc: *** error for object 0x7fdf5af040b0: pointer being freed was not allocated
TextbookProject(4814,0x115cd0e00) malloc: *** set a breakpoint in malloc_error_break to debug*/