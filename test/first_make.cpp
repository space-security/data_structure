#include <iostream>
#include <thread>
#include "xdata.h"

using std::cin;
using std::cout;
using std::endl;
using std::thread;

void ThreadMain()
{
    cout << "Thread Main" << endl;
}

int main(int argc, char const *argv[])
{
    thread th(ThreadMain);
    cout << "This is my first test! " << endl;
    th.join();
    Xdata d;
    return 0;
}
