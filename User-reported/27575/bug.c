#include <stdio.h>
int main(int argc, char **argv) {
  int i = argc - 1;
  int a = 1 << i;
  int b = a >> 1;
  double c = b > 0 ? (double)b : 0.5;
  printf("%d %g\n", b, c);
}
