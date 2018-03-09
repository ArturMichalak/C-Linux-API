#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>
#include "ReadFile.h"

int main(int argc, char **argv) {
  if (argc != 2) {
    perror("Niewsłaściwa liczba parametrów");
  }
  char* out;
  int cOut =1;
  if (RFUL(argv[1], &out, &cOut)) {
    printf("Nie udalo sie otworzyc pliku: %s\n", strerror(errno));
  }
  
  write(1, out, cOut);
  return 0;
}

