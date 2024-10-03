/*
The filelib.h interface exports several functions that make it easy to work
with filenames. Two functions that are particularly useful are getRoot and 
getExtension, which divide a function into its root, which is the identifying 
part of the filename, and the extension, which indicates its type. For example, 
given the filename Middlemarch.txt used in the preceding exercise, the 
root is Middlemarch and the extension is .txt (note that filelib.h defines 
the extension to includes the dot). Write the code necessary to implement 
these functions. To find out how to handle special cases, such as filenames 
that don’t include a dot, consult the filelib.h interface in Appendix A.
*/

#include <iostream>
#include <string>
using namespace std;

string getRoot(string fileName){
    int index = fileName.rfind('.');
    if (index == string::npos)
        cout << "error!" << endl;
    return fileName.substr(0, index);
}

string getExtension(string fileName){
    int index = fileName.rfind('.');
    if(index == string::npos)
        cout << "error !" << endl;
    return fileName.substr(index + 1, fileName.length() - index - 1);
}

int main(){
    string file("hello.txt");
    cout << getRoot(file) << endl;
    cout << getExtension(file) << endl;
    return 0;
}