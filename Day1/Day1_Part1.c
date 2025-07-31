//Implementation without Default libraries

#include <stdio.h>
#include <stdlib.h>
// #define MAX 1000

//Implementation of the Quick Sort Function 

// Swap the Elements
void swap(long int *a,long int *b){
    long int temp = *a;
    *a = *b;
    *b = temp;
}


int partition(long int arr[], long int low, long int high){
    long int pivot = arr[low];
    long int i = low + 1;
    long int j = high;

    while(i <= j){
        while(i <= high && arr[i] <= pivot) i++;
        while(j >= low && arr[j] > pivot) j--;

        if(i < j){
            swap(&arr[i], &arr[j]);
        }
    }

    swap(&arr[low], &arr[j]); 
    return j;
}

void quick_sort(long int arr[], long int low, long int high){
    if(low < high){
        int p = partition(arr, low, high);
        quick_sort(arr, low, p - 1);
        quick_sort(arr, p + 1, high);
    }

} //problem


long int Abs(long int x){
    // if(x < 0){
    //     return x*-1;
    // }
    // return x;
    return (x<0)? -x:x;
}

long int totaldistance(long int left[],long int right[],long int size){
    quick_sort(left,0,size-1);
    quick_sort(right,0,size-1);
    long int total = 0;

    // Calcuate the Total Distance
    for(long int i = 0 ; i < size ; i++){
        total += Abs(left[i] - right[i]);
    }
    return total;
}

int main(){
    //Read the Input File
    FILE *fp = fopen("input2.txt","r");

    if(fp == NULL){
        printf("Error in opening the file");
        return 1; 
    }

    // Implement using Dynamic Array using Malloc and Realloc

    long int max = 1000; 
    long int *left = malloc(max*sizeof(long int)); // Initize the Left array
    long int *right = malloc(max*sizeof(long int)); // Initize the Right array
    long int count = 0; 
    char *line = NULL;
    size_t line_len = 0;

    while(getline(&line,&line_len, fp) != -1){ // Traverse Line by line 
        if(sscanf(line,"%ld %ld",&left[count],&right[count])==2){ // Check the contain of the line will match the format required
            if(count >= max){// Check whether if the number for element is more then the initalize value
                //Relocate the size of the array by 2 
                max *= 2;
                long int *temp_left = realloc(left, max*sizeof(long int));
                long int *temp_right = realloc(right, max*sizeof(long int));  
                //Assign the relocate size to the arrays            
                left = temp_left;
                right = temp_right;
            }   
            count++;    
        }
    }


    fclose(fp);
    long int result = totaldistance(left, right, count); // Call Total Distance Function
    printf("Total Distance is = %ld\n",result);

    //Delocate the memory
    free(left);
    free(right);
    return 0;
}