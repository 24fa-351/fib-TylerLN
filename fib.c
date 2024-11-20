#include <stdio.h>
#include <stdlib.h>

int fib_iterative(int fib_index) {
  if (fib_index == 1) {
    return 0;
  } else if (fib_index == 2) {
    return 1;
  }
  int first = 0;
  int second = 1;
  int next_value;

  for (int ix = 3; ix <= fib_index; ix++) {
    next_value = first + second;
    first = second;
    second = next_value;
  }
  return second;
}

int fib_recursive(int recursive_index) {
  if (recursive_index == 1) {
    return 0;
  } else if (recursive_index == 2) {
    return 1;
  } else {
    return (fib_recursive(recursive_index - 1) + fib_recursive(recursive_index - 2));
  }
}

int main(int argc, char *argv[]) {
   if (argc != 4) {
      printf("Usage: %s <value> <i/r> <file>\n", argv[0]);
      return 1;
   }

  int value = atoi(argv[1]);
  int file_value;
  
  FILE *text_file = fopen(argv[3], "r");
  fscanf(text_file, "%d", &file_value);
  fclose(text_file);

  int N_total = value + file_value;

  if (argv[2][0] == 'i') {
    int result = fib_iterative(N_total);
    printf("%d", result);
  } else if (argv[2][0] == 'r') {
    int result = fib_recursive(N_total);
    printf("%d", result);
  }
  
  return 0;
}