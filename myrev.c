#include <stdio.h>
#include <string.h>
#define MAXLINE 1000

char input[MAXLINE+1];
int length;
int i;

void reverse_file();
void reverse_string();

int main(int argc, char* argv[]){
FILE* f;
int wasfile = 0;

for(i=1; i<argc; i++){
printf("argv[%d] is %s\n", i, argv[i]);
}

for(i=1; i<argc; i++){
	if(argv[i][0] == '-') { continue; }
	f = fopen(argv[i], "r");
	if(f != NULL){
		wasfile = 1;
		reverse_file(f);
	fclose(f);
	}
}

if(!wasfile){
	fgets(input, MAXLINE, stdin);
	while(!feof(stdin)){
		length = (strlen(input)-2);
		reverse_string(input);
		fgets(input, MAXLINE, stdin);
	}
}
return(0);
}

void reverse_file(FILE* f){
fgets(input, MAXLINE, f);
	while(!feof(f)) {
		length = (strlen(input)-2);
   		reverse_string(input);
    		fgets(input, MAXLINE, f);
  	}
}

void reverse_string(char* s){
char tmp;

for(i=0; i<=length; i++){
	tmp = s[i];
	s[i] = s[length];
	s[length] = tmp;
	length--;
}

printf("%s", s);

}
