#include<stdio.h>
#include<omp.h>    // prototype of open mp function
int main()
{
    int tid,numt;           // shared variable
   // numt=omp_get_num_threads();  // only one master thread
    #pragma omp parallel private(tid) //compiler directive
    {
       int i;
       if(tid==0)
       {
        numt=omp_get_num_threads();   // this function give total number of thraed
       for(i=0; i<10000; i++);       // using for dealay
       }
    }
    #pragma omp parallel private(tid) //shared(numt) // compiler directive
    {   
       //printf("anand Maurya\n");         // printed number of thread time
       tid=omp_get_thread_num();     // this function give thread ID
       printf("Total Number of Thread : %d  %d\n",tid,numt);
    }
          
    /*#pragma omp parallel
    {
        int numt=omp_get_num_threads();  
        int tid=omp_get_thread_num();
        printf("Total Number of Thread : %d  %d\n",tid,numt);
    }*/
    return 0;
}