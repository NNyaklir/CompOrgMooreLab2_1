#include <stdlib.h>

char **tokenize(char *str, const char *delims) {
    // Count the number of tokens
    size_t token_count = 1;  // At least one token even if str is empty
    for (size_t i = 0; str[i] != '\0'; i++) {
        for (size_t j = 0; delims[j] != '\0'; j++) {
            if (str[i] == delims[j]) {
                token_count++;
                break;
            }
        }
    }

    // Allocate memory for array of pointers
    char **tokens = (char **)malloc((token_count + 1) * sizeof(char *));
    if (tokens == NULL) {
        // Memory allocation failed
        return NULL;
    }

    // Tokenize the string
    size_t token_index = 0;
    char *token = str;
    while (*str != '\0') {
        for (size_t j = 0; delims[j] != '\0'; j++) {
            if (*str == delims[j]) {
                *str = '\0';  // Null-terminate the substring
                tokens[token_index] = token;
                token_index++;
                token = str + 1;  // Move to the next character
                break;
            }
        }
        str++;
    }

    // Null-terminate the array of pointers
    tokens[token_index] = NULL;

    return tokens;
}

int main() {
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
}