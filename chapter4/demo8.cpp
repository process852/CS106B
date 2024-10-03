/*
Even though comments are essential for human readers, the compiler simply 
ignores them. If you are writing a compiler, you therefore need to be able to 
recognize and eliminate comments that occur in a source file.
Write a function
void removeComments(istream & is, ostream & os);
that copies characters from the input stream is to the output stream os, except 
for characters that appear inside C++ comments. Your implementation should 
recognize both comment conventions:
• Any text beginning with and ending with, possibly many lines later.
• Any text beginning with //and extending through the end of the line.
The real C++ compiler needs to check to make sure that these characters are 
not contained inside quoted strings, but you should feel free to ignore that 
detail. The problem is tricky enough as it stands.
*/

#include <iostream>
#include <string>
#include <fstream>
using namespace std;

void removeComments(istream & is, ostream & os){
    string line;
    bool flag = false;
    while(getline(is, line)){
        if (! flag){
            int index = line.find("/*");
            if (index != string::npos){
                os << line.substr(0, index);
                flag = true;
            }
            else{
                index = line.find("//");
                if (index != string::npos){
                    os << line.substr(0, index);
                }
                else{
                    os << line;
                }
            }
            os << endl;
        }
        else{
            int index = line.find("*/");
            if (index != string::npos){
                string leftString = line.substr(index + 2, line.length() - index - 2);
                index = leftString.find("//");
                os << leftString.substr(0, index);
                flag = false;
            }
            os << endl;
        }
        
    }
}
int main(){
    ifstream file("demo7.cpp");
    removeComments(file, cout);
    return 0;
}