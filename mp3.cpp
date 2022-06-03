#include<stdio.h>
#include<omp.h>
int main()
{
	int numt;
	/*#pragma omp parallel
	{
		int tid=omp_get_thread_num();
		if(tid==0)
			numt=omp_get_num_threads();
		#pragma omp barrier
		printf("Total thread : %d  %d\n",tid,numt);
	}*/

// #pragma omp single master   : Only master thread execute
// #pragma omp single nowait  : no wait any thread execude
// #pragma omp single         : Only one thread execute
	#pragma omp parallel
	{
		int i;
		#pragma omp single     
		{                             
			for(i=0; i<10000; i++);   
		   numt=omp_get_num_threads();
		}
		for(i=0; i<10000; i++);
		int tid=omp_get_thread_num();
		printf("Total number of thread : %d  %d\n",tid,numt);
	}
	return 0;
}