## Lab 2.1

## my_string
    [ ] Impliment strlen
    [ ] Impliment strcomp & strncomp
    [ ] Impliment memcpy
    [ ] Impliment strchr
    [ ] Impliment strpbk
    [ ] Impliment strsep
    [ ] Impliment strcat

## tokenizer
    [ ] Make a function defined as “char **tokenize(char *str, const char *delims)”
        [ ] This function takes two pointers where each array of characters is null terminated.
            [ ] str: Array of characters to be split into tokens based on delims characters
            [ ] delims: Array of characters used to split “str.”
        [ ] This function must return a null-terminated array of pointers of size k+1 where k is the
            number of times that a character from “delims” was found in “str”
            [ ] The pointers in the return value most point to memory places in “str”. Therefore, you
                must null terminate each substring in “str” and point to the beginning of the
                substring. 

## part 3 ArrayList_t
    [ ] Initilize struct
    [ ] Delete struct
    [ ] Print all elements in the struct
    [ ] Retreive an element from anywhere in the struct
    [ ] Overwrite what is contained at an index
    [ ] Pre-append
    [ ] Delete the first element
    [ ] Append
    [ ] Delete the last element
    [ ] Insert element at given index
    [ ] Delete element at given index
    [ ] 