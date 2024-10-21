/*
Write a program that uses a stack to reverse a sequence of integers read from 
the console one number per line, as shown in the following sample run:
*/
#include <iostream>
#include <stack>
#include <iomanip>

using namespace std;

int main(){
    stack<int> s;
    cout << "Enter a list of integers, ending with 0:" << endl;
    while(true){
        int number;
        cin >> number;
        if(number == 0)
            break;
        s.push(number); // put number in stack
    }

    cout << "Those integers in reverse order are: " << endl;
    while(s.size()){
        cout << setw(6) << left << s.top() << endl; // 返回栈顶元素
        s.pop(); // 弹出元素
    }
    return 0;

}