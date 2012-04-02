// This is file child.cpp - update 2
#include <stdlib.h>
#include <sys/wait.h>
#include <iostream>
using namespace std;

bool forever = true;

void signal_handler(int signo)
{
    if (signo == SIGTERM)
	cerr << "Process[" << getpid() << "]: Child received SIGTERM." << endl;
    forever = false;
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
    while(forever) // busy loop
    {
    }

    cout << "Process[" << getpid() << "]: Child terminating." << endl;
    return 0;
}
