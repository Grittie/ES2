/*!
 * @file    program10.c
 * 
 * @brief   This program accompanies the slide # 13 in the "More about pointers"
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

void div(int num1, int num2, int *quotient, int *remainder) {

   *quotient = num1 / num2;
   *remainder = num1 % num2;

}

int main() {

  int a = 76, b = 10, q, r;

  div(a, b, &q, &r);

  printf("The quotient is: %d\n", q);
  printf("The remainder is: %d\n", r);

  return 0;

}
