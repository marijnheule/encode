#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main (int argc, char** argv) {
  unsigned long int a, b, c, max, offset = 0, nVars = 0, nClauses = 0;
  int true = 0, false = 0;

  if (argc < 2) {
    printf ("run using ./PythagoreanTriples MAX [OFFSET=0]\n"); exit (0); }

  max = atoi (argv[1]);
  if (argc > 2) offset = atoi(argv[2]);

  for (a = 1; a <= max; a++)
    for (b = a; (a*a + b*b) <= (max * max); b++) {
      c = sqrt(a*a + b*b);
      if ((c*c) == (a*a + b*b)) {
        nClauses += 2;
        if (c > nVars) nVars = c; } }

  printf ("p cnf %lu %lu\n", nVars + offset, nClauses);

  for (a = 1; a <= max; a++)
    for (b = a; (a*a + b*b) <= (max*max); b++) {
      c = sqrt(a*a + b*b);
      if ((c*c) == (a*a + b*b)) {
        printf ("%lu %lu %lu 0\n",    a + offset, b + offset, c + offset);
        printf ("-%lu -%lu -%lu 0\n", a + offset, b + offset, c + offset); } }
}
