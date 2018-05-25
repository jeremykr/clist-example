#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include "Node.h"

typedef struct List List;

/* Singly-linked list implementation */
struct List {
    Node* head;
    int size;
};

List* make_list(void);

List* append(List*, int);

List* from_string(char*, const char*);

List* combine(List*, List*);

List* copy(List*);

int pop(List*, int*);

void print_list(List*);

void free_nodes(List*);