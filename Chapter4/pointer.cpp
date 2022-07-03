//4.15
#include <iostream>

int main() {
    using namespace std;
    int updates = 6;
    int *p_updates;
    p_updates = &updates;
    
    //express value
    cout << "Values: updates = " << updates;
    cout << " , *p_updates = " << *p_updates << endl;
    
    //express address
    cout << "Address: &updates = " << &updates;
    cout << ", p_updates = " << p_updates;
    
    //use pointer to change value
    *p_updates = *p_updates + 1;
    cout << "Now updates = " << updates << endl;
    
    return 0;
    
}
