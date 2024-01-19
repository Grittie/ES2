/*!
 * @file    program1.c
 * 
 * @brief   This program accompanies the slide # 2 in the "More about pointers"
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

int main() {

  int a = 80;
  char c = 65;
  int *p;
  char *q;

  p = &a;
  q = &c;

  printf("%d - %d\n", a, c);
  printf("%d - %d\n", *p, *q);
  printf("%p - %p\n", &a, &c);
  printf("%p - %p\n", p, q);
  printf("%p - %p\n", &p, &q);

  return 0;

}
