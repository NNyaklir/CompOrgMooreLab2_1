#include "my_string.h"

// 1
size_t str_len(const char *s)
{
    size_t count = 0;
    // while whats pointed to by point isn't the end of the string increase count 
    while(*(s+count) != '\0'){
        count++;
    }
    return count;
}

//2
int str_cmp(const char *s1, const char *s2)
{
    int count = 0;
    while(*(s1+count) != '\0' && *(s2+count) !='\0') //stop at end of str
    {
        if(*(s1+count) != *(s2+count)) // compare the characters
        {
            return 0; // stop
        }
        count++;
    }
    if(*(s1+count) == *(s2+count)) // ensure both strings are done
    {
        return 1; 
    }
    return 0;
}

int str_n_cmp(const char *s1, const char *s2, size_t n)
{
    int count = 0;
    while(*(s1+count) != '\0' && *(s2+count) != '\0' && count < n-1) //stop at end of str or the second to last char
    {
        if(*(s1+count) != *(s2+count)) // compare the characters
        {
            return 0; // stop
        }
        count++;
    }
    if(*(s1+count) == *(s2+count)) // Check the last char
    {
        return 1; 
    }
    return 0;
}
//3
void *mem_cpy(void* __restrict__ dst, const void* __restrict__ src, size_t n)
{
    unsigned char *d = dst;
    const unsigned char *s = src;

    while (n--) {
        *d++ = *s++;
    }

    return dst;
}

// 4
char *str_chr(const char *s, int c)
{
    int count = 0;
    while(*(s+count)!= c && *(s+count) != '\0') // while you havent found the char or sting's not done keep looking
    {
        count++;
    }
    return s+count; // retun a pointer to the char
}

//5
char *str_p_brk(const char *s, const char *charset)
{
    int count1 = 0;
    while(*(s+count1)!='\0') //iterating over first str
    {
        int count2 = 0;
        while(*(charset+count2)!='\0') // iterating over second str
        {
            if(*(s+count1) == *(charset+count2)) //compares each letter of first to each letter in second 
            {
                return (s+count1);// returns pointer of first string
            }
            count2++;
        }
        count1++;
    }
    return NULL; // not found return null
}

//6
char *str_sep(char **stringp, const char *delim)
{
    char *start, *end;
    start = *stringp;
    if (start == NULL) return NULL;

    // if there is only one char in the delimiter, less expensive
    if (*delim == '\0' || *(delim+1) == '\0')
    {
        char ch = *delim;

        if (ch == '\0')end = NULL;
        else
        {
	        if (*start == ch) end = start;
	        else if (*start == '\0') end = NULL;
	        else end = str_chr(start + 1, ch);
	    }
    }
    else
    {
        // Find the end of the word.
        end = str_p_brk(start, delim);
    }

    if (end)
    { 
        // Terminate the token and set *STRINGP past NUL character.
        *end++ = '\0';
        *stringp = end;
    }
    else
    {
        // No more delimiters; this is the last token.
        *stringp = NULL;
    }
    return start;
}

//7
char *strcat(char *dest, const char *src)
{
    size_t count1,count2;
    for (count1 = 0; *(dest+count1) != '\0'; count1++); //find the end of dest
    for (count2 = 0; *(src+count2) != '\0'; count2++)// for each letter in src copy to dest
        *(dest+count1+count2) = *(src+count2);
    *(dest+count1+count2) = '\0'; //add back the termination
    return dest; // return starting pointer to dest
}