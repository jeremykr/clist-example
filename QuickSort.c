#include "QuickSort.h"

/* 
Destroys the original list, unless it is
a singleton list.
*/
List* quick_sort(List* list) {
    if (list->size <= 1) return list;

    int pivot, value;
    pop(list, &pivot);

    List* lo = make_list();
    List* hi = make_list();
    
    while (pop(list, &value)) {
        if (value <= pivot) {
            append(lo, value);
        } else {
            append(hi, value);
        }
    }

    return combine(append(quick_sort(lo), pivot), quick_sort(hi));
}