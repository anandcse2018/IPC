#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/shm.h>
#include<string.h>
int main()
{ 
int shmid=shmget(2345, 1024, 0666|IPC_CREAT); 
printf("Key of shared memory is %d\n",shmid);
char *shared_memory=(char *)shmat(shmid,NULL,0); 
printf("Process attached at %p\n",shared_memory); 
printf("write data in to shared memory : ");
scanf("%[^\n]%*c", shared_memory);
printf("You wrote : %s\n",shared_memory);
shmdt(shared_memory);
printf("\n");
return 0;
}