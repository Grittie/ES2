/*!
 * @file    program5.c
 * 
 * @brief   This program accompanies the slide # 13 in the "Introduction to C
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

  int k;
  int a = 80;
  char c = 65;
  int *p;
  char *q;

  p = &a;
  q = &c;

  for (k = 1; k <= 5; k++)
    printf("%p - %p\n", p++, q++);

  return 0;

}
