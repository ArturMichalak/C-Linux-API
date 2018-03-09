#ifndef READFILE_H_
#define READFILE_H_

typedef struct FileBuffer {
  char character;
  struct FileBuffer *next;
} FileBuffer;

int RFUL(char *fileName, char **out, int *cOut);

#endif // !READFILE_H_
