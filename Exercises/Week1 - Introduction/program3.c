/*!
 * @file    program3.c
 * 
 * @brief   This program accompanies the slide # 9 in the "Introduction to C
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

int main() {

  int a = 80;
  int *p;

  p = &a;

  printf ("Address of a: %p - %p\n", &a, p);
  printf ("Value of a: %i - %i\n", a, *p);

  return 0;

}
