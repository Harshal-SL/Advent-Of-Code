#include <stdio.h>
#include <stdlib.h>
#define MAX 1000

//Custom Comparator using for QSort funtion to Sort elements in ascending Order
int compare(const void*a,const void*b){
    return(*(int*)a - *(int*)b);
}

// Calcuate Total Distance
int totaldistance(int* left,int* right,int size){

    // Sort the array elements
    qsort(left,size,sizeof(int),compare);
    qsort(right,size,sizeof(int),compare);

    int total = 0;
    
    // Calcuate the Total Distance
    for(int i = 0 ; i < size ; i++){
        total += abs(left[i] - right[i]);
    }
    return total;
}




int main(){

    //Read the Input File
    FILE *fp = fopen("input.txt","r");

    if(fp == NULL){
        printf("Error in opening the file");
        return 1;
    }

    int left[MAX] , right[MAX];
    int count = 0; 

    //Read the elements of the input file 
    while(fscanf(fp,"%d %d",&left[count],&right[count]) == 2){
        count++;
    }

    int result = totaldistance(left, right, count); // Call Total Distance Function
    printf("Total Distance is = %d\n",result);
    return 0;
}