// This is file parent.cpp - update 2
#include <stdlib.h>
#include <sys/wait.h>
#include <iostream>
using namespace std;
int main()
{
    int pid = fork();
    if(pid == 0) 
    { 
	// this is the child process 
	execl("./child", "child", "red", "white", "blue", NULL);
	exit(0); // shouldn't ever get here
    }
   
    // parent process
    cout << "Process[" << getpid() << "]: Parent executing..." << endl;
    sleep(6); 
   
    if(kill(pid, SIGTERM) == 0)
	cout << "Process[" << getpid() << "]: Parent terminated child process..."
	     << endl;
   
    cout << "Process[" << getpid() << "]: Parent terminating." << endl;
    return 0;
}
