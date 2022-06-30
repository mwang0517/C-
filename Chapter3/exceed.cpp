//3.2
#include <iostream>
#include <climits>
#define ZERO 0

int main() {
    
    using namespace std;
    short sam = SHRT_MAX;
    unsigned short sue = sam;
    
    cout << "Sam has " << sam << " dollars and Sue has " << sue << " dollars deposited." << endl;
    cout << "Add $1 to each account. " << endl;
    sam = sam + 1;
    sue = sue + 1;
    cout << "Sam has " << sam << " dollars and Sue has " << sue << " dollars deposited.\n Poor Sam!" << endl;
    
    sam = ZERO;
    sue = ZERO;
    cout << "Sam has " << sam << " dollars and Sue has " << sue << " dollars deposited." << endl;
    cout << "Take $1 to each account. " << endl;
    sam = sam - 1;
    sue = sue - 1;
    cout << "Sam has " << sam << " dollars and Sue has " << sue << " dollars deposited.\n Lucky Sue!" << endl;
    return 0;
}
