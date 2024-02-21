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


void *AL_get_at(ArrayList_t *AL, size_t i){
    if(AL==NULL || i>=AL->size){
        return NULL; //if empty return empty
    }

    return AL->array[i]; //return value if not
}

int AL_set_at(ArrayList_t *AL, size_t i, void *elem, void *(*copy_data)(void *),int (*delete_data)(void *)){
    if(AL==NULL || i>=AL->size){
        return 1; //fail
    }

    if(delete_data!=NULL){
        delete_data(AL->array[i]); //if there is data there then delete it
    }

    if(copy_data !=NULL){
        AL->array[i] =copy_data(elem); //if there is something to copy, copy to specified

    }
    else{
        AL->array[i]= elem; //or just straight up inset it
    }

    return 0; //success
}
