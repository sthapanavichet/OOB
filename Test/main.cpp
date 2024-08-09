

#include <iostream>
#include <stdlib.h>
using namespace std;
template<class T, class U>
class A
{
    T x;
    U y;
};
template<typename T> T maximum(T x, T y)
{
    return (x > y)? x : y;
}
int main() {
//    A<char, char> a;
//    A<int, int> b;
//    cout << sizeof(a) << endl << sizeof(b) << endl;
    cout << maximum(3, 7) << std::endl;
    cout << maximum(3.0, 7.0) << std::endl;
    cout << maximum(3, 7.0) << std::endl;
    return 0;
}