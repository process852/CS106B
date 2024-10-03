/*
Another useful function in filelib.h is
string defaultExtension(string filename, string ext);
which adds ext to the end of filename if it doesn’t already have an 
extension. For example,
defaultExtension("Shakespeare", ".txt")
would return "Shakespeare.txt". If filename already has an extension, 
that name is returned unchanged, so that
defaultExtension("library.h", ".cpp")
would ignore the specified extension and return "library.h" unchanged. If, 
however, ext includes a star before the dot, defaultExtension removes
any existing extension from filename and adds the new one (minus the star). 
Thus,
defaultExtension("library.h", "*.cpp")
would return "library.cpp". Write the code for defaultExtension so 
that it behaves as described in this exercise.
*/

#include <iostream>
#include <string>
using namespace std;

bool startWith(string str, char c){
    if (str[0] == c)
        return true;
    return false;
}
int findPoint(string str){
    int index = str.length() - 1;
    for(; index >= 0; index--){
        if(str[index] == '.')
            return index;
    }
    return index;
}
string defaultExtension(string file, string ext){
    // check start with '*'
    bool flag = startWith(ext, '*');
    if(flag){
        int index = findPoint(file);
        if (index < 0){
            return file + ext.substr(1, ext.length() - 1);
        }
        else{
            return file.substr(0, index) + ext.substr(1, ext.length() - 1);
        }
    }
    else{
        int index = findPoint(file);
        if (index < 0){
            return file + ext;
        } 
        else{
            return file;
        }
    }

}

void test(){
    cout << defaultExtension("Shakespeare", ".txt") << endl;
    cout << defaultExtension("library.h", ".cpp") << endl;
    cout << defaultExtension("library.h", "*.cpp") << endl;
}
int main(){
    test();
    return 0;
}