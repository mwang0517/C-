#include <iostream>
#include "acctabc.h"
using std::cout;
using std::ios_base;
using std::endl;
using std::string;

//Abstract Base Class
AcctABC::AcctABC(const string & s, long an, double bal){
    fullName = s;
    acctNum = an;
    balance = bal;
}

AcctABC::Formatting AcctABC::SetFormat() const{       //protected methods for formatting
    Formatting f;
    f.flag = cout.setf(ios_base::fixed, ios_base::floatfield);
    f.pr = cout.precision(2);
}

void AcctABC::Restore(Formatting & f) const{
    cout.setf(f.flag, ios_base::floatfield);
    cout.precision(2);
}

void AcctABC::Deposit(double amt){
    if (amt < 0)
        cout << "Negative deposit not allowed; deposit is cancelled.\n";
    else
        balance += amt;
}

void AcctABC::Withdraw(double amt){
    balance -= amt;
}


//Brass Methods
void Brass::Withdraw(double amt){
    if (amt < 0)
        cout << "Withdraw money must be positive; withdraw cancelled.\n";
    else if (amt <= Balance())
        AcctABC::Withdraw(amt);
    else 
        cout << "With amount of $" << amt << " exceeds your balance.\n" << "Withdrawal canceled.\n";
}

void Brass::ViewAcct() const{
    Formatting f = SetFormat();
    cout << "Brass Client: " << FullName() << endl;
    cout << "Account Number: " << AcctNum() << endl;
    cout << "Balance: $ "<< Balance() << endl;
    Restore(f);
}

//BrassPlus Methods
BrassPlus::BrassPlus(const string & s, long an, double bal, double ml, double r): AcctABC(s, an, bal){
    maxLoan = ml;
    owesBank = 0.0;
    rate = r;
}

BrassPlus::BrassPlus(const Brass & ba, double ml, double r): AcctABC(ba){
    maxLoan = ml;
    owesBank = 0.0;
    rate = r;
}

void BrassPlus::ViewAcct() const{
    Formatting f = SetFormat();
    cout << "BrassPlus Client: " << FullName() << endl;
    cout << "Account Number: " << AcctNum() << endl;
    cout << "Balance: $ "<< Balance() << endl;
    cout << "Maximum loan: $" << maxLoan << endl;
    cout << "Owed to bank: $" << owesBank << endl;
    cout.precision(3);
    cout << "Loan Rate: " << 100 * rate << "%\n";
    Restore(f);
}

void BrassPlus::Withdraw(double amt){
    Formatting f = SetFormat();
    
    double bal = Balance();
    if (amt <= bal)
        AcctABC::Withdraw(amt);
    else if (amt <= bal + maxLoan - owesBank){
        double advance = amt - bal;
        owesBank += advance * (1.0 + rate);
        cout << "Bank advance: $" << advance << endl;
        cout << "Fiance charge: $" << advance * rate << endl;
        Deposit(advance);
        AcctABC::Withdraw(amt);
    }
    else
        cout << "Credit limit exceeded. Transaction cancelled.\n";
    Restore(f);
}