// ASAN_Appliction.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>
using namespace std;

int main()
{
    /// 1. heap-buffer-overflow
    char* heap_buf = new char[32];
    memcpy(heap_buf + 30, "heapbuffer", 10);
    delete[] heap_buf;

    /// 2. heap-use-after-free
    char* x = new char[10];
    delete[](x);
    int n = x[5];

    /// 3. new-delete-type-mismatch
    auto ndtm = []() -> void {
        struct Base {};
        struct Derived : public Base {
            int t;
        };

        Base* b = new Derived;
        delete b;
    };
    ndtm();

    system("pause");
}