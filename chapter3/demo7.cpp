/*
Write a function
string replaceAll(string str, char c1, char c2);
that returns a copy of str with every occurrence of c1 replaced by c2. For 
example, calling
replaceAll("nannies", 'n', 'd');
should return "daddies".
Once you have coded and tested this function, write an overloaded version
string replaceAll(string str, string s1, string s2);
that replaces all instances of the string s1 with the replacement string s2.
*/
#include <iostream>
#include <string>
using namespace std;

string replaceAll(string str, char c1, char c2){
    for(int i = 0; i < str.length(); i++){
        if (str[i] == c1){
            str.replace(i, 1, string(1, c2));
        }
    }
    return str;
}
string replaceAll(string str, string s1, string s2){
    while(true){
        auto index = str.find(s1);
        if (index != string::npos){
            str.replace(index, s1.length(), s2);
        }
        else{
            return str;
        }
    }
}

void test(){
    cout << replaceAll("Hello", 'l', 'w') << endl;
    cout << replaceAll("Hello aa World aa", "aa", "ss") << endl;
}
int main(){
    test();
    return 0;
}