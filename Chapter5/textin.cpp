//5.17
#include <iostream>

/*int main() {
    using namespace std;
    char ch;
    int count = 0;
    cout << "Enter characters; enter # to quit :\n";
    cin >> ch;
    while (ch != '#'){
        cout << ch;
        ++count;
        cin >> ch;
    }
    cout << endl << count << " characters read\n";
    return 0;
    
}*/

/*int main() {
    using namespace std;
    char ch;
    int count = 0;
    
    cout << "Enter characters; enter # to quit: \n";
    cin.get(ch);
    while ( ch != '#' ){
        cout << ch;
        ++count;
        cin.get(ch);
    }
    cout << endl << count << " characters read\n";
    return 0;
}*/

int main() {
    using namespace std;
    char ch;
    int count = 0;
    cin.get(ch);
    
    while (cin.fail() == false){
        cout << ch;
        ++count;
        cin.get(ch);
    }
    cout << endl << count << " characters read\n";
    return 0;
    
}
