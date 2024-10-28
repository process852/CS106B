#include <iostream>
#include <tuple>
#include <string>

using namespace std;

// initializer_list<type> 是类模板
void foo(initializer_list<int> x){
    for(auto it = x.begin(); it != x.end(); it++){
        cout << *it << endl;
    }
}

tuple<int, double, string> f(){
    return make_tuple(1, 2.3, "hello");
}

int main(){
    foo({1,2,3,4});
    auto [x, y, z] = f();
    cout << x << y << z << endl;
    return 0;
}