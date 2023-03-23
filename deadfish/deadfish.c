#include <stdio.h>

int main(int argc, char *argv[])
{
  if (argc == 2) 
  {
    printf("Reading file %s\n", argv[1]);
    readInputFile(argv[1]);
  }
  else if (argc > 2) 
  {
    printf("Too many arguments!\n");

    return 1;
  }
  else 
  {
    printf("Entering cmd mode...\n");
  }

  return 0;
}

void readInputFile(char filename[])
{
  FILE *input;
  char buff[255];

  input = fopen(filename, "r");

  if (input == NULL)
  {
    printf("Could not open file %s", filename);
    return;
  }
  
  while (fscanf(input, "%s", buff) == 1) { 
    printf("%s\n", buff);
  }

  fclose(input);
}
