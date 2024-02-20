#include "ArrayList.h"
#include <stdlib.h>

typedef struct{
    void **array;
    size_t size;
    size_t capacity;
} ArrayList_t;


//1
struct ArrayList_t *AL_init(void){
    ArrayList_t *list = malloc(sizeof(ArrayList_t));// accrue space
    if (list==NULL){
        return NULL; //if empty show its empty
    }

    list->array = NULL;
    list->size = 0;
    list->capacity = 0; //initilize at zero

    return list; //returns pointer of list
}

