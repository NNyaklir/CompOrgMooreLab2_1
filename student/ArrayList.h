#ifndef ArrayList_H
#define ArrayList_H

#include <stdlib.h>

typedef struct {
    void **array;
    unsigned long size;
    unsigned long capacity;
} ArrayList_t;

ArrayList_t *AL_init(void); //1

int AL_free(ArrayList_t *AL, int (*delete_data)(void *)); //2

void AL_print(ArrayList_t *AL, void (*print_data)(void *)); //3

void *AL_get_at(ArrayList_t *AL, size_t i); //4

//int AL_set_at(ArrayList_t *AL, size_t i, void *elem, void *(*copy_data)(void *), int (*delete_data)(void *));// 5

//int AL_insert_first(ArrayList_t *AL, void *elem, void
//*(*copy_data)(void *)); // 6

//int AL_delete_first(ArrayList_t *AL, int (*delete_data)(void *)); //7

//int AL_insert_last(ArrayList_t *AL, void *elem, void
//*(*copy_data)(void *)); //8

//int AL_delete_last(ArrayList_t *AL, int (*delete_data)(void *));// 9

//int AL_insert_at(ArrayList_t *AL, size_t i, void *elem, void
//*(*copy_data)(void *)); //10

//int AL_delete_at(ArrayList_t *AL, size_t i, int (*delete_data)(void*));// 11




#endif