#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

// Linear time O(n) and constant memory O(1)

unsigned long long memory_required;
const int ERROR_STATUS = -1;
const int OK_STATUS = 0;

unsigned long long fibonacci(unsigned int n) {

  // Note that due to the function set up we do not need
  // special cases.
  unsigned long long fibs_n_1 = 1;
  unsigned long long fibs_n_2 = 1;
  memory_required = sizeof(fibs_n_1) + sizeof(fibs_n_2);
  for (unsigned int i = 2; i <= n; i++) {
    unsigned long long tmp = fibs_n_1;
    fibs_n_1 = fibs_n_1 + fibs_n_2;
    fibs_n_2 = tmp;
  }
  return fibs_n_1;
}

int main(int argc, char *argv[]) {

  if (argc < 2) {
    fprintf(stderr, "ERROR: provide the number to find fibonnaci!\n");
    exit(-1);
  }
  int n = atoi(argv[1]);
  struct timeval start_time;
  gettimeofday(&start_time, NULL);
  unsigned long long fib = fibonacci(n); 
  struct timeval end_time;
  gettimeofday(&end_time, NULL);
  fprintf(stdout, "Fibonnaci[%d] = %lld.\n", n, fib);
  fprintf(stdout, "Computed with %ld bytes of memory.\n",
	  memory_required);
  fprintf(stdout, "Elapsed time in seconds: %d\n",
	  end_time.tv_sec - start_time.tv_sec);
  
  exit(OK_STATUS);
}
