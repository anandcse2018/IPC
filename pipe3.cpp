#include<iostream>
#include<unistd.h>
#include<sys/wait.h>
using namespace std;
int main()
{
	int a[]={1,2,3,4,5,6,7,8};
	int n=sizeof(a)/sizeof(int);
	int fd[2]; 
	pipe(fd);
	int start,end;
	int id=fork();
	if(id==0)
	{
		start=0;
		end=n/2;
	}
	else
	{
		start=n/2;
		end=n;
	}
	int sum=0; 
	for(int i=start; i<end; i++)
		sum+=a[i];
	cout<<"calculated partial sum : "<<sum<<endl;
	if(id==0)
		write(fd[1],&sum,sizeof(sum));
	else
	{
		int sum1;
		read(fd[0],&sum1,sizeof(sum1));
		cout<<"Total sum : "<<sum1+sum<<endl;
		wait(NULL);
	}
	return 0;
}