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

void AL_print(ArrayList_t *AL, void (*print_data)(void*)){
    if (AL==NULL || AL->array==NULL){
        return;
    }

    for(size_t i=0; i< AL->size; i++){
        if(print_data !=NULL){
            print_data(AL->array[i]);
        }
    }
}


void *AL_get_at(ArrayList_t *AL, size_t i, void *elem, void*(*copy_data)(void *), int (*delete_data)(void *)){
    if (AL==NULL || i>=AL->array){
        return 1; //fail sadge
    }

    if(delete_data !=NULL){
        delete_data(AL->array[i]);
    }
    if(copy_data!=NULL){
        AL->array[i]= copy_data(elem);
    }
    else {
        AL->array[i]= elem;
    }
    return 0; //success
}
