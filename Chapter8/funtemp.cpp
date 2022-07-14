//8.11
#include <iostream>

template <typename T>
void Swap(T &a, T &b);

int main(){
    using namespace std;
    int i = 10;
    int j = 20;
    cout << "i, j = " << i << ", " << j << ".\n";
    cout << "Using compiler-generated int swapper:\n";
    Swap(i, j);
    cout << "Now i, j = " << i << ", " << j << ".\n";
    return 0;
}

template <typename T>
void Swap(T &a, T &b){
    T temp;
    temp = a;
    a = b;
    b = temp;
}