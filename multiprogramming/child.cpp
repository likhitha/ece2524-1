// This is file child.cpp - update 2
#include <sys/wait.h>
#include <iostream>
using namespace std;

void signal_handler(int signo)
{
    if (signo == SIGTERM)
	cerr << "Process[" << getpid() << "]: Child received SIGTERM." << endl;
}

int main(int argc, char *argv[])
{
    cout << "Process[" << getpid() << "]: Child executing..." << endl;
    if (signal(SIGTERM, signal_handler) == SIG_ERR)
	cerr << "Can't catch SIGTERM" << endl;
    if (signal(SIGKILL, signal_handler) == SIG_ERR)
	cerr << "Can't catch SIGKILL" << endl;
    for (int i=0; i<argc; i++)      // print arguments
    {
	cout << argv[i] << endl;
    }
    while(1) // busy loop
    {
    }
    cout << "Process[" << getpid() << "]: Child terminating." << endl;
    return 0;
}
