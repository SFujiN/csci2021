#include <stdlib.h>
#include <stdio.h>

int main(){
	char *filename = "data/short.txt";
	FILE *fin = fopen(filename,"r");
	int success,sum = 0;
	int currentNum;
	while(success != EOF){
		success = fscanf(fin,"%d",&currentNum);
		printf("currentNum: %d\n",currentNum);
		if(success != EOF){
			sum+=success;
		}
	}
	printf("sum: %d\n",sum);
	return 0;
}

