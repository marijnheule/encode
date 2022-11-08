#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

int main (int argc, char** argv) {

  if (argc < 3) {
    printf ("c too few arguments: %s size discrepancy\n", argv[1]);
    exit (0); }

  int size = atoi (argv[1]);
  int disc = atoi (argv[2]);

  int nVar = size;
  int nCls = 0;

  for (int i = 1; i < size; i++)
    for (int d = 1; d < size; d++)
      if (i + 2*d <= size)
        nCls++;

  for (int i = 1; i < size; i++)
    for (int d = 1; d < size; d++)
      if (i + (disc-1)*d <= size)
        nCls++;

  printf ("p cnf %i %i\n", nVar, nCls);

  for (int i = 1; i < size; i++)
    for (int d = 1; d < size; d++)
      if (i + 2*d <= size)
        printf ("%i %i %i 0\n", i, i+d, i+2*d);

  for (int i = 1; i < size; i++)
    for (int d = 1; d < size; d++)
      if (i + (disc-1)*d <= size) {
        for (int l = 0; l < disc; l++)
          printf ("%i ", -i - l*d);
        printf ("0\n");
      }

}
