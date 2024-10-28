#include <iostream>

using namespace std;
template<typename T>
void print(T value); // 需要提前声明函数，否则报错

template<typename T, typename ...Ts>
void print(T value, Ts ... args){
    cout << value << endl;
    print(args...); // 需要存在递归终止条件
}

// 模板函数重载
template<typename T>
void print(T value){
    std::cout << value << std::endl;
}
int main(){
    print(1, "Hello World", 2.32);
    return 0;
}
