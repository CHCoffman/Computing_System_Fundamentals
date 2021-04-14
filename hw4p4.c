#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#include <time.h>
#include <sys/time.h>

int main(int argc, char** argv){

struct timeval start, end;

	int array[1000000];
	int input = atoi(argv[1]);
	int count = 1000000;
	gettimeofday(&start, NULL);
	double itime, ftime, exec_time;
	itime = omp_get_wtime();
	#pragma omp_set_dynamic(0)
	#pragma omp_set_num_threads(input) //use this many threads
	#pragma omp parallel num_threads(input)
	{
		for(int i = 0; i < count; i++){
			array[i] = rand();
			for(int j = 1; j < 1001; j++){
			array[i] % j;
			}
		}
	printf("Threads: %u\n", omp_get_num_threads());
	}	
	gettimeofday(&end, NULL);
	//printf("threads%u\n",omp_get_num_threads());
	printf("time = %f seconds\n", (double)((end.tv_sec * 1000000 + end.tv_usec)- (start.tv_sec * 1000000 + start.tv_usec))/1000000);
	ftime = omp_get_wtime();
	exec_time = ftime - itime;
	exec_time = exec_time / input;
	printf("\nExecution Time per thread %f\n", exec_time);
return(0);
}
