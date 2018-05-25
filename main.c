#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include "List.h"
#include "MergeSort.h"
#include "QuickSort.h"

int main() {
    char input[100];
    const char* delim = " ";

    printf("Enter a list of integers separated by spaces:\n");
    gets(input);

    List* list = from_string(input, delim);
    
    /* We create copies to sort, since the 
    sorting operations are destructive. */
    List* l1 = copy(list);
    List* l2 = copy(list);
    printf("Original:\n");
    print_list(list);

    l1 = merge_sort(l1);
    l2 = quick_sort(l2);
    
    printf("Merge sort:\n");
    print_list(l1);
    printf("Quick sort:\n");
    print_list(l2);

    free_nodes(list);
    free_nodes(l1);
    free_nodes(l2);
}