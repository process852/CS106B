/*
Although they are certainly simple, Caesar ciphers are also extremely easy to 
break. There are, after all, only 25 values for the number of characters to shift. 
If you want to break a Caesar cipher, all you have to do is try each of the 25 
possibilities and see which one translates the original message into something 
readable. A better scheme is to allow each letter in the original message to be 
represented by an arbitrary letter instead of one a fixed distance from the 
original. In this case, the key for the encoding operation is a translation table 
that shows what each of the 26 letters becomes in the encrypted form. Such a 
coding scheme is called a letter-substitution cipher.
The key in a letter-substitution cipher is a 26-character string that indicates 
the translation for each character in the alphabet in order. For example, the 
key "QWERTYUIOPASDFGHJKLZXCVBNM" indicates that the encoding process 
should use the following translation rule:
Write a program that implements encryption using a letter-substitution 
cipher. Your program should be able to duplicate the following sample run:
*/

#include <iostream>
#include <string>
#include <cctype>
#include <limits>
using namespace std;

string encodeCaesarCipher(string word, string key){
    char lower_case[26];
    char upper_case[26];
    string new_string;
    if(key.length() != 26){
        return "error";
    }

    for(int i = 0; i < 26; i++){
        lower_case[i] = tolower(key[i]);
        upper_case[i] = toupper(key[i]);
    }

    for(int i = 0; i < word.length(); i++){
        char c = word[i];
        if(isalpha(c)){
            if(c >= 'a' && c <= 'z'){
                new_string += lower_case[c - 'a'];
            }
            else if (c >= 'A' && c <= 'Z'){
                new_string += upper_case[c - 'A'];
            }
        }
        else{
            new_string += c;
        }
    }
    return new_string;
}

int main(){
    cout << "This program encodes a message using Caesar cipher." << endl;
    while(true){
        string line;
        string key;
        cout << "Enter a 26-letter key: ";
        getline(cin, key); // 会读取换行符
        cout << "Enter a message: ";
        getline(cin, line);
        if(key == "") break;
        cout << "Encoded message: " << encodeCaesarCipher(line, key) << endl;
    }
    return 0;
}
