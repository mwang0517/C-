//4.4 & 4.5
#include <iostream>

int main() {
    using namespace std;
    const int ArSize = 20;
    char name[ArSize];
    char dessert[ArSize];
    
    cout << "Enter your name:\n";
    //cin.getline(name, ArSize);
    cin.get(name, ArSize).get();
    cout << "Enter your favourite dessert:\n";
    //cin.getline(dessert, ArSize);
    cin.get(dessert, ArSize).get();
    cout << "I have some delicious " << dessert;
    cout << " for you, " << name << ".\n" << endl;
    return 0;
}
