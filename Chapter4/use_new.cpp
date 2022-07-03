//4.17
#include <iostream>

int main() {
    using namespace std;
    int nights = 1001;
    int *pt = new int;
    *pt = 1001; //store a new value
    
    cout << "nights value = ";
    cout << nights << " location: " << &nights << endl;
    
    cout << "int value = "; 
    cout << *pt << " location: " << pt << endl;
    
    double *pd = new double;
    *pd = 10000001.0;
    cout << "double value = ";
    cout << *pd << " location: " << pd << endl;
    cout << "location of pointer pd: " << &pd << endl;
    
    cout << "size of pt = " << sizeof(pt) << endl;
    cout << "size of *pt = " << sizeof(*pt) << endl;
    cout << "size of pd = " << sizeof(pd) << endl;
    cout << "size of *pd = " << sizeof(*pd) << endl;
    
    return 0;
    
}
