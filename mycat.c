#include <stdio.h>
#include <string.h>
#define BUFSIZE 1000

char buffer[BUFSIZE+1];
int lineno = 0;

void cat(FILE* f, int lines) {
  fgets(buffer, BUFSIZE, f);
  while(!feof(f)) {
    if(lines) {
      printf("%6d ", ++lineno);
    }
    printf("%s", buffer);
    fgets(buffer, BUFSIZE, f);
  }
}

int main(int argc, char* argv[]) {
  FILE* f;
  int i;
  int lines = 0;
  int wasfile = 0;
  int input = 1;
  
  for(i = 1; i < argc; i++) {
    if(strcmp(argv[i], "-n") == 0) { lines = 1; }
  }
  
  if(strcmp(argv[1], "--") == 0) { input = 0; }
  
  for(i = 1; i < argc; i++) {
    if(input){
    if(argv[i][0] == '-') { cat(stdin, lines); }
    }
    f = fopen(argv[i], "r");
    if(f != NULL) {
      wasfile = 1;
      cat(f, lines);
      fclose(f);
    }
  }

  if(!wasfile) {
    cat(stdin, lines);
  }

  return 0;
}

