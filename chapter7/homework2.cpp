/*
Unlike many programming languages, C++ does not include a predefined 
operator that raises a number to a power. As a partial remedy for this 
deficiency, write a recursive implementation of a function
int raiseToPower(int n, int k)
that calculates n
k
. The recursive insight that you need to solve this problem is 
the mathematical property that
*/

#include <iostream>
using namespace std;

int raiseToPower(int n, int k){
    if(k == 0)
        return 1;
    else{
        return n * raiseToPower(n, k - 1);
    }
}

int main()
{
    cout << raiseToPower(2, 3) << endl;
    cout << raiseToPower(3, 4) << endl;
    return 0;
}