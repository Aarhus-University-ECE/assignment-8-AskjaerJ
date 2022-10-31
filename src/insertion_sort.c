#include "insertion_sort.h"
#include "linked_list.h"
#include <stdio.h>


// Add your sort function here
void sort(linked_list *llPtr) {
    int swapcount = 0;
    node_t*temp = llPtr->head;
    node_t*prev_node = llPtr->head;
    while(true) {
        if(temp->next == NULL) {
            if(swapcount == 0) { /* If we didn't swap anything means we are finished, so we break */
                break;
            }
            else {
                swapcount = 0; /* Set swapcount to 0 for next run */
                temp = llPtr->head;
                prev_node = llPtr->head;
            }
        }
        if(temp->data > temp->next->data) {
            if(temp == prev_node) { 
                llPtr->head = swap(temp, temp->next); /* Swap values in list */
            }
            else {
                prev_node->next = swap(temp, temp->next); /* Swap values in list */
                temp = prev_node->next;
            }   
            swapcount++; /* Add one to swapcount to avoid break */
        }
    prev_node = temp;
    temp = temp->next;
    }
}
 

