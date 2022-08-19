#include <stdio.h>
#include <stdlib.h>

int atmostone (int* array, int size, int aux) {
  if (size > 1) {
    printf ("%i %i 0\n", -array[0], -array[1]); }

  if (size > 2) {
    printf ("%i %i 0\n", -array[0], -array[2]);
    printf ("%i %i 0\n", -array[1], -array[2]); }

  if (size <= 3) return aux;

  if (size == 4) {
    printf ("%i %i 0\n", -array[0], -array[3]);
    printf ("%i %i 0\n", -array[1], -array[3]);
    printf ("%i %i 0\n", -array[2], -array[3]);
    return aux; }

  aux++;

  printf ("%i %i 0\n", -array[0], aux);
  printf ("%i %i 0\n", -array[1], aux);
  printf ("%i %i 0\n", -array[2], aux);

  for (int i = 0; i < size - 3; i++)
    array[i] = array[i+3];
  array[size-3] = aux;

  return atmostone (array, size - 2, aux);
}

int main (int argc, char** argv) {
  int n = atoi (argv[1]);

  int* array = malloc (sizeof(int) * n);

  for (int i = 1; i <= n; i++) array[i-1] = i;

  printf ("p cnf %i %i\n", n + (n-3) / 2, 3*(n-2));

  atmostone (array, n, n);

  return 0;
}


