#pragma once
#include <stdlib.h>
#include <stddef.h>

typedef struct Node Node;

struct Node {
    Node* next;
    int value;
};

Node* make_node(int value);