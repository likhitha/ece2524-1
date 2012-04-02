// This is file child.cpp
#include <sys/wait.h>
#include <iostream>
using namespace std;
int main()
{
    cout << "Process[" << getpid() << "]: Child executing..." << endl;
    sleep(1);
    cout << "Process[" << getpid() << "]: Child terminating." << endl;
    return 0;
}
