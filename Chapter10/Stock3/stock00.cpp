#include <iostream>
#include "stock00.h"

Stock::Stock(){
    std::cout << "Defautl constructors called.\n";
    company = "no name";
    shares = 0;
    share_val = 0.0;
    total_val = 0.0;
}

Stock::Stock(const std::string & co, long n, double pr){
    std::cout << "Constructor using " << co << " called.\n";
    company = co;
    if (n<0) {
        std::cout << "Constructor using " << co << " called.\n";
        shares = 0;
    }
    else
        shares = n;
    share_val = pr;
    set_tot();
}

Stock::~Stock(){
    std::cout << "Bye, " << company << "\n";
}

void Stock::acquire(const std::string & co, long n, double pr){
    company = co;
    if (n<0) {
        std::cout << "Number of shares cannot be negative: "
                << company << " shares set to 0.\n";
        shares = 0;
    } else
        shares = n;
    share_val = pr;
    set_tot();
}

void Stock::buy(long num, double price){
    if (num<0) {
        std::cout << "Number of shares purchased cannot be negative. "
                  << "Transaction is aborted.\n";
    }
    else {
        shares += num;
        share_val = price;
        set_tot();
    }
}

void Stock::sell(long num, double price){
    using std::cout;
    if (num<0) {
        cout << "Number of shares sold cannot be negative. "
            << "Transaction is aborted.\n";
    }
    else if(num > shares) {
        cout << "You cannot sell more than you have! "
            << "Transaction is aborted.\n";
    } else {
        shares -= num;
        share_val = price;
        set_tot();
    }
}

void Stock::update(double price){
    share_val = price;
    set_tot();
}

void Stock::show() const{
    using std::cout;
    using std::ios_base;
    ios_base::fmtflags orig = cout.setf(ios_base::fixed, ios_base::floatfield);
    std::streamsize prec = cout.precision(3);
    std::cout << "Company: " << company
            << " Shares: " << shares << '\n'
            << " Share Price: $" << share_val
            << " Total Worth: $" << total_val << '\n';
}

const Stock & Stock::topval(const Stock & s) const{
    if (s.total_val > total_val)
        return s;
    else
        return *this; 
}