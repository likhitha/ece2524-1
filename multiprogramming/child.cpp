// This is file child.cpp
#include <sys/wait.h>
#include <iostream>
using namespace std;
int main(int argc, const char* argv[])
{
    cout << "Process[" << getpid() << "]: Child executing..." << endl;
    for (int i=0; i<argc; i++)      // print arguments
    {
	cout << argv[i] << endl;
    }
    for (int i=0; i<2000000000; i++) // busy loop
    {
    }
    cout << "Process[" << getpid() << "]: Child terminating." << endl;
    return 0;
}
