#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int n, m, k;

int var (int i, int j, int c) {
  return i * m * k + j * k + c; }

int main (int argc, char** argv) {
  if (argc < 4) {
    printf ("run using ./grid-color N M K\n"); exit (0); }

  n = atoi (argv[1]);
  m = atoi (argv[2]);
  k = atoi (argv[3]);

  unsigned int nVars = n*m*k;
  unsigned int nClauses = n*m + n*m*k*(n-1)*(m-1)/4;

  printf ("p cnf %u %u\n", nVars, nClauses);

  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) {
      for (int c = 1; c <= k; c++)
        printf ("%i ", var(i,j,c));
      printf ("0\n"); }

  for (int ia = 0; ia < n; ia++)
    for (int ja = 0; ja < m; ja++)
      for (int ib = ia+1; ib < n; ib++)
        for (int jb = ja+1; jb < m; jb++)
          for (int c = 1; c <= k; c++)
            printf ("-%i -%i -%i -%i 0\n", var(ia,ja,c), var(ia,jb,c), var(ib,ja,c), var(ib,jb,c));
}
