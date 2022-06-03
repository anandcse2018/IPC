#include<iostream>
#include<unistd.h>
#include<sys/wait.h>
using namespace std;
int main()
{
	int fd[2];
	if(pipe(fd)==-1)
		cout<<"An error occured with opening the pipe"<<endl;
	int id=fork();
	if(id==0)
	{
		close(fd[0]);
		int x;
		cout<<"child process > Enter the Number : ";
		cin>>x;
		if(write(fd[1],&x,sizeof(x))==-1) 
			cout<<"An error occured writing in the pipe"<<endl;
		close(fd[1]);
	}
	else
	{
		close(fd[1]);
		int y;
		if(read(fd[0],&y,sizeof(y))==-1)
			cout<<"An error occured reading the pipe"<<endl;
		close(fd[0]);
		cout<<"parent process > Got from child process : "<<y<<endl;
	}
	return 0;
}