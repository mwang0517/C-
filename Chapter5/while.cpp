//5.13
#include <iostream>
const int arSize = 20;

int main() {
    using namespace std;
    char name[arSize];
    cout << "Your first name, please: ";
    cin >> name;
    cout << "Here is your name, verticalized and ASCIIized:\n";
    int i = 0;
    while (name[i]){
        cout << name[i] << ": " << int(name[i]) << endl;
        i++;
    }
    return 0;
    
}

