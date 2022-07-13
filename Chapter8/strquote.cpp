//8.7
#include <iostream>
#include <string>
using namespace std;

string version1 (const string & s1, const string & s2);
const string & version2(string & s1, const string & s2); //has side effect
const string & version3(string & s1, const string & s2); //bad design

int main(){
    string input;
    string copy;
    string result;
    
    cout << "Enter a string: ";
    getline(cin, input);
    copy = input;
    cout << "Your string as entered: " << input << endl;
    result = version1(input, "***");
    cout << "Your string enhanced: " << result << endl;
    cout << "Your original string: " << input << endl;
    
    result = version2(input, "###");
    cout << "Your string enhanced: " << result << endl;
    cout << "Your original string: " << input << endl;
    
    cout << "Resetting original string.\n";
    input = copy;
    result = version3(input, "@@@");
    cout << "Your string enhanced: " << result << endl;
    cout << "Your original string: " << input << endl;
    return 0;
    
}

//使用引用效率更高，因为函数不需要创建新的string对象
//const说明该函数将使用原来的string对象，但不会修改它
//temp是一个新的string对象，只在函数中有效，该函数执行完毕后，它不再存在
//因此返回指向temp的引用是不可行的，因此函数返回类型为string
//这意味着temp的内容被临时复制到一个临时的存储单元中，然后在main()中，
//该存储单元的内容被复制到一个名为result的string中
string version1(const string & s1, const string & s2){
    string temp;
    temp = s2 + s1 + s2;
    return temp;
}

const string & version2(string & s1, const string & s2){
    s1 = s2 + s1 + s2;
    return s1; // safe to return reference passed to function
}

const string & version3(string & s1, const string & s2){
    string temp;
    temp = s2 + s1 + s2;
    return temp; //unsafe to return reference to local variable
}