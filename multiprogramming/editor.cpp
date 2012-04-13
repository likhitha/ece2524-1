#include <stdlib.h>
#include <stdio.h>
#include <cstdio>
#include <unistd.h>
#include <iostream>
#include <string>
#include <readline/readline.h>
#include <boost/algorithm/string.hpp>


using namespace std;
using namespace boost::algorithm;

std::string get_string_from_user(const char* prompt)
{
    char* userinput = readline(prompt);
    string userstring(userinput);
    trim(userstring);
    return userstring;
}

void file_copy(std::string filename, int fd)
{
    /* copy the contents of a file given by filename to a file descriptor fd */
    char *mystring = NULL;
    size_t num_bytes = 0;

    FILE* input = fopen(filename.c_str(), "r");
    FILE* towc = fdopen(fd, "w");
    while (getline(&mystring, &num_bytes, input) > 0)
	fputs(mystring, towc);
    fclose(towc);
    fclose(input);
}

int main(int argc, const char* argv[])
{
    bool verbose = true;

    char *pEditor;
    pEditor = getenv("EDITOR");
    if (pEditor==NULL)
    {
	cerr << "EDITOR environment variable not set." << endl;
	exit(1);
    };

    string filename = get_string_from_user("Enter a file name to edit: ");

    string command("$EDITOR ");
    command.append(filename);
    
    if (verbose)
	cerr << "Invoking editor defined by $EDITOR and opening file " << filename << "." << endl;

    int ret = system(command.c_str());
    if (verbose)
	cerr << "Returning from editor with return code " << ret << endl;
    
    int fd[4];
    pipe(fd);
    pipe(fd+2);
    pid_t pid = fork();

    if (pid == 0)
    {
	/* child process */
	if (verbose)
	    cerr << "exec'ing wc with " << filename << " as input." << endl;
	close(fd[0]);
	dup2(fd[1], 1);
	close(fd[3]);
	dup2(fd[2],0);
	execlp("wc", "wc", "-w", NULL);
	perror("execlp");
	exit(1);
    } else if (pid < 0) {
	perror("fork");
	exit(1);
    } else {
	/* parent process */
	char *mystring = NULL;
	size_t num_bytes = 0;

	close(fd[1]);
	close(fd[2]);

	file_copy(filename,fd[3]);

	FILE* fromwc = fdopen(fd[0], "r");
	getline(&mystring, &num_bytes, fromwc);
	int word_count = atoi(mystring);
	cout << "File " << filename << " contains " << word_count << " words." << endl;
	fclose(fromwc);
	close(fd[0]);
    }
    return EXIT_SUCCESS;
}
