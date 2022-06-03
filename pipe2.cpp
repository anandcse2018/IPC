#include<iostream>
#include<unistd.h>
#include<sys/wait.h>
#include<time.h>
using namespace std;
int main()
{
	int p1[2];   // C->P
    int p2[2];   // P->C
	pipe(p1);
	pipe(p2);
	int id=fork();
	if(id==0)
	{
		close(p1[0]);
		close(p2[1]);
		int x;
	    read(p2[0],&x,sizeof(x));
		cout<<"read by child : "<<x<<endl; cout<<endl;
		x*=4;
		write(p1[1],&x,sizeof(x)); 
		cout<<"written by child : "<<x<<endl;
		close(p1[1]);
		close(p2[0]);
	}
	else
	{
		close(p1[1]);
		close(p2[0]);
		srand(time(NULL));
		int y=rand()%10;
		write(p2[1],&y,sizeof(y));
		cout<<"written by parent : "<<y<<endl;
		read(p1[0],&y,sizeof(y));
		cout<<"read by parent : "<<y<<endl;
		close(p1[0]);
		close(p2[1]);
		wait(NULL);
	}
	return 0;
}