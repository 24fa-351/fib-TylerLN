#include <stdio.h>
#include <stdlib.h>

int FibIterative(int n) {
  if (n == 1) {
    return 0;
  } else if (n == 2) {
    return 1;
  }
  int first = 0;
  int second = 1;
  int next_value;
  for (int ix = 3; ix <= n; ix++) {
    next_value = first + second;
    first = second;
    second = next_value;
  }
  return second;
}

int FibRecursive(int n) {
  if (n == 1) {
    return 0;
  } else if (n == 2) {
    return 1;
  } else {
    return (FibRecursive(n - 1) + FibRecursive(n - 2));
  }
}

int main(int argc, char *argv[]) {
  int value = atoi(argv[1]);
  FILE *text_file = fopen(argv[3], "r");
  int file_value;
  fscanf(text_file, "%d", &file_value);
  fclose(text_file);

  int N_total = value + file_value;

  if (argv[2][0] == 'i') {
    int result = FibIterative(N_total);
    printf("%d", result);
  } else if (argv[2][0] == 'r') {
    int result = FibRecursive(N_total);
    printf("%d", result);
  }
  return 0;
}