#include<stdio.h>
#include "omp.h"
#define NUM_THREADS 10

int main()
{
	omp_set_num_threads(NUM_THREADS);
#pragma omp parallel
  {
  int ID =omp_get_thread_num();
  printf("Procesadores(%d)\n",ID);
  printf("Multiples(%d)\n",ID);
  printf("en accion(%d)\n",ID);
  }
}
