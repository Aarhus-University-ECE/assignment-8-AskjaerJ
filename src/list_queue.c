#include "list_queue.h"


void init_queue(queue *q) { // Add your initialize queue
  q->front = NULL;
  q->size = 0;
  q->rear = NULL;
}

int empty(queue *q) { // Add your empty function  
  if(q->size == 0) { /* Boolean values, if queue is empty return true (1) */
    return 1;
  }
  else {
    return 0; /* Otherwise return false (0) */
  }
  
}

void enqueue(queue *q, int x) { // Add your enqueue function
  qnode*add = malloc(sizeof(qnode));
  add->data = x; /* X is input of enqueue function */
  if(q->size == 0) { /* If the queue is empty make rear and front both point to input */
    q->front = add; 
    q->rear = add;
  }
  else{
    q->rear->next = add; /* Otherwise we add one in the back of the queue */
    q->rear = add;
  }
  q->size++; /* Make the queue one larger */
}

int dequeue(queue *q) { // Add your dequeue function
  qnode*temp;
  temp = q->front;
  q->front = q->front->next; /* Set the front to the next in the queue */
  if(q->size == 1) { /* If the queue size is 1 means that the rear doesn't exist. */
    q->rear = NULL;
  }
  q->size--; /* Subtract one from the queue size because we removed one */
  return temp->data;
}
