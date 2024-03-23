#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <conio.h>
#include <malloc.h>


char* remove_last_character(char* str) {
    // Check if the string is NULL or empty
    if (str == NULL || *str == '\0') {
        return NULL;
    }

    // Get the length of the string
    int len = strlen(str);

    // Allocate memory for the new string
    char* new_str = (char*) malloc(len * sizeof(char));

    // Check if memory allocation was successful
    if (new_str == NULL) {
        return NULL;
    }

    // Copy the original string to the new string, excluding the last character
    strncpy(new_str, str, len - 1);

    // Add the null terminator to the end of the new string
    new_str[len - 1] = '\0';

    // Free the memory of the old string
    free(str);

    return new_str;
}

char* add_character_to_end(char* str, char character) {
    // Check if the string is NULL
    if (str == NULL) {
        return NULL;
    }

    // Get the length of the string
    int len = strlen(str);

    // Allocate memory for the new string (old string length + 1 for the new character + 1 for the null terminator)
    char* new_str = (char*)malloc((len + 2) * sizeof(char));

    // Check if memory allocation was successful
    if (new_str == NULL) {
        return NULL;
    }

    // Copy the original string to the new string
    strcpy(new_str, str);

    // Add the new character to the end of the new string
    new_str[len] = character;

    // Add the null terminator to the end of the new string
    new_str[len + 1] = '\0';

    // Free the memory of the old string
    free(str);

    return new_str;
}

char* input_with_timeout(const char* prompt, const unsigned int timeout) {
    // Define characters for carriage return, line feed, backspace, and null
    char CR = '\r';
    char LF = '\n';
    char BS = '\b';
    char NL = '\0';

    // Initialize an empty line buffer
    char* line = (char*) malloc(1 * sizeof(char));
    *line = NL;

    // Print the prompt to the console
    printf(prompt);

    // Get the current time and calculate the end time for the timeout
    const long start = time(NULL);
    const long end   = start + timeout;
    const int DELAY  = 5000;    // (5e-3 s) ~~~ (5 ms)

    // Loop until the current time is less than the end time
    while (time(NULL) < end) {
        // If a key has been pressed
        if (kbhit()) {
            // Get the pressed character
            char c = getch();

            // If the character is a backspace
            if (c == BS) {
                // If the line is not empty
                if (*line != NL) {
                    // Remove the last character from the line
                    line = remove_last_character(line);

                    // Clear the character on the screen
                    printf("%c%c", BS, ' ');

                    // Move the cursor back
                    printf("%c", BS);

                     // Print the prompt and the updated line
                    // printf("%c%s%s", CR, prompt, line);
                }
            }
            // If the character is a carriage return or line feed
            else if (c == CR || c == LF) {
                // Print a new line and return the line
                printf("%c%c", CR, LF);
                return line;
            }
            // If the character is any other character
            else {
                // Print the character and add it to the end of the line
                printf("%c", c);
                line = add_character_to_end(line, c);
            }
        }
        // Sleep for a short delay to prevent high CPU usage
        usleep(DELAY);
    }

    // If the timeout is reached, print a new line, free the line, and return null
    printf("%c%c", CR, LF);
    free(line);
    return NULL;
}

int main() {
    // Get user input with a timeout of 10 seconds
    char *input = input_with_timeout("Enter your input: ", 10);

    // If input is not NULL, print the input
    if (input != NULL) {
        printf("Input received: '%s'\n", input);
        free(input);
    } else {
        // If input is NULL, print a timeout message
        printf("Timeout occurred. Returning NULL.\n");
    }

    return 0;
}
