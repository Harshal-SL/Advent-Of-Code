#include<stdio.h>
// #include <string.h>

int main(){
    long int total = 0;
    FILE *fp;
    //Open the File in read mode
    fp = fopen("input.txt","r"); 

    // Check whether the file is open successfully or not
    if(fp == NULL){
        printf("Error in opening the file");
        return 0;
    }
    char *line = NULL;
    size_t line_len = 0; 

    int enabled = 1; // Acts as a Toggle variable to check whether the previous was do() or don't()

    // Read file line by line 
    while(getline(&line,&line_len,fp) != -1){
        long int i = 0; // Traverse through the line

        while (line[i] != '\0') {

            //Without using strncmp()
            // Check the occurence of don't()
            if(enabled == 1 && line[i] == 'd' && line[i+1] == 'o' && line[i+2] == 'n' && line[i+3] == '\'' && line[i+4] == 't' && line[i+5] == '(' && line[i+6] == ')'){
            
                enabled = 0; // If there is a occurence of don't() then disable
                i += 7; // increment i by 7 (readed 7 charater)
                continue; // skip  the iteration
            }
            
            // Check the occurence of do()
            if(enabled == 0 && line[i] == 'd' && line[i+1] == 'o' && line[i+2] == '(' && line[i+3] == ')' ){
                enabled = 1; // If there is a occurence of do() then enable
                i += 4; // increment i by 4 (readed 4 charater)
                continue; // skip  the iteration
            }

            // with using strncmp

            // if (strncmp(&line[i], "do()", 4) == 0) {
            //     enabled = 1;
            //     i += 4;
            //     continue;
            // }

            // if (strncmp(&line[i], "don't()", 7) == 0) {
            //     enabled = 0;
            //     i += 7;
            //     continue;
            // }


            // Check wheather enabled . if yes then check the occurence of 'mul('

            if(enabled && line[i] == 'm' && line[i+1] == 'u' && line[i+2] == 'l' && line[i+3] == '('){
                long int a,b;
                int chars_read = 0; // To store the count of following word readed

                if(sscanf(&line[i],"mul(%ld,%ld)%n",&a,&b,&chars_read) == 2){
                    // Check whether terminating by ')'
                    if(chars_read > 0 && line[i + chars_read - 1] == ')'){
                        total += a*b; // Calcuate total
                        i += chars_read;  // increment i with the chars_read
                        continue; // Skip the current set of iteration
                    }
                }
            }
            i++; // Move to next character
        }
    }
    fclose(fp); // Close the file
    printf(" Total : %ld \n" , total);
    return 0;
}