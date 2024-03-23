# input-with-timeout
This project includes a function in the C programming language that receives user input with a timeout.

## Usage

To run this code, first compile it:

```bash
gcc main.c -o main
```

## Functions

- char* remove_last_character(char* str): This function removes the last character of a string.
- char* add_character_to_end(char* str, char character): This function adds a character to the end of a string.
- char* input_with_timeout(const char* prompt, const unsigned int timeout): This function receives user input with a timeout.

## Note for Memory Management
- After using the pointer returned by the function "input_with_timeout", make sure to free the allocated memory using free() to avoid memory leaks !
