/*!
 * @file    program1.c
 * 
 * @brief   This program accompanies the slide # 5 in the "Using pointers"
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
#include <stdio.h> 
#include <stdlib.h> 

int main() { 

  int *ptr, num, item;

  printf("Enter number of elements: "); 
  scanf("%d", &num);

  ptr = (int*) malloc(num * sizeof(int)); 

  if (ptr == NULL)
    printf("ERROR: Memory not allocated.\n"); 
  else {

    int item;

    for (int i = 0; i < num; i++) {

      printf("Enter the element: "); 
      scanf("%d", &item);

      ptr[i] = item; 

    }
  
    printf("The elements of the array are: "); 
    for (int i = 0; i < num; i++) { 
      printf("%d ", ptr[i]); 
    } 

    printf("\n");

  } 

  free(ptr);

  return 0; 

} 
