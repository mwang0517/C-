#include "worker1.h"
#include <iostream>
using std::cout;
using std::cin;
using std::endl;

//--------------Worker Method--------------
Worker::~Worker(){} //must implement virtual destructor, even if pure.

//Protected Methods
void Worker::Data() const{
    cout << "Name: " << fullname << "\n";
    cout << "Employee ID: " << id << "\n";
}

void Worker::Get(){
    cout << "Enter worker's name: ";
    getline(cin, fullname);
    cout << "Enter worker's ID: ";
    cin >> id;
    while (cin.get()!= '\n')
        continue;
}

//--------------Waiter Methods--------------

//Protected Methods
void Waiter::Data() const{
    cout << "Panache rating: " << panache << endl;
}

void Waiter::Get(){
    cout << "Enter waiter's panache rating: ";
    cin >> panache;
    while (cin.get()!='\n')
        continue;
}

void Waiter::Set(){
    cout << "Enter waiter's name: ";
    Worker::Get();
    Get(); 
}

void Waiter::Show() const{
    cout << "Category: waiter\n";
    Worker::Data();
    Data();
}


//--------------Singer Methods--------------
char * Singer::pv[] = {"other", "alto", "contralto", "soprano", "bass", "baritone", "tenor"};

//Protected Methods
void Singer::Data() const{
    cout << "Vocal range: " << pv[voice] << endl;
}

void Singer::Get(){
    cout << "Enter number for singer's vocal range:\n";
    int i;
    for (i=0; i<Vtypes; i++){
        cout << i << ": " << pv[i] << " ";
        if (i % 4 == 3)
            cout << endl;
    }
    if (i % 4 != 0)
        cout << endl;
    while (cin >> voice && (voice < 0 || voice >= Vtypes))
        cout << "Please enter a value >= 0 and < " << Vtypes << endl;
    while (cin.get() != '\n')
        continue;
}

void Singer::Set(){
    cout << "Enter singer's name: ";
    Worker::Get();
    Get();
}

void Singer::Show() const{
    cout << "Category: Singer\n";
    Worker::Data();
    Data();
}

//--------------SingingWaiter Methods--------------

//Protected Methods
void SingingWaiter::Data() const{
    Singer::Data();
    Waiter::Data();
}

void SingingWaiter::Get(){
    Waiter::Get();
    Singer::Get();
}

void SingingWaiter::Set(){
    cout << "Enter singing waiter's name: ";
    Worker::Get();
    Get();
}

void SingingWaiter::Show() const{
    cout << "Category: singingwaiter\n";
    Worker::Data();
    Data();
}