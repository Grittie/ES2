/*!
 * @file    program1.c
 * 
 * @brief   This program accompanies the slide # 5 in the "Data Structures"
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

typedef struct linked_list_node {

  int data;
  struct linked_list_node *next;

} linked_list_node_t;

typedef struct linked_list {
    
  linked_list_node_t *head;
    
} linked_list_t;

void insert_beginning(linked_list_t *l) {

  linked_list_node_t *temp = (linked_list_node_t*) malloc(sizeof(linked_list_node_t));

  printf("Enter the data: ");
  scanf("%d", &(temp->data));

  temp->next = l->head;

  l->head = temp;

}

void print_list(linked_list_t *l) { 

  linked_list_node_t *temp = l->head;
  
  printf("The elements of the list are:");
  
  while (temp != NULL) { 

    printf(" %d ", temp->data); 
    temp = temp->next; 

  }
  
  printf("\n");

} 

int main() {

  int num_nodes = 0;

  linked_list_t *l = (linked_list_t*) malloc(sizeof(linked_list_t));
  l->head = NULL;
  
  printf("Enter the number of nodes: ");
  scanf("%d", &num_nodes);
  
  for (int k = 0; k < num_nodes; k++) {

    insert_beginning(l);

  }
  
  print_list(l);
  
  return 0;

}
