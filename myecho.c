#include <stdio.h>
#include <string.h>

int main(int argc, char* argv[]) {
  int verbose = 0;
  int i;

  for(i = 1; i < argc; i++) {
    if(strcmp(argv[i], "-v") == 0) { verbose = 1; break; }
    if(strcmp(argv[i], "--verbose") == 0) { verbose = 1; break; }
  }

  for(i = 1; i < argc; i++) {
    if(verbose) {
      printf("Argument %d: '%s'\n", i, argv[i]);
    }
    else {
      if(i > 1) { printf(" "); }
      printf("%s", argv[i]);
    }
  }
  printf("\n");
  return 0;

}
