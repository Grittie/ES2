/*!
 * @file    program5.c
 * 
 * @brief   This program accompanies the slide # 16 in the "Data Structures"
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

typedef struct stack_node {
    
  int data;
  struct stack_node *next;    
    
} stack_node_t;

typedef struct stack {
    
  stack_node_t *top;
    
} stack_t;

void push(stack_t *s) { 

  stack_node_t *temp = (stack_node_t*) malloc(sizeof(stack_node_t));

  printf("Enter the data: ");
  scanf("%d", &(temp->data));

  temp->next = s->top;

  s->top = temp;

} 

void pop(stack_t *s) { 

  if (s->top == NULL) 
    return; 
  
  stack_node_t *temp = s->top; 
  
  s->top = s->top->next; 

  temp->next = NULL; 

  free(temp); 

} 

void print_stack(stack_t *s) { 

  stack_node_t *temp = s->top;
  
  printf("The elements of the queue are:");
  
  while (temp != NULL) { 

    printf(" %d ", temp->data); 
    temp = temp->next; 

  }
  
  printf("\n");

}

int main() {

  int num_nodes = 0;
  
  stack_t *s = (stack_t*) malloc(sizeof(stack_t));
  s->top = NULL;
  
  printf("Enter the number of nodes to push: ");
  scanf("%d", &num_nodes);
  
  for (int k = 0; k < num_nodes; k++) {

    push(s);

  }

  print_stack(s);

  pop(s);

  print_stack(s);
    
  return 0;
  
}
