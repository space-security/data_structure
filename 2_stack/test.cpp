#include <iostream>
#include "seqStack.hpp"
#include "linkStack.hpp"

using std::cin;
using std::cout;
using std::endl;

int main(int argc, char const *argv[])
{
    /*检查顺序栈*/
    seqStack<int> a(3);
    a.Push(1);
    a.Push(10);
    a.Push(11);
    a.Push(212);
    cout << a.getSize() << endl;
    cout << a;

    /*检查链式栈*/
    linkStack<int> linkS;
    linkS.Push(10);
    linkS.Push(20);
    linkS.Push(30);
    linkS.Push(40);
    cout << "size: " << linkS.getSize() << endl;
    int x = 0;
    linkS.Pop(x);
    cout << "Pop(): " << x << endl;
    cout << "size: " << linkS.getSize() << endl;
    cout << linkS;
    return 0;
}
