/************************************************************[EDP2.c]
  A SAT encoding of Erdos' discrepancy problem for discrepancy 2
  Written by Marijn Heule
  Last edit, February 26, 2014
********************************************************************/

#include <stdio.h>
#include <stdlib.h>

int main (int argc, char** argv) {
  int a, b, c, d, k, nClauses = 0, nVars;

  if (argc < 1) {
    printf ("run using ./ErdosDiscrepancy MAX\n"); exit (0); }

  int size = atoi(argv[1]);

  nVars = size;

  for (k = 1; k * 3 <= size; k++) {
    c = k;
    while (1) {
      c += 2 * k;
      nClauses += 2;
      if (c + 2 * k > size) break;
      nClauses += 6;
      nVars++;
    }
  }

  printf("p cnf %i %i\n", nVars, nClauses);

  nVars = size;
  for (k = 1; k * 3 <= size; k++) {
    a = k;
    b = a + k;
    while (1) {
      c = b + k;
      printf(" %i  %i  %i 0\n", a, b, c);
      printf("-%i -%i -%i 0\n", a, b, c);

      if (c + 2 * k > size) break;
      d = ++nVars;
      printf(" %i  %i -%i 0\n", a, b, d);
      printf("-%i -%i  %i 0\n", a, b, d);
      printf(" %i  %i -%i 0\n", a, c, d);
      printf("-%i -%i  %i 0\n", a, c, d);
      printf(" %i  %i -%i 0\n", b, c, d);
      printf("-%i -%i  %i 0\n", b, c, d);

      a = d;
      b = c + k;
    }
  }
}
