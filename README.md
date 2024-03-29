# input-with-timeout
This project includes a function in the **C programming language** that receives user input with a timeout.


## Usage

To run this code, first compile it:

```bash
gcc main.c -o main
```


## Functions

- `char* remove_last_character(char* str)`: This function removes the last character of a string.
- `char* add_character_to_end(char* str, char character)`: This function adds a character to the end of a string.
- `char* input_with_timeout(const char* prompt, const unsigned int timeout)`: This function receives user input with a timeout.


## Note for Memory Management
- After using the pointer returned by the function `input_with_timeout`, make sure to free the allocated memory using `free()` to avoid memory leaks !



## Alerts

> [!NOTE]
> This code includes functions that manipulate strings in C. It's important to understand how memory allocation works in C before using these functions.

> [!WARNING]
> This code uses the `malloc` function to allocate memory and the `free` function to deallocate memory. Always ensure that you have freed any memory that you have allocated to prevent memory leaks.

> [!TIP]
> The `input_with_timeout` function allows you to set a timeout for user input. This can be useful in scenarios where your program needs to continue executing if the user does not provide input within a certain timeframe.

> [!IMPORTANT]
> The `remove_last_character` and `add_character_to_end` functions modify the original string. If you need to keep the original string unchanged, make sure to create a copy of the string before using these functions.

## Example
```c
char *input = input_with_timeout("Enter your input: ", 10);

// If the timeout is not reached
if (input != NULL) {
    printf("Input received: '%s'\n", input);
    free(input);
} else {
    // If input is NULL, print a timeout message
    printf("Timeout occurred. Returning NULL.\n");
}
```
