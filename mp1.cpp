#include<iostream>
#include<omp.h>
using namespace std;
int main()
{
	int a[5]={1,2,3,4,5};
	int b[5]={1,2,3,4,5};
	int c[5];
/*	#pragma omp parallel num_threads(4)
	{
		int t;
		t=omp_get_thread_num();
		c[t]=a[t]+b[t];
		printf("c[%d] = %d\n",t,c[t]);
	} */ 
	cout<<endl;
	#pragma omp parallel for num_threads(5)
		for(int i=0; i<5; i++)
		{
		  int t=omp_get_thread_num();
		  c[t]=a[t]+b[t];
		  printf("c[%d] = %d\n",t,c[t]);
		} 
}

// $g++ -fopenmp mp1.cpp