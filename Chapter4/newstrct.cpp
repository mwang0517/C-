//4.21
#include <iostream>

struct inflatable{
    char name[20];
    float volume;
    double price;
};

int main() {
    using namespace std;
    inflatable *ps = new inflatable;;
    cout << "Enter name of inflatable item: ";
    cin.get(ps->name, 20); //method 1 for member acccess
    cout << "Enter volume in cubic feet: ";
    cin >> (*ps).volume; //method 2 for member access
    cout << "Enter price: &";
    cin >> ps->price;
    cout << "Name: " << (*ps).name << endl;
    cout << "Volume: " <<  ps->volume << " cubic feet\n";
    cout << "Price: & " << ps->price << endl;
    delete ps;
    
    return 0;
    
}
