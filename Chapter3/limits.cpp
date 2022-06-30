//3.1
#include <iostream>
#include <climits>

int main() {
    
    using namespace std;
    int n_int = INT_MAX;
    short n_short = SHRT_MAX;
    long n_long = LONG_MAX;
    long long n_llong = LLONG_MAX;
    
    cout << "int is " << sizeof (int) << " bytes." << endl;
    cout << "short is " << sizeof n_short << " bytes." << endl;
    cout << "long is " << sizeof n_long << " bytes." << endl;
    
    cout << "Maximum value: " << endl;
    cout << "int: " << n_int << endl;
    cout << "short: " << n_short << endl;
    
    cout << "Bits per byte = " << CHAR_BIT << endl;
    
    return 0;
}
