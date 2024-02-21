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

int AL_insert_first (ArrayList_t *AL, void *elem, void *(*copy_data)(void *)){
    if (AL ==NULL){
        return 1; //fail

    }

    if(AL->size==AL->capacity){//if size and capacity are same, expand
        size_t newCapacity = (AL->capacity==0) ? 1 : AL->capacity*2;
        void ** newArray = realloc(AL->array, newCapacity *sizeof(void *)); //gets new space for expanding array
        if(newArray==NULL){
            return 1;
        }
        AL->array = newArray;
        AL->capacity = newCapacity; //this finishes recreating the array
    }

    for(size_t i= AL->size; i>0; i--){
        AL->array[i] = AL->array[i-1];
    }

    if (copy_data!=NULL){
        AL->array[0] = copy_data(elem);
    }
    else{
        AL->array[0] = elem;
    }
    AL->size++; //reflect that the size increased by one
    return 0;
}


int AL_delete_first(ArrayList_t *AL, int (*delete_data)(void *)) {
    if (AL == NULL || AL->size == 0) {
        return 1;  //fail
    }

    if (delete_data!= NULL) { //if there is something to delete, delete
        delete_data(AL->array[0]);

    }

    for (size_t i = 1; i < AL->size; ++i) {
        AL->array[i-1] =AL->array[i];
    } //shifts all elements in array towards 0 once

    AL->size--;
    return 0;  // success
}

int AL_delete_last(ArrayList_t *AL, int (*delete_data)(void *)) {
    if (AL ==NULL || AL->size ==0) {
        return 1;//fail
    }

    if (delete_data!= NULL) {
        delete_data(AL->array[AL->size - 1]);//deletes data
    }

    AL->size--;
    return 0;//success
}

int AL_insert_at(ArrayList_t *AL, size_t i, void *elem, void *(*copy_data)(void *)) {
    if (AL == NULL) {
        return 1; //fail
    }

    if (i > AL->size) {
        i = AL->size;  // inserts element at end index is greater than size
    }

    if (AL->size == AL->capacity){ //this bit will start to increase the size,capacity,etc 
        size_t new_capacity = (AL->capacity == 0) ? 1 : AL->capacity * 2;
        void** new_array = realloc(AL->array, new_capacity * sizeof(void *));
        if (new_array == NULL) {
            return 1; 
        }
        AL->array = new_array;
        AL->capacity = new_capacity;
    }

    for (size_t j = AL->size; j > i; --j) { //decreases size
        AL->array[j] = AL->array[j - 1];
    }

    if (copy_data != NULL) { //inserts data
        AL->array[i] = copy_data(elem);
    } else {
        AL->array[i] = elem;
    }

    AL->size++;
    return 0; //does the thing
}

int AL_delete_at(ArrayList_t *AL, size_t i, int (*delete_data)(void *)) {
    if (AL==NULL || i >=AL->size) {
        return 1;  //fail
    }

    if (delete_data!=NULL) { //deletes data
        delete_data(AL->array[i]);
    }

    for (size_t j =i+1; j<AL->size; ++j) { //decreases size
        AL->array[j - 1]= AL->array[j];
    }

    AL->size--;
    return 0; //success
}
