/*
判断字符串是否为回文串

*/

#include <iostream>
#include <string>
using namespace std;

bool isPalindrome1(string str){
    // recursion method
    int len = str.length();
    if(len <= 1)
        return true;
    else{
        // 每次需要拷贝字符串
        return str[0] == str[len - 1] && isPalindrome1(str.substr(1, len - 2));
    }
}

bool isPalindrome2(const string& str, int left, int right){
    // recursion method
    if(left >= right)
        return true;
    else{
        // 每次需要拷贝字符串
        return str[left] == str[right] && isPalindrome2(str, left + 1, right - 1);
    }
}

void test(){
    cout << isPalindrome1("level") << endl;
    cout << isPalindrome1("hello") << endl;

    cout << isPalindrome2("level", 0, 4) << endl;
    cout << isPalindrome2("hello", 0, 4) << endl;
}

int main(){
    test();
    return 0;
}