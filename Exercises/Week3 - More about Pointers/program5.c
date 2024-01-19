/*!
 * @file    program5.c
 * 
 * @brief   This program accompanies the slide # 8 in the "More about pointers"
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

void swap (int *p , int *q) {

  int temp = *p;
  *p = *q;
  *q = temp;

}

int main() {

  int a = 10, b = 20;
      
  printf("Initial values -> a: %d - b: %d\n", a, b);
  swap(&a, &b);
  printf("Final values -> a: %d - b: %d\n", a, b);

  return 0;

}

