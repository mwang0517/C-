#include <iostream>
#include <string>
#include "brass.h"
const int CLIENTS = 4;

/*int main(){
    using std::cout;
    using std::endl;
    
    Brass Piggy("Porcelor Pigg", 381299, 4000.00);
    BrassPlus Hoggy("Horatio Hagg", 382288, 3000.00);
    Piggy.ViewAcct();
    cout << endl;
    Hoggy.ViewAcct();
    cout << endl;
    cout <<"Deposit $1000 into the Hogg Account:\n";
    Hoggy.Deposit(1000.00);
    cout << "New balance: $" << Hoggy.Balance() << endl;
    cout << "Withdrawing &4200 from the Pigg Accout:\n";
    Piggy.Withdraw(4200.00);
    cout << "Pigg accout balance: $" << Piggy.Balance() << endl;
    cout << "Withdrawing $4200 from the Hogg Account: \n";
    Hoggy.Withdraw(4200);
    Hoggy.ViewAcct();
    return 0;
}*/

int main(){
    using std::cin;
    using std::cout;
    using std::endl;
    
    Brass * p_clients[CLIENTS];
    std::string temp;
    long tempnum;
    double tempbal;
    char kind;
    
    for (int i = 0; i < CLIENTS; i++){
        cout << "Enter client's name: ";
        getline(cin, temp);
        cout << "Enter client's account number: ";
        cin >> tempnum;
        cout << "Enter opening balance: $ ";
        cin >>tempbal;
        cout << "Enter 1 for Brass Account or 2 for BrassPlus Account: ";
        while (cin >> kind && (kind != '1' && kind != '2')){
            cout << "Enter either 1 or 2: ";
        }
        if (kind == '1')
            p_clients[i] = new Brass(temp, tempnum, tempbal);
        else {
            double tmax, trate;
            cout << "Enter the overdraft limit: $";
            cin >> tmax;
            cout << "Enterthe interest rate as a decimal fraction: ";
            cin >> trate;
            p_clients[i] = new BrassPlus(temp, tempnum, tempbal, tmax, trate);
        }
        while (cin.get() != '\n')
            continue;
    }
    
    for (int i = 0; i < CLIENTS; i++){
        p_clients[i] -> ViewAcct();
        cout << endl;
    }
    
    for (int i = 0; i < CLIENTS; i++){
        delete p_clients[i];
    }
    cout << "Done.\n";
    return 0;
}

