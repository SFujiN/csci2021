#include <stdio.h>
//#include "print_graph_demo.c"

void print_graph(int *data, int len, int max_height){
	int min = data[0];
	int max = data[0];
	for(int i=1;i<len;i++){
		if(min>data[i]){
			min = data[i];
		}
		if(max<data[i]){
			max = data[i];
		}
	}
	int range = max - min;
	float units_per_height = range/(float)max_height;
	printf("length: %d\nmin: %d\nmax: %d\nrange: %d\nmax_height: %d\nunits_per_height: %.2f\n     ",len,min,max,range,max_height,units_per_height);
	for(int i=0;i<len;i++){
		if(i%5==0){
			printf("+");
		}else{
			printf("-");
		}
	}
	printf("\n");
	for(int level=max_height;level>=0;level--){
		printf("%3d |",(int)(min + level * units_per_height));
		for(int i=0;i<len;i++){
			if(data[i]>=(int)(min + level * units_per_height)){
				printf("X");
			}else{
				printf(" ");
			}
		}
		printf("\n");
	}
	printf("     ");
	for(int i=0;i<len;i++){
		if(i%5==0){
			printf("+");
		}else{
			printf("-");
		}
	}
	printf("\n     ");
	for(int i=0;i<len;i++){
		if(i%5==0){
			printf("%-5d",i);
		}
	}
	printf("\n");
}
