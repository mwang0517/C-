//4.13
#include <iostream>

struct inflatable{
    char name[20];
    float volume;
    double price;
};

int main() {
    using namespace std;
    inflatable guests[2] = {
        {"Bambi", 0.5, 21.99},
        {"Godzilla", 2000, 565.99}
    };
    
    cout << "Expand yout guest list with " << guests[0].name;
    cout << " and " << guests[1].name << endl;
    cout << guests[0].price + guests[1].price << endl;
    return 0;
    
}
