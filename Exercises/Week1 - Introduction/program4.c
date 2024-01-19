/*!
 * @file    program4.c
 * 
 * @brief   This program accompanies the slide # 11 in the "Introduction to C
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

/*
 *
   TODO: Modify the program in such a way that, using the pointer p, both variables
         a and b will end up storing the same value (a = b = 160).
 *
 */

int main() {

  int a = 80, b = 160;
  int *p;

  printf ("Values: a -> %i  - b -> %i\n", a, b);

  *p = b;

  printf ("Values: a -> %i - b -> %i\n", a, b);

  return 0;

}
