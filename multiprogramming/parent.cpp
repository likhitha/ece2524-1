// This is file parent.cpp
#include <stdlib.h>
#include <sys/wait.h>
#include <iostream>
using namespace std;
int main()
{
    if(fork() == 0) 
    { 
	// this is the child process 
	execl("./child", "child", NULL);
	exit(0); // shouldn't ever get here
    }
     
    // parent process
    cout << "Process[" << getpid() << "]: Parent executing..." << endl;
    sleep(2); // wait two seconds
     
    if(wait(NULL) > 0)
	cout << "Process[" << getpid() << "]: Parent detects child terminating..."
	     << endl;
     
    cout << "Process[" << getpid() << "]: Parent terminating." << endl;
    return 0;
}
