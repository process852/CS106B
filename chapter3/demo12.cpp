/*
As an example, 
suppose that you wanted to encode a message by shifting every letter ahead 
three places. In this cipher, each A becomes an D, B becomes E, and so on. If 
you reach the end of the alphabet, the process cycles around to the beginning, 
so that X becomes A, Y becomes B, and Z becomes C.
To implement a Caesar cipher, you should first define a function
string encodeCaesarCipher(string str, int shift);
that returns a new string formed by shifting every letter in str forward the 
number of letters indicated by shift, cycling back to the beginning of the
alphabet if necessary. After you have implemented encodeCaesarCipher, 
write a program that generates the following sample run:
Note that the transformation applies only to letters; any other characters are
copied unchanged to the output. Moreover, the case of letters is unaffected: 
lowercase letters come out as lowercase, and uppercase letters come out as 
uppercase. You should also write your program so that a negative value of 
shift means that letters are shifted toward the beginning of the alphabet 
instead of toward the end, as illustrated by the following sample run:
*/

#include <iostream>
#include <string>
#include <cctype>
#include <limits>
using namespace std;

string encodeCaesarCipher(string str, int shift){
    // TODO shift alpha cycle
    // a- 50       z 76
    char lowerAlpha[26];
    char upperAlpha[26];
    string new_string;
    for(int i = 0; i < 26; i++){
        lowerAlpha[i] = 'a' + i;
    }
    for(int i = 0; i < 26; i++){
        upperAlpha[i] = 'A' + i;
    }
    if (shift == 0){
        return str;
    }
    else{
        // convert shift < 0 to shift > 0
        shift = shift > 0 ? shift % 26 : (shift % 26) + 26;
        for(int i = 0; i < str.length(); i++){
            char c = str[i];
            if(isalpha(c)){
                if (c >= 'a' && c <= 'z'){
                    // lower alpha
                    int index = ((c - 'a') + shift) % 26;
                    c = lowerAlpha[index];
                }
                else if (c >= 'A' && c <= 'Z'){
                    int index = ((c - 'A') + shift) % 26;
                    c = upperAlpha[index];
                }
            }
            new_string += c;
        }
    }
    return new_string;
}

int main(){
    cout << "This program encodes a message using Caesar cipher." << endl;
    while(true){
        string line;
        int shift;
        cout << "Enter a number of character positions to shift: ";
        cin >> shift; // 不会读取换行符
        cout << "Enter a message: ";
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // clear cache
        // getline 会读取 cin 丢弃的换行符，所以需要清空缓存
        getline(cin, line);
        if(line == "") break;
        cout << "Encoded message: " << encodeCaesarCipher(line, shift) << endl;
    }
    return 0;
}
