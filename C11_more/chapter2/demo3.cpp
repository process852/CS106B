#include <iostream>
#include <string>

using namespace std;

// C11标准
template<typename T, typename U>
auto addC11(T x, U y) -> decltype(x+y){
    return x+y;
}

// C14标准
template<typename T, typename U>
auto addC14(T x, U y){
    return x+y;
}

int main(){
    cout << addC11(1, 2.33) << endl;
    cout << addC14(string("hello"), string(" world")) << endl;
    return 0;
}
