#include <stdlib.h>
#include <stdio.h>
#include "deltas.h"

int *read_text_deltas(char *fname, int *len){
    FILE *fin = fopen(fname,"r");
    int data,success;
    int size = 0;
	success = fscanf(fin,"%d",&data);
    if(fin == NULL && success == EOF){
        *len = -1;
        return NULL;
    }
	size++;
    while(success != EOF){
        success = fscanf(fin,"%d",&data);
        size++;
    }
    int *darr = (int *)malloc(sizeof(int)*size);
    *len = size;
    rewind(fin);
    for(int i=0;i<size;i++){
        if(i == 0){
            fscanf(fin,"%d",&data);
            darr[i] = data;
        }
        else{
            fscanf(fin,"%d",&data);
            darr[i] = darr[i-1] + data;
        }
    }
	fclose(fin);
    return darr;
}
int *read_int_deltas(char *fname, int *len){
	FILE *fin = fopen(fname,"r");
	int data;
	int success,size = 0;
	
	fclose(fin);
	return 0;	
}
int *read_4bit_deltas(char *fname, int *len){
	return 0;
}
