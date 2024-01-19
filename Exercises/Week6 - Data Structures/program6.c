/*!
 * @file    program6.c
 * 
 * @brief   This program accompanies the slide # 21 in the "Data Structures"
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

typedef struct tree_node {
    
  int key;
  struct tree_node *left;    
  struct tree_node *right;    
        
} tree_node_t;

typedef struct binary_search_tree {
    
  tree_node_t *root;
    
} binary_search_tree_t;

tree_node_t *search(tree_node_t *root, int key) { 

    // Base Cases: root is null or key is present at root 
    if (root == NULL || root->key == key) 
       return root; 
     
    // Key is greater than root's key 
    if (root->key < key) 
       return search(root->right, key); 
  
    // Key is smaller than root's key 
    return search(root->left, key); 

} 

tree_node_t *insert(tree_node_t *node, int key) { 

  if (node == NULL) {

    tree_node_t *temp =  (tree_node_t*) malloc(sizeof(tree_node_t)); 

    temp->key = key;
    temp->left = NULL;
    temp->right = NULL; 

    return temp; 
  
  }

  if (key < node->key) 
    node->left = insert(node->left, key); 
  else if (key > node->key) 
    node->right = insert(node->right, key);    
  
  return node; 

} 

void print_inorder(tree_node_t *root) { 

  if (root != NULL) { 

    print_inorder(root->left); 
    printf("%d \n", root->key); 
    print_inorder(root->right); 

  } 

} 

int main() {

  int num_nodes = 0;
  int root = 0, key = 0;
  
  binary_search_tree_t *t = (binary_search_tree_t*) malloc(sizeof(binary_search_tree_t));
  
  printf("Enter the number of nodes: ");
  scanf("%d", &num_nodes);
  
  printf("Enter the root: ");
  scanf("%d", &root);
  t->root = insert(t->root, root);
  
  for (int k = 0; k < (num_nodes - 1); k++) {

    printf("Enter the node: ");
    scanf("%d", &key);
    insert(t->root, key);

  }

  print_inorder(t->root); 

  printf("Enter the node to search: ");
  scanf("%d", &key);
  
  if (search(t->root, key)) 
    printf("The key is present!\n");
  else
    printf("The key is not present!\n");

  return 0; 

}
