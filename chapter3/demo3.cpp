/*
Without using the built-in string method substr, implement a free function 
substr(str, pos, n) that returns the substring of str beginning at position 
pos and containing at most n characters. Make sure that your function 
correctly applies the following rules:
• If n is missing or greater than the length of the string, the substring should 
extend through the end of the original string.
• If pos is greater than the length of the string, substr should call error
with an appropriate message.
*/

#include <iostream>
#include <string>
using namespace std;

string my_substr(const string str, int pos, int n);
void test();

int main(){
    test();
    return 0;
}

string my_substr(const string str, int pos, int n = -1){
    int str_length = str.length();
    if (pos >= str_length){
        cerr << "The position is greater than string length" << endl;
    }
    if (n == -1){
        n = str_length - pos;
    }
    int index = 0;
    string new_string;
    for(; index + pos < str_length && index < n; index++){
        new_string += str[pos + index];
    }
    return new_string;
}
void test(){
    cout << my_substr("Hello", 0, 10) << endl;
    cout << my_substr("Hello", 10, 2) << endl;
    cout << my_substr("Hello", 1);
}