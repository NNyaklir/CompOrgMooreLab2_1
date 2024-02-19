#include <stdio.h>
#include "my_string.c"


/*static char *randstring(size_t length) {
  static char charset[] =
      "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789`~!@#$%^&*"
      "()_+-=[]{}\\|;:,<.>/?";
  char *randomString = NULL;

  if (!length) return NULL;
  if ((randomString = malloc(sizeof(char) * (length + 1))) == NULL) return NULL;

  for (size_t i = 0; i < length; i++) {
    int key = rand() % (int)(sizeof(charset) - 1);
    randomString[i] = charset[key];
  }

  randomString[length] = '\0';

  return randomString;
} */

int main(void) {
 // char *s;
 // size_t len = 5;

 // s = randstring(len);

  //printf("String s: %s\n", s);

  //free(s);

  //return 0;

  //write your test code here
  char* name = 'johhny';
  int n = str_len( *name);
  printf("%d\n" ,n);

  
}