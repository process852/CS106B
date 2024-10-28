#include <iostream>
#include <type_traits>

using namespace std;

// 函数重载
void foo(char *){
    cout << "foo(char*) is called" << endl;
}

void foo(int){
    cout << "foo(int) is called" << endl;
}

int main(){
    // decltype 关键字用于类型推导
    // NULL 不同于 0、nullptr以及（void*) 0
    if(is_same<decltype(NULL), decltype(0)>::value){
        cout << "NULL == 0" << endl;
    }
    if(is_same<decltype(NULL), decltype((void*)0)>::value){
        cout << "NULL == (void*)0" << endl;
    }
    if(is_same<decltype(NULL), decltype(nullptr)>::value){
        cout << "NULL == nullptr" << endl;
    }

    foo(0);
    // NULL 不同编译器会定义为 0 或者 (void *) 0
    // foo(NULL); // 会引起重载函数的混乱
    foo(nullptr);
    return 0;
}

