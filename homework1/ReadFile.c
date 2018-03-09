#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <fcntl.h>
#include <unistd.h>
/* optional */
#include <sys/types.h>
#include <sys/stat.h>
/* File Header */
#include "ReadFile.h"

/* READ FILE UNDER LINUX*/
int RFUL(char *fileName, char **out, int *cOut) {
  int file, error;
  
  FileBuffer *buf_char = (FileBuffer*)malloc(sizeof(FileBuffer));
  FileBuffer *buf_pointer = buf_char;
  if ((file = open(fileName, O_RDONLY)) < 0) return errno;
  while (error = read(file, &(buf_pointer->character), 1)) {
    if (error < 0) return errno;
    (*cOut)++;
    buf_pointer->next = (FileBuffer*)malloc(sizeof(FileBuffer));
    buf_pointer = buf_pointer->next;
  }
  buf_pointer->character = '\0';
  buf_pointer->next = buf_char;

  (*out) = (char*)malloc((*cOut) * sizeof(char));
  int i = 0;
  while (buf_char->character != '\0') {
    (*out)[i] = buf_char->character;
    buf_pointer = buf_char;
    buf_char = buf_char->next;
    free(buf_pointer);
    i++;
  }
  
  free(buf_char);
  close(file);
  (*out)[i] = '\0';
  
  return errno;
}