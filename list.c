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

    nuevoNodo -> next = list -> head;
    if(list -> head != NULL) list -> head -> prev = nuevoNodo; 
    
    list -> head = nuevoNodo;
    nuevoNodo -> prev = NULL;
    
    if(list -> tail == NULL)
    {
        list -> tail = nuevoNodo;
        nuevoNodo -> prev = list -> current;
    }
    
}

void pushBack(List * list, void * data)
{
    list->current = list->tail;
    pushCurrent(list,data);
}

void pushCurrent(List * list, void * data) 
{
    Node *nuevoNodo = createNode(data);
    
    if(list -> head == NULL) list -> head = nuevoNodo;
    if(list -> current -> next != NULL)
    {
        list -> current -> next = nuevoNodo;
        nuevoNodo -> next = list -> current -> next;
        nuevoNodo -> prev = list -> current;
    }
    else
    {
        list -> tail = nuevoNodo;
        nuevoNodo -> prev = list -> current;
        list -> current -> next = nuevoNodo;
    }
}

void * popFront(List * list) {
    list->current = list->head;
    return popCurrent(list);
}

void * popBack(List * list) {
    list->current = list->tail;
    return popCurrent(list);
}

void * popCurrent(List * list) 
{
    Node *aux = list -> head;
    if(list -> current == list -> head) aux -> next = list -> current -> next;
    
    if(aux -> next != list -> current) aux -> next = list -> current -> next;
    else
    {
        while (aux -> next != list -> current)
        {
            aux = aux -> next;
        }
        aux -> next = list -> current -> next;
    }
    
}

void cleanList(List * list) {
    while (list->head != NULL) {
        popFront(list);
    }
}