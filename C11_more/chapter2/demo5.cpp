#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    vector<int> vec = {1,2,3,4};
    if(auto itr = find(vec.begin(), vec.end(), 3); itr != vec.end())
        *itr = 4;
    for(auto element : vec) // 改变的是拷贝值
        cout << element << endl;

    for (auto &element : vec) // 改变原值
        element += 1;
    
    for(auto element : vec)
        cout << element << endl;
    return 0;
}