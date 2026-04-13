#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
  if (argc < 2)
    {
      printf("Usage: %s \"string\"\n", argv[0]);
      return 1;
    }
  
  char *str = strdup(argv[1]);
  if (!str)
    return 1;

  char* piece = strtok(str, " ");
  while(piece != NULL)
    {
      printf("%s\n", piece);
      piece = strtok(NULL, " ");
    }
  free(str);
  return 0;
}
