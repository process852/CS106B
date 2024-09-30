/*
Most people—at least those in English-speaking countries—have played the
Pig Latin game at some point in their lives. There are, however, other 
invented “languages” in which words are created using some simple 
transformation of English. One such language is called Obenglobish, in which 
words are created by adding the letters ob before the vowels (a, e, i, o, and u) 
in an English word. For example, under this rule, the word english gets the 
letters ob added before the e and the i to form obenglobish, which is how the 
language gets its name.
In official Obenglobish, the ob characters are added only before vowels 
that are pronounced, which means that a word like game would become 
gobame rather than gobamobe because the final e is silent. While it is 
impossible to implement this rule perfectly, you can do a pretty good job by 
adopting the rule that the ob should be added before every vowel in the 
English word except
• Vowels that follow other vowels
• An e that occurs at the end of the word
Write a function obenglobish that takes an English word and returns its 
Obenglobish equivalent, using the translation rule given above. For example, 
if you used your function with the main program
int main() {
 while (true) {
 string word = getLine("Enter a word: ");
 if (word == "") break;
 string trans = obenglobish(word);
 cout << word << " -> " << trans << endl;
 }
 return 0;
}
you should be able to generate the following sample run:
*/

#include <iostream>
#include <string>
using namespace std;
bool endWithChar(string str, char c){
    int len = str.length();
    if (len == 0){
        return false;
    }
    else{
        return str[len - 1] == c ? true : false;
    }
}
bool isVowel(char c){
    const int length = 5;
    char arr[length] = {'a', 'e', 'i', 'o', 'u'};
    for(int i = 0; i < length; i++){
        if(c == arr[i]){
            return true;
        }
    }
    return false;
}
bool checkBeforeChar(string name, char c, int pos){
    if(pos == 0){
        return false;
    }
    else{
        if (isVowel(name[pos - 1])){
            return true;
        }
        return false;
    }
}
string obenglobish(string word){
    string new_word;
    for(int index = 0; index < word.length(); index++){
        if(index == word.length() - 1 && endWithChar(word, 'e')){
            new_word += word[index];
        }
        else{
            if (isVowel(word[index])){
                if(!checkBeforeChar(word, word[index], index)){
                    new_word += "ob";
                }
            }
            new_word += word[index];
        }
    }
    return new_word;
}


int main(){
    while(true){
        string word;
        cout << "Enter a word: ";
        getline(cin, word);
        if (word == "") break;
        string translate = obenglobish(word);
        cout << word << " -> " << translate << endl;

    }
    return 0;
}