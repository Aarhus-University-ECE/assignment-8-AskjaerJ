#include "list_queue.h"


void init_queue(queue *q) { // Add your initialize queue
  q->front = NULL;
  q->size = 0;
  q->rear = NULL;
}

int empty(queue *q) { // Add your empty function  
  if(q->size == 0) {
    return 1;
  }
  else {
    return 0;
  }
  
}

void enqueue(queue *q, int x) { // Add your enqueue function
  qnode*add = malloc(sizeof(qnode));
  add->data = x;
  if(q->size == 0) {
    q->front = add;
    q->rear = add;
  }
  else{
    q->rear->next = add;
    q->rear = add;
  }
  q->size++;
}

int dequeue(queue *q) { // Add your dequeue function
  qnode*temp;
  temp = q->front;
  q->front = q->front->next;
  if(q->size == 1) {
    q->rear = NULL;
  }
  q->size--;
  return temp->data;
}
