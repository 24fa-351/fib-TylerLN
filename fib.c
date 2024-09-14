#include <stdio.h>
#include <stdlib.h>


unsigned long long int i_memo_array[100000000];
unsigned long long int r_memo_array[100000000];


unsigned long long int FibIterative(int n) {
   if (i_memo_array[n] != 0) {
      return i_memo_array[n];
   }
   if (n == 1) {
      return 0;
   } else if (n == 2) {
      return 1;
   }
   unsigned long long int first = 0, second = 1, next_value;
   for (int i = 3; i <= n; i++) {
      next_value = first + second;
      first = second;
      second = next_value;
   }
   i_memo_array[n] = second;
   return second;
}


unsigned long long int FibRecursive(int n) {
   if (r_memo_array[n] != 0) {
      return r_memo_array[n];
   }
   if(n == 1){
      return 0;
   } else if (n == 2) {
      return 1;
   }
   r_memo_array[n] = FibRecursive(n-1) + FibRecursive(n-2);
   return r_memo_array[n];
}


unsigned long long int fib_i_wrapper(int n) {
   return FibIterative(n);
}
unsigned long long int fib_r_wrapper(int n) {
   return FibRecursive(n);
}


int main(int argc, char *argv[]) {
   int value = atoi(argv[1]);
   FILE *text_file = fopen(argv[3], "r");
   int file_value;
   fscanf(text_file, "%d", &file_value);
   fclose(text_file);


   int N = value + file_value;


   if (argv[2][0] == 'i') {
      unsigned long long int result = FibIterative(N);
      printf("%llu", result);
   } else if (argv[2][0] == 'r') {
      unsigned long long int result = FibRecursive(N);
      printf("%llu", result);
   }
   return 0;


}

