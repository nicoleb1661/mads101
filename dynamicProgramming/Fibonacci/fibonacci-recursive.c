#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

static unsigned long long num_recursive_calls = 0;
const int ERROR_STATUS = -1;
const int OK_STATUS = 0;

unsigned long long fibonacci(unsigned int n) {

  ++num_recursive_calls;
  
  if (n == 0 || n == 1) {
    return 1;
  }

  return fibonacci(n - 1) + fibonacci(n - 2);

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
  fprintf(stdout, "Fibonnaci[%d] = %ld.\n", n, fib);
  fprintf(stdout, "Computed with %ld recursive calls.\n",
	  num_recursive_calls);
  fprintf(stdout, "Elapsed time in seconds: %d\n",
	  end_time.tv_sec - start_time.tv_sec);
  
  exit(0);
}
