#include <stdio.h>
#include <stdlib.h>

int main (int argc, char** argv) {

  if (argc < 3) {
    printf ("c too few arguments: %s k (discrepancy) n (length)\n", argv[1]);
    exit (0); }

  int k = atoi (argv[1]);
  int n = atoi (argv[2]);

  int nCls = 0;
  for (int i = 1; i < n; i++)
    for (int d = 1; d < n; d++) {
      if (i + 2*d <= n) nCls++;
      if (i + (k-1)*d <= n) nCls++; }

  printf ("p cnf %i %i\n", n, nCls);

  for (int i = 1; i < n; i++)
    for (int d = 1; d < n; d++)
      if (i + (k-1)*d <= n) {
        for (int j = 0; j < k; j++)
          printf ("%i ", i + j*d);
        printf ("0\n"); }

  for (int i = 1; i < n; i++)
    for (int d = 1; d < n; d++)
      if (i + 2*d <= n)
        printf ("-%i -%i -%i 0\n", i, i+d, i+2*d);
}
