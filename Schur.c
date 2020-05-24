#include <stdio.h>
#include <stdlib.h>

int main (int argc , char ** argv) {
  int i, j, k;

  if (argc < 3) {
    printf ("c too few arguments: ./Schur [size] [colors]\n");
    exit (0); }

  int size = atoi (argv[1]);
  int sets = atoi (argv[2]);

  int nrofclauses = size + sets * (size/2) + size * sets * (sets-1) / 2;;
  for (i = 1; i <= size; i++)
    for (k = i + 1; i + k <= size; k++)
      nrofclauses += sets;

  printf("p cnf %i %i\n", size * sets, nrofclauses);

  for (i = 0; i < size; i++) {
    for (j = 1; j <= sets; j++) printf("%i ", i * sets + j);
    printf ("0\n"); }

  for (i = 0; i < size; i++)
    for (j = 1; j <= sets; j++)
      for (k = j + 1; k <= sets; k++)
        printf ("-%i -%i 0\n", i * sets + j, i * sets + k);

  for (i = 1; i <= size; i++)
    for (k = i; i + k <= size; k++)
      for (j = 1; j <= sets; j++) {
        if (i < k) printf ("-%i ", (i-1)*sets + j);
        printf ("-%i -%i 0\n", (k-1) * sets + j, (i+k-1) * sets + j); }
}
