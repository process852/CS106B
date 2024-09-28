/*
The concept of a palindrome is often extended to full sentences by ignoring 
punctuation and differences in the case of letters. For example, the sentence
Madam, I’m Adam.
is a sentence palindrome, because if you only look at the letters and ignore any 
distinction between uppercase and lowercase letters, it reads identically 
backward and forward.
Write a predicate function isSentencePalindrome(str) that returns 
true if the string str fits this definition of a sentence palindrome. For 
example, you should be able to use your function to write a main program 
capable of producing the following sample run:
*/

#include <iostream>
#include <string>
#include <cctype>
using namespace std;

bool isSentencePalindrome(string str){
    int left = 0;
    int right = str.length() - 1;
    while (left < right){
        if(! isalpha(str[left])){
            left++;
            continue;
        }
        if(! isalpha(str[right])){
            right--;
            continue;
        }
        if(tolower(str[left]) != tolower(str[right]))
            return false;
        left++;
        right--;
    }
    return true;
}

int main(){
    cout << "This program tests for sentence palindromes." << endl;
    cout << "Indicate the end of the input with a blank line." << endl;
    string line;
    while(true){
        cout << "Enter a sentence: ";
        // cin >> line; // cin遇到空格、制表符以及换行符都会停止，不会读取整行数据
        getline(cin, line);
        if (line == "quit"){
            break;
        }
        else{
            if(isSentencePalindrome(line)){
                cout << "That sentence is a palindrom." << endl;
            }
            else{
                cout << "That sentence is not a palindrom." << endl;
            }
        }

    }
    return 0;
}