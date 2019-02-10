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
        }else{
            fscanf(fin,"%d",&data);
            darr[i] = darr[i-1] + data;
        }
    }
	fclose(fin);
    return darr;
}
int *read_int_deltas(char *fname, int *len){
	struct stat sb;
	int data;
	int result = stat(fname,&sb);
	if(result==-1 || sb.st_size < sizeof(int)){
		*len = result;
		return NULL;
	}
	FILE *fin = fopen(fname,"r");
	int *darr = (int *)malloc(sb.st_size);
	len = sb.st_size/sizeof(int);
	for(int i=0;i<sb.st_size/sizeof(int);i++){
		if(i == 0){
			fread(&darr[i],sizeof(int),1,fin);
		}else{
			fread(&data,sizeof(int),1,fin);
			darr[i] = darr[i-1] + data;
		}
	}
	fclose(fin);
	return darr;	
}
int *read_4bit_deltas(char *fname, int *len){
	return 0;
}
