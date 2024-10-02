/*
Write a program that prints the longest line in a file chosen by the user. If 
several lines are all equally long, your program should print the first such line.
*/

#include <iostream>
#include <string>
#include <fstream>
using namespace std;

string getFileName(){
    string path;
    while(true){
        cout << "Enter a file path: ";
        getline(cin, path);
        ifstream file(path);
        if (!file){
            cout << "The path is error!\n";
        }
        else{
            file.close();
            return path;
        }
    }
}
int main(){
    string name;
    string line, maxLine;
    int maxCount = 0;
    name = getFileName();
    ifstream file(name);
    while(getline(file, line)){
        if (line.length() >  maxCount){
            maxLine = line;
            maxCount = line.length();
        }
    }
    cout << maxLine << endl;
    return 0;
}
