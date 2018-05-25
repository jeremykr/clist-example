#include "MergeSort.h"

/* 
Top-down merge sort implementation referenced from
https://en.wikipedia.org/wiki/Merge_sort

Destroys the original list, unless it is
a singleton list.
*/

List* merge_sort(List* list) {
    // Base case: No need to sort if a list contains 1 or 0 elements
    if (list->size <= 1) return list;

    List* left = make_list();
    List* right = make_list();

    /* Split list into left and right lists, with
    the first half of the list placed in the left,
    and the second half placed in the right */
    int i = 0;
    for (Node* p = list->head; p != NULL && i < list->size; p = p->next, i++) {
        if (i < list->size/2) {
            append(left, p->value);
        } else {
            append(right, p->value);
        }
    }

    // Recursively sort the resulting lists
    left = merge_sort(left);
    right = merge_sort(right);

    return merge(left, right);
}

List* merge(List* left, List* right) {
    int value;
    List* result = make_list();

    while (left->size > 0 && right->size > 0) {
        if (left->head->value <= right->head->value) {
            pop(left, &value);
            append(result, value);
        } else {
            pop(right, &value);
            append(result, value);
        }
    }

    // Consume remaining values from left list
    while (pop(left, &value)) {
        append(result, value);
    }
    // Consume remaining values from right list
    while (pop(right, &value)) {
        append(result, value);
    }
    return result;
}