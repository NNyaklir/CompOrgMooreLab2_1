#include "ArrayList.h"
#include <stdlib.h>

/*typedef struct{
    void **array;
    size_t size;
    size_t capacity;
} ArrayList_t;*/


//1
ArrayList_t *AL_init(void){
    ArrayList_t *list = malloc(sizeof(ArrayList_t));// accrue space
    if (list==NULL){
        return NULL; //if empty show its empty
    }

    list->array = NULL;
    list->size = 0;
    list->capacity = 0; //initilize at zero

    return list; //returns pointer of list
}

//2
int AL_free(ArrayList_t *AL, int (*delete_data)(void *)){
    if (AL==NULL){
        return 1; //if null failure
    }
    for (size_t i=0; i<AL->size; i++){
        if (delete_data!=NULL){
            delete_data(AL->array[i]);
        }
        free(AL->array[i]);//frees individual data
    }
    free(AL->array);
    free(AL);

    return 0; //success
}

