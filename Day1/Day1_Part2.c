#include <stdio.h>
#include <stdlib.h>
#define MAX 1000

//Custom Comparator using for QSort funtion to Sort elements in ascending Order
int compare(const void*a,const void*b){
    return(*(int*)a - *(int*)b);
}

// Calcuate Similarity Score
int calcuate_similarity_score(int* left,int* right,int size){

    // Sort the array elements by calling Qsort function
    qsort(left,size,sizeof(int),compare);
    qsort(right,size,sizeof(int),compare);

    int similarity_score = 0;
    
    // Calcuate the similarity score
    for(int i = 0 ; i < size ; i++){
        int no_of_times = 0;
        for (int j= 0; j < size; j++) {
            if(left[i] == right[j]){
                no_of_times++;
            }
        }
        similarity_score += left[i] * no_of_times;
    }
    return similarity_score;
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

    int result = calcuate_similarity_score(left, right, count); // Call Calcuate Similarity Score
    printf("Similarity Score = %d\n",result);
    return 0;
}