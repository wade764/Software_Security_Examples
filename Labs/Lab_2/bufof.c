//sudo sysctl -w kernel.randomize_va_space=0
//gcc -g -fno-stack-protector -z execstack -o bufof bufof.c 



#include <stdio.h>
#include <string.h>

int convert(char *str){
	int i=0;
	int null = 0;
	char buffer[20];
	strcpy(buffer, str);
	for(i=0; i<20; i++){
		if(buffer[i] >= 65 && buffer[i] <=90){
			buffer[i] += 32;
		}
		else{
			buffer[i]=null;
		}
	}
	printf("The new string is %s\n", buffer);
	return(0);

		

}

int main(int argc, char *argv[]){
	convert(argv[1]);
	return(0);
}

