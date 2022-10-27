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
            if(swapcount == 0) {
                break;
            }
            else {
                swapcount = 0;
                temp = llPtr->head;
                prev_node = llPtr->head;
            }
        }
        if(temp->data > temp->next->data){
            if(temp == prev_node) {
                llPtr->head = swap(temp, temp->next);
            }
            else {
                prev_node->next = swap(temp, temp->next);
                temp = prev_node->next;
            }   
            swapcount++;
        }
    prev_node = temp;
    temp = temp->next;
    }
}
 

