/*
Implement a function capitalize(str) that returns a string in which the
initial character is capitalized (if it is a letter) and all other letters are converted
to lowercase. Characters other than letters are not affected. For example, both
capitalize("BOOLEAN") and capitalize("boolean") should return
the string "Boolean".
*/

#include <iostream>
#include <string>
#include <cctype>
using namespace std;

string capitalize(string str);
void test();
int main()
{
    test();
    return 0;
}

string capitalize(string str)
{
    string new_str;
    for (int i = 0; i < str.length(); i++)
    {
        if (isalpha(str[i]))
        {
            if (i == 0)
            {
                new_str += toupper(str[i]);
            }
            else
            {
                new_str += tolower(str[i]);
            }
        }
        else
        {
            new_str += str[i];
        }
    }
    return new_str;
}

void test()
{
    cout << capitalize("hello") << endl;
    cout << capitalize("BOOLEN") << endl;
    cout << capitalize("alpha123") << endl;
}