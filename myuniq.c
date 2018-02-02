#include <stdio.h>
#include <string.h>
#define MAXLINE 1000

char line1[MAXLINE+1];
char line2[MAXLINE+1];
char repeat[MAXLINE+1];
int i;
int d = 0;
int u = 0;

void process_file();

int main(int argc, char* argv[]){
FILE* f;
int wasfile = 0;

if(strcmp(argv[1], "-d") == 0) { d = 1; }
if(strcmp(argv[1], "-u") == 0) { u = 1; }

for(i=1; i<argc; i++){
    if(argv[i][0] == '-') { continue; }
    f = fopen(argv[i], "r");
    if(f != NULL){
        wasfile = 1;
        process_file(f);
    fclose(f);
    }
}

if(!wasfile){
    process_file(stdin);
}
return(0);
}

void process_file(FILE* f){

fgets(line1, MAXLINE, f);
    while(!feof(f)){
          if(d){
            if(strcmp(line1, line2) == 0) {
              printf("%s", line1);
	while(strcmp(line1,line2) == 0 && !feof(f)) {
		fgets(line1, MAXLINE, f);
	}
             }
            strcpy(line2, line1);
            fgets(line1, MAXLINE, f); 
          } else if(u) {
	fgets(line2, MAXLINE, f);
            if(strcmp(line1, line2) == 0) {
              strcpy(repeat, line2);
	while(strcmp(line1,repeat) == 0 && !feof(f)) {
	fgets(line1, MAXLINE, f);
	}
             } else {
              printf("%s", line1);
              strcpy(line1, line2);
             }
          } else {
            if(strcmp(line1, line2) != 0) {
              printf("%s", line1);
             }
            strcpy(line2, line1);
            fgets(line1, MAXLINE, f); 
          }
      }
}
