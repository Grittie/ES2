/*!
 * @file    program8.c
 * 
 * @brief   This program accompanies the slide # 17 in the "Introduction to C
 *          programming" lecture of the Embedded Systems 2 course.
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

/* Macro 1 */
#define RADTODEG1(x) ((x) * 57.29578)

/* Macro 2 */
#define RADTODEG2(x) (x * 57.29578)

int main() {

  int a;
  a = RADTODEG1(40);
  printf("a has the value: %i\n", a);

  /* Correct */
  a = RADTODEG1(10 + 30);
  printf("a has the value: %i\n", a);

  /* Be careful: 10 + (30 * 57.29578) */
  a = RADTODEG2(10 + 30);
  printf("a has the value: %i\n",a);

  return 0;

}
