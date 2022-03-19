#include <iostream>
#include "seqQueue.hpp"
#include "linkQueue.hpp"

using std::cin;
using std::cout;
using std::endl;

int main(int argc, char const *argv[])
{
    // 以下是对seqQueue的测试
    seqQueue<int> seq(3);
    seq.enQueue(0);
    seq.enQueue(1);
    // cout << "size of queue is " << seq.getSize() << endl;
    seq.enQueue(2);
    seq.enQueue(3);
    seq.enQueue(4);
    
    int x = 0;
    seq.deQueue(x);
    seq.getFront(x);
    cout << "top " << x << endl;
    // seq.enQueue(3);
    cout << "number of data is " << seq.getSize() << endl;
    cout << "size of queue is " << seq.showQueueSize() << endl;

    /********************************************************/
    // 以下是对linkQueue的测试
    /*
    linkQueue<int> linkQ;
    linkQ.enQueue(10);
    linkQ.enQueue(20);
    linkQ.enQueue(30);
    linkQ.enQueue(40);
    int x = 0;
    linkQ.deQueue(x); // 出队，此时x=10，队列剩下20,30,40
    linkQ.getFront(x);//得到队首元素，队列剩下20，30,40
    cout << "front is " << x << endl;
    cout << linkQ << endl;
    */
    return 0;
}
