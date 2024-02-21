#include <stdlib.h>

char **tokenize(char *str, const char *delims) {
    //count the number of tokens
    size_t token_count = 1;  // at least one token even if str is empty
    for (size_t i = 0; str[i] != '\0'; i++) {
        for (size_t j = 0; delims[j] != '\0'; j++) { //delims takes the whole line
            if (str[i] == delims[j]) {
                token_count++;
                break;
            }
        }
    }

    //allocate memory for array of pointers
    char **tokens = (char **)malloc((token_count + 1) * sizeof(char *));
    if (tokens== NULL) {
        //memory allocation failed
        return NULL;
    }

    //tokenize the string
    size_t token_index = 0;
    char *token = str;
    while (*str != '\0') {
        for (size_t j =0; delims[j] != '\0'; j++) {
            if (*str ==delims[j]) {
                *str = '\0'; //null-terminate the substring
                tokens[token_index] = token;
                token_index++;
                token = str + 1;  //move to the next character
                break;
            }
        }
        str++;
    }

    //null-terminate the array of pointers
    tokens[token_index] = NULL;

    return tokens;
}

/* test code

    char str[] = "This is a sample string";
    const char delims[] = " ";

    char **tokens = tokenize(str, delims);

    // Example usage: Print the tokens
    for (size_t i = 0; tokens[i] != NULL; i++) {
        printf("Token %zu: %s\n", i + 1, tokens[i]);
    }

    // Free the allocated memory
    free(tokens);

    return 0;
     */