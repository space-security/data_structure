#include <iostream>
#include <string>
#include "seqStack.hpp"
#include "linkStack.hpp"

using std::cin;
using std::cout;
using std::endl;
using std::string;

/** ERROR!!!!
 * 栈的应用一：括号匹配
 * 将有相对应括号匹配的括号的位置输出
 * 将字符串中的左括号一次放入栈中，碰到右括号即可匹配
 * 如果栈空，则右括号多余
 * 如果遍历后依旧有左括号，则左括号多余
 */
void printMatchedPairs(char *experience) {
    seqStack<int> linkS;
    int length = sizeof(experience) / sizeof(experience[0]);
    int j; // 用来保存左括号的位置
    for (int i = 0; i <= length; ++i) {
        if (experience[i] == '(') {
            linkS.Push(i);
        } else if (experience[i] == ')') {
            if (linkS.isEmpty() == false) {
                linkS.Pop(j);
                cout << j << "与" << i << "匹配" << endl;
            } else {
                cout << "没有和第" << i << "个符号匹配的左括号" << endl;
            }
        }
    }
    // 当栈中还有元素，说明之前push进来的左括号还有剩余
    while (linkS.isEmpty() == false) {
        linkS.Pop(j);
        cout << "没有与第" << j << "个左括号相匹配的右括号" << endl;
    }
}


int main(int argc, char *argv[])
{
    /** 检查顺序栈
    seqStack<int> a(3);
    a.Push(1);
    a.Push(10);
    a.Push(11);
    a.Push(212);
    cout << a.getSize() << endl;
    cout << a;
    */
    /** 检查链式栈
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
    */
   printMatchedPairs(argv[1]);

    return 0;
}
