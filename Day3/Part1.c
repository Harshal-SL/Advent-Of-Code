#include <stdio.h>

int main(){
    long int total = 0;
    FILE *fp;
    //Open the File in read mode
    fp = fopen("input.txt","r");

    // Check whether the file is open successfully or not
    if (!fp) {
        printf("Failed to open file.\n");
        return 1;
    }

    char *line = NULL;
    size_t line_len = 0;
    // Read file line by line 
    while (getline(&line, &line_len, fp) != -1) {
        long int i = 0; // Traverse through the line

        while (line[i] != '\0') {
            // Verify "mul(" 
            if (line[i] == 'm' && line[i+1] == 'u' && line[i+2] == 'l' && line[i+3] == '(') {
                long int a, b;
                int chars_read = 0; // To store the count of following word readed

                // Check the occurence of 'mul('
                if (sscanf(&line[i], "mul(%ld,%ld)%n", &a, &b, &chars_read) == 2) {
                   // Check whether terminating by ')'
                    if (line[i + chars_read - 1] == ')' && chars_read > 0) {
                        total += a*b; // Calcuate total
                        i += chars_read;  // increment i with the chars_read
                        continue; // Skip the current set of iterations
                    }
                }
            }
            i++; // Move to next character
        }
    } 
    fclose(fp); // Close the file
    printf("Total = %ld\n", total);
    return 0;
}
