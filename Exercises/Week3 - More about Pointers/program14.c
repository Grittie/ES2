/*!
 * @file    program14.c
 * 
 * @brief   This program accompanies the slide # 20 in the "More about pointers"
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

int do_add(int a, int b) {

  return a + b;

}

int do_mult(int a, int b) {

  return a * b;

}

int main() {

  int y;

  //* Declare the function pointer */
  int (*pf) (int, int);

  pf = do_add;
  y = pf(6, 5);

  printf("Variable y has the value: %i\n", y);
  printf("Memory address of do_add is: %p\n", pf);

  pf = do_mult;
  y = pf(6, 5);

  printf("Variable y has the value: %i\n", y);
  printf("Memory address of do_mult is: %p\n", pf);

  return 0;

}
