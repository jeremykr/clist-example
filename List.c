#include "List.h"

List* make_list() {
    List* list = (List*)malloc(sizeof(List));
    list->head = NULL;
    list->size = 0;
    return list;
}

/* Append a value to the end of the given list. */
List* append(List* list, int value) {
    Node* node = make_node(value);
    if (list->head == NULL) {
        list->head = node;
    } else {
        Node* p;
        for (p = list->head; p->next != NULL; p = p->next);
        p->next = node;
    }
    list->size++;
    return list;
}

/* Parse a string as a list of ints. */
List* from_string(char* s, const char* delim) {
    List* nums = make_list();
    char** endptr = NULL;
    char* token = NULL;
    int num;

    token = strtok(s, delim);
    while (token != NULL) {
        if (strcmp("0", token) == 0) {
            append(nums, 0);
        } else {
            num = strtol(token, endptr, 10);
            if (num != 0) {
                append(nums, num);
            }
        }
        token = strtok(NULL, delim);
    }
    return nums;
}

/* Appends list b to the end of list a. 
References to the original lists are preserved. */
List* combine(List* a, List* b) {
    if (a->head == NULL && b->head == NULL) {
        return a;
    }
    if (a->head == NULL) {
        return b;
    } else if (b->head == NULL) {
        return a;
    } else {
        Node* p;
        for (p = a->head; p->next != NULL; p = p->next);
        p->next = b->head;
        a->size += b->size;
        return a;
    }
}

/* Creates and returns a duplicate of the given list. */
List* copy(List* list) {
    List* dup = make_list();
    if (list->head == NULL) return NULL;
    for (Node* p = list->head; p != NULL; p = p->next) {
        append(dup, p->value);
    }
    return dup;
}

/* Returns 1 if a value was popped, 0 if the list is empty. */
int pop(List* list, int* value) {
    if (list->head == NULL) {
        return 0;
    } else {
        *value = list->head->value;
        Node* p = list->head;
        list->head = list->head->next;
        free(p);
        list->size--;
    }
    return 1;
}

void print_list(List* list) {
    printf("[");
    if (list->head != NULL) {
        for (Node* p = list->head; p != NULL; p = p->next) {
            printf("%d", p->value);
            if (p->next != NULL) {
                printf(", ");
            }
        }
    }
    printf("]\n");
}

void free_nodes(List* list) {
    int x;
    while (pop(list, &x));
}