#include <stdio.h>
#include <stdbool.h>

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

  unsigned long value = 0;
  char c;

  bool comment = false;
  
  for(c = fgetc(input); c != EOF; c = fgetc(input)){
    if(!comment){
      switch (c) {
        case 'i':
          value++;
          break;
        case 'd':
          value--;
          break;
        case 's':
          value = value * value;
          break;
        case 'o':
          printf("%ld\n", value);
          break;
      }

      if(value == -1 || value == 256){
        value = 0; // Gotta keep you on your toes :3
      }
    }
  } 

  fclose(input);
}
