/*
Write a program that checks whether the bracketing operators (parentheses, 
brackets, and curly braces) in a string are properly matched. As an example of 
proper matching, consider the string
{ s = 2 * (a[2] + 3); x = (1 + (2)); }
If you go through the string carefully, you discover that all the bracketing 
operators are correctly nested, with each open parenthesis matched by a close 
parenthesis, each open bracket matched by a close bracket, and so on. On the 
other hand, the following strings are all unbalanced for the reasons indicated:
(([]) The line is missing a close parenthesis.
)( The close parenthesis comes before the open parenthesis.
{(}) The bracketing operators are improperly nested.
*/

#include <iostream>
#include <stack>
#include <vector>

using namespace std;

bool bracketMatch(string str){
    stack<char> charStack;
    for(int index = 0; index < str.length(); index++){
        char c = str.at(index);
        if(c == '(')
            charStack.push(c);
        else if (c == '{')
            charStack.push(c);
        else if (c == ')'){
            if (charStack.top() != '(')
                return false;
            charStack.pop();
        }
        else if (c == '}'){
            if (charStack.top() != '{')
                return false;
            charStack.pop();
        }
        else
            ;
    }
    return charStack.size() ? false : true;
}

int main(){
    cout << bracketMatch("{ s = 2 * (a[2] + 3); x = (1 + (2)); }") << endl;
    cout << bracketMatch("(([])") << endl;
    return 0;
}
