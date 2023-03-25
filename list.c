#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "list.h"

typedef struct Node Node;

struct Node {
    void * data;
    Node * next;
    Node * prev;
};

struct List {
    Node * head;
    Node * tail;
    Node * current;
};

typedef List List;

Node * createNode(void * data) {
    Node * new = (Node *)malloc(sizeof(Node));
    assert(new != NULL);
    new->data = data;
    new->prev = NULL;
    new->next = NULL;
    return new;
}

List * createList( ) {
    List *list;
    list = malloc( sizeof( List));
    list->head = NULL;
    list->tail = NULL;
    list->current = NULL;
  
     return list;
}

void * firstList(List * list) {
  if ( !list->head){
    return NULL;
  }

  list->current = list->head;
  
    return (list->head->data);
}

void * nextList(List * list) {
  
  if ( list->current == NULL || list->current == list->tail) return NULL;
  list->current = list->current->next;
  
    return (list->current->data);
}

void * lastList(List * list) {
  if (!list->tail) return NULL;
  list->current = list->tail;
    return list->tail->data;
}

void * prevList(List * list) {
  if ( list->head == NULL) return NULL;
  if( list->current == NULL) return NULL;
  if ( list->current == list->head) return NULL;
  
  
    list->current = list->current->prev;
    return list->current->data;
}

void pushFront(List * list, void * data) {

  Node* aux;
  aux = createNode( data);
  aux->next = list->head;
  list->head = aux;
  if (list->tail == NULL){
    list->tail = list->head;
  }
  
}

void pushBack(List * list, void * data) {
    list->current = list->tail;
    pushCurrent(list,data);
}

void pushCurrent(List * list, void * data) {
  Node* aux;
  aux = createNode( data);
  aux->prev= list->current;
  list->current->next = aux;
  list->tail = aux;


}

void * popFront(List * list) {
    list->current = list->head;
    return popCurrent(list);
}

void * popBack(List * list) {
    list->current = list->tail;
    return popCurrent(list);
}

void * popCurrent(List * list) {
  
  if ( list->head == NULL || list->current == NULL){
    return NULL;
  }
  void* aux = list->current->data;
  

  if ( list-> head == list->current){
    list->head = list->current->next;
    free( list->current);
    list->current = list->head;
    list->current->prev = NULL;
    
  } else if( list->current->next != NULL || list->current->prev != NULL){

    list->current->prev = list->current->next;
    list->current->next = list->current->prev;
    //free(list->current);
    
    
    
    
  } else if( list->current == list->tail){

    list->tail = list->current->prev ;
    free( list->current);
    list->current->prev = list->tail;
    list->tail->next = NULL;
    
    
    
    
    
    
    
  
    
  }

  

  list->head->next = list->current;
  return aux;
}

void cleanList(List * list) {
    while (list->head != NULL) {
        popFront(list);
    }
}