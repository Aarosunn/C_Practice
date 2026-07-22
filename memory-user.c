#include <errno.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

bool parse_arg(const char *str, size_t *out) {
  char *end;
  errno = 0;
  long val = strtol(str, &end, 10);

  if (errno != 0 || end == str || *end != '\0' || val > INT_MAX || val < 0)
    return false;

  *out = (size_t)val;
  return true;
}

int main(int argc, char **argv) {
  if (argc != 3) {
    fprintf(
        stderr,
        "error this program requires two arguments memory(mb) and time(s)\n "
        "you had %d arguments \n",
        argc);
    exit(1);
  }

  size_t mem_mb, dur_sec;

  if (!parse_arg(argv[1], &mem_mb) || !parse_arg(argv[2], &dur_sec)) {
    fprintf(stderr, "error occured\n");
    exit(1);
  }

  printf("memory: %zu MB, time: %zu seconds\n", mem_mb, dur_sec);

  size_t arr_length = (mem_mb * (size_t)pow(10, 6)) / 4;

  printf("elements in array: %zu\n", arr_length);
  printf("PID: %d\n", getpid());

  size_t elapsed_ms = 0, dur_ms = dur_sec * 1000;
  size_t iters = 0, cycles = 0;
  int fill_value = 67;
  clock_t before = clock();

  int *arr = malloc(arr_length * sizeof(int));

  do {
    size_t index = iters % arr_length;
    arr[index] = fill_value++;

    clock_t difference = clock() - before;
    elapsed_ms = ((size_t)(difference * 1000 / CLOCKS_PER_SEC));
    if (index == 0)
      ++cycles;

    iters++;
  } while (elapsed_ms < dur_ms);

  printf(
      "Time taken %zu seconds %zu milliseconds (%zu iterations, %zu cycles)\n",
      elapsed_ms / 1000, elapsed_ms % 1000, iters, cycles);
  printf("%d\n", arr[0]);

  free(arr);
  return 0;
}
