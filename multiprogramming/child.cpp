// This is file child.cpp - update 2
#include <sys/wait.h>
#include <iostream>
using namespace std;
int main(int argc, char *argv[])
{
    int i;
   
    cout << "Process[" << getpid() << "]: Child executing..." << endl;
    for (i=0; i<argc; i++)      // print arguments
    {
	cout << argv[i] << endl;
    }
    while(1) // busy loop
    {
    }
    cout << "Process[" << getpid() << "]: Child terminating." << endl;
    return 0;
}
