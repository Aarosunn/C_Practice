
#include <stdio.h>
#include <stdlib.h>

int main() {

  int a = 999;

  printf("%zu\n", sizeof a);
  printf("%zu\n", sizeof(2 + 7));
  printf("%zu\n", sizeof 3.14);

  int i = 9;

  while (i < 10)
    printf("while: i is %d\n", i++);

  i = 9;

  do {
    printf("do-while: i is %d\n", i++);
  } while (i < 10);

  int r;

  do {
    r = rand() % 100;
    printf("%d\n", r);
  } while (r != 37);

  return 0;
}
