/*!
 * @file    program4.c
 * 
 * @brief   This program accompanies the slide # 12 in the "Data Structures"
 *          lecture of the Embedded Systems 2 course.
 * 
 * @author  Bernardo Villalba Frías  <b.r.villalba.frias@hva.nl>
 * 
 * @version 1.0
 * 
 * @date    4 September 2021
 * 
 * This program is a free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License version 2 as published
 * by the Free Software Foundation.
 */
#include <stdlib.h>
#include <stdio.h>

typedef struct queue_node {
    
  int data;
  struct queue_node *next;    
    
} queue_node_t;

typedef struct queue {
    
  queue_node_t *first;
  queue_node_t *last;    
    
} queue_t;

void enqueue(queue_t *q) { 

  queue_node_t *temp = (queue_node_t*) malloc(sizeof(queue_node_t)); 
    
  printf("Enter the data: ");
  scanf("%d", &(temp->data));
  temp->next = NULL; 
  
  if (q->last == NULL) { 

    q->first = temp;
    q->last = temp; 
    return; 

  } 
  
  q->last->next = temp; 
  q->last = temp; 

} 

void dequeue(queue_t *q) { 

  if (q->first == NULL) 
    return; 
  
  queue_node_t *temp = q->first; 
  
  q->first = q->first->next; 
  
  if (q->first == NULL) 
    q->last = NULL; 
  
  free(temp); 

} 

void print_queue(queue_t *q) { 

  queue_node_t *temp = q->first;
  
  printf("The elements of the queue are:");
  
  while (temp != NULL) { 

    printf(" %d ", temp->data); 
    temp = temp->next; 

  }
  
  printf("\n");

}

int main() {

  int num_nodes = 0;
  
  queue_t *q = (queue_t*) malloc(sizeof(queue_t));
  q->first = NULL;
  q->last = NULL; 
  
  printf("Enter the number of nodes to enqueue: ");
  scanf("%d", &num_nodes);
  
  for (int k = 0; k < num_nodes; k++) {

    enqueue(q);

  }

  print_queue(q);

  dequeue(q);

  print_queue(q);
    
  return 0;
  
}
