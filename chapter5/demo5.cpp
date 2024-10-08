/*
In the third century B.C.E., the Greek astronomer Eratosthenes developed an 
algorithm for finding all the prime numbers up to some upper limit N. To 
apply the algorithm, you start by writing down a list of the integers between 2 
and N. For example, if N were 20, you would begin by writing the following 
list:
You then circle the first number in the list, indicating that you have found a 
prime. Whenever you mark a number as a prime, you go through the rest of 
the list and cross off every multiple of that number, since none of those 
multiples can itself be prime. Thus, after executing the first cycle of the 
algorithm, you will have circled the number 2 and crossed off every multiple 
of 2, as follows:
To complete the algorithm, you simply repeat the process by circling the 
first number in the list that is neither crossed off nor circled, and then crossing 
off its multiples. In this example, you would circle 3 as a prime and cross off 
all multiples of 3 in the rest of the list, which results in the following state:
Eventually, every number in the list will either be circled or crossed out, as 
shown in this diagram:
The circled numbers are the primes; the crossed-out numbers are composites. 
This algorithm is called the sieve of Eratosthenes.
Write a program that uses the sieve of Eratosthenes to generate a list of the 
primes between 2 and 1000.
*/

#include <iostream>
#include <vector>
using namespace std;

vector<int> getPrime(int start, int end){
    vector<bool> flag(end - start + 1, true);
    vector<int> data;

    for(int i = start; i <= end; i++){
        if(flag[i - start]){
            int n = i + 1;
            while(n <= end){
                if(n % i == 0)
                    flag.at(n - 2) = false;
                n++;
            }
        }
    }
    for(int i = 0; i < flag.size(); i++){
        if (flag[i]){
            data.push_back(i + start);
        }
    }
    return data;
}

ostream& showVector(ostream& out, vector<int>& data){
    out << "[";
    for(int i = 0; i < data.size(); i++){
        out << data.at(i);
        if(i != data.size() -1){
            cout << ", ";
        }
    }
    out << "]" << endl;
    return out;
}

int main(){
    vector<int> primes = getPrime(2, 1000);
    showVector(cout, primes);
    return 0;

}