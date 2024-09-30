/*
Write a function
int findDNAMatch(string s1, string s2, int start = 0);
that returns the first position at which the DNA strand s1 can attach to the 
strand s2. As in the find method for the string class, the optional start
parameter indicates the index position at which the search should start. If 
there is no match, findDNAMatch should return –1.
rule A <--> T  G <--> C
*/

#include <iostream>
#include <string>
using namespace std;

int findDNAMatch(string s1, string s2, int start = 0){
    if(start >= s2.length()){
        return -1;
    }
    for(int i = start; i < s2.length(); i++){
        bool flag = true;
        for(int j = 0; j < s1.length(); j++){
            if (i+j >= s2.length()){
                    return -1;
            }
            char c1 = s1[j];
            char c2 = s2[i + j];
            if (c1 == 'A' && c2 == 'T');
            else if (c1 == 'T' && c2 == 'A');
            else if (c1 == 'C' && c2 == 'G');
            else if (c1 == 'G' && c2 == 'C');
            else{
                flag = false;
                break;
            }
        }
        if (flag) return i;
    }
    return -1;
}

void test(){
    cout << findDNAMatch("TTGCC", "TAACGGTACGTC") << endl;
    cout << findDNAMatch("TGC", "TAACGCTACGTC") << endl;
}

int main(){
    test();
    return 0;
}