#include <stdio.h>
#include <stdlib.h>
#define max 1000

char buffer[max+1];

int main(int argc, char* argv[]){
FILE* f;
int append = 0, i;

if(argc == 1 || (argc == 2 && (strcmp(argv[1], "-a") == 0))){
	fprintf(stderr, "You didn't give a filename to save the input in.\n");
	exit(1);
}

if(strcmp(argv[1], "-a") == 0) { append = 1;}

for(i=1; i<argc; i++){
	if(strcmp(argv[i], "-a") == 0) { continue; }
	if(append) { f = fopen(argv[i], "a"); }
	else { f = fopen(argv[i], "w"); }
	fgets(buffer, max, stdin);
	while(!feof(stdin)) {
		fprintf(f, "%s", buffer);
		printf("%s", buffer);
		fgets(buffer, max, stdin);
	}
	fclose(f);
}
return(0);
}
