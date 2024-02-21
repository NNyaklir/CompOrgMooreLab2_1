#ifndef string_included
#define string_included

#include <stdlib.h>

size_t str_len(const char *s);

int str_cmp(const char *s1, const char *s2);

int str_n_cmp(const char *s1, const char *s2, size_t n);

void *mem_cpy(void* __restrict__ dst, const void* __restrict__ src, size_t n);

char *str_chr(const char *s, int c);

char *str_p_brk(const char *s, const char *charset);

char *str_sep(char **stringp, const char *delim);

char *str_cat(char *s1, const char *s2);
#endif
