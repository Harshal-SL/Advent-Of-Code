// Part 2 - Using Problem Dampener

#include<stdio.h>

// Detemine whether the level is safe.
int is_safe(int arr[] , int n){

    if(n < 2)
        return 1;
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
        if((increasing && difference <0 ) || (decreasing && difference > 0))
            return 0;
        // Check the difference between is exactly in range between 1 - 3 else return false
        if (difference > 3 || difference < -3)
            return 0;
            
    }

    return 1;
}

// Determine whether the level is_safe using damper
int is_safe_damper(int arr[] , int n){

    // Check whether the level is safe without using damper 
    if(is_safe(arr,n))
        return 1;
    //Using damper


    for(int skip = 0 ; skip < n ; skip++){

        // Initize the temporary array to store new array after the current element
        int temp[100]; 
        int temp_size = 0;

        // Skip the current element and store the elements of the current array to temporary array
        for(int i = 0 ; i < n ; i++){
            if(i != skip){
                temp[temp_size++] = arr[i];
            }
        }
        // Check whether by skipping the current element does the level is safe
        if(is_safe(temp,temp_size)){
            return 1;
        }
    }
    return 0;
}


int main(){
    int total_safe = 0;
    FILE *fp;
    fp = fopen("input.txt","r"); // Open the input file
    char line[3000];

    // Read the input file line by line
    while(fgets(line,sizeof(line),fp)) {
        int level[100];   // Create an array to store the element of the perticular level  
        int n = 0;
        char *ptr = line; //Create a pointer to traverse the elements within the line 

        // Read the element of the level and store in the array 
        while(sscanf(ptr,"%d",&level[n]) == 1){
            n++;
            while(*ptr != ' ' && *ptr != '\0') ptr++; // Skips the current number 
            while(*ptr == ' ' ) ptr++ ;// Skips any empty spaces in between the elements
        }
        // Call the is_safe function for that perticular level
        if (n > 0 && is_safe_damper(level, n)) {
            total_safe++; // If the level is safe then increment the total_safe
        }
  
    }
    // int arr1[] = {7, 6, 4, 2, 1};
    // int arr2[] = {1, 2, 7, 8, 9};
    // int arr3[] = {9, 7, 6, 2, 1};
    // int arr4[] = {1, 3, 2, 4, 5};
    // int arr5[] = {8, 6, 4, 4, 1};
    // int arr6[] = {1, 3, 6, 7, 9};

    // if (is_safe(arr5, 5)) {
    //       total_safe++;
    //     }
    
    printf("Total Safe : %d \n" ,total_safe);

    return 0;
}