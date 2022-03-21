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

List * createList() 
{
    List *lista = (List *) malloc(sizeof(List));
    lista -> head = NULL;
    lista -> current = NULL;
    lista -> tail = NULL;
    
    return lista;
}

void * firstList(List * list)
{
    if(list -> head && list -> head -> data)
    {
        list -> current = list -> head;
        return list -> head -> data;
    }
    return NULL;
}

void * nextList(List * list) 
{
    if(list -> current && list -> current -> data)
    {
        list -> current = list -> current -> next;
        if (list -> current == NULL) return NULL;
        return list -> current -> data;
    }
    return NULL;
}

void * lastList(List * list) 
{
    if(list -> tail && list -> tail ->data)
    {
        list -> current = list -> tail;
        return list -> tail -> data;
    }
    return NULL;
}

void * prevList(List * list) 
{
    if(list -> current && list -> current -> data)
    {
        list -> current = list -> current -> prev;
        if (list -> current == NULL) return NULL;
        return list -> current -> data;
    }
    return NULL;
}

void pushFront(List * list, void * data) 
{
    Node *nuevoNodo = createNode(data);

    if(list -> head == NULL)
    {
        list -> head = nuevoNodo;
    }
    else
    {
        if(list -> current -> next != NULL)
        {
            list -> current = list -> head;
            list -> head = nuevoNodo;
            nuevoNodo -> next = list -> current -> next; 
        }
    }
}

void pushBack(List * list, void * data) {
    list->current = list->tail;
    pushCurrent(list,data);
}

void pushCurrent(List * list, void * data) 
{
    //Node *nuevoNodo = createNode(data);
    
    //if(list -> head = NULL) list -> head = nuevoNodo;
    //if(list -> current -> next == NULL)
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
    return NULL;
}

void cleanList(List * list) {
    while (list->head != NULL) {
        popFront(list);
    }
}