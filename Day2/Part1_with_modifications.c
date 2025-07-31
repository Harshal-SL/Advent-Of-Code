// Using Dynamic Memory allocation

#include<stdio.h>
#include <stdlib.h>

// Detemine whether the level is safe.
int is_safe(int arr[] , int n){

    // Check Whether the adjecent elements are equal
    for(int i = 1 ; i < n ; i++){
        if(arr[i] == arr[i-1]){   
            return 0;
        }
    }

    // Detemine Whether the level is increasing or decreasing
    int increasing = arr[1] > arr[0];
    int decreasing = arr[0] > arr[1];


    for (int i = 1; i < n; i++) {
        int difference = arr[i] - arr[i-1]; // Difference between the corresponding elements
        
        // Check if increasing the difference should be greater then 0 , similarily is decreasing the difference must be lesser then 0
        if((increasing && difference <=0 ) || (decreasing && difference >= 0))
            return 0;
        
        // Check the difference between is exactly in range between 1 - 3 else return false
        if (difference > 3 || difference < -3)
            return 0;
    }

    return 1;
}


int main(){

    int total_safe = 0;
    FILE *fp;

    fp = fopen("input.txt","r"); // Open the input file
    char *line = NULL;
    size_t line_len = 0;

    // Read the input file line by line
    while(getline(&line,&line_len,fp) != -1) {
        int max = 5;
        int *level = malloc(max*sizeof(int));   //Dynamically create a  array to store the elements of the level
        int n = 0;

        char *ptr = line; //Create a pointer to traverse the elements within the line 

        // Read the element of the level and store in the array 
        while(sscanf(ptr,"%d",&level[n]) == 1){
   
            //Relocate the memory if the allocate memory is more then required
            if( n >= max){
                max *= 2;
                level = realloc(level,max*sizeof(int));
                
            }
            n++;
            while(*ptr != ' ' && *ptr != '\0') ptr++; // Skips the current number 
            while(*ptr == ' ' ) ptr++ ;// Skips any empty spaces in between the elements
        } 
        // Call the is_safe function for that perticular level
        if (n > 0 && is_safe(level, n)) {
            total_safe++; // If the level is safe then increment the total_safe
        }
        free(level); // Deallocate the memory 
  
    }
    // int arr1[] = {7, 6, 4, 2, 1};
    // int arr2[] = {1, 2, 7, 8, 9};
    // int arr3[] = {9, 7, 6, 2, 1};
    // int arr4[] = {1, 3, 2, 4, 5};
    // int arr5[] = {8, 6, 4, 4, 1};
    // int arr6[] = {1, 3, 6, 7, 9};

    // if (is_safe(arr6, 5)) {
    //       total_safe++;
    //     }
    
    printf("Total Safe : %d \n" ,total_safe);
    fclose(fp); // Close the opened file
    
    return 0;
}