/*!
 * @file    program12.c
 * 
 * @brief   This program accompanies the slide # 15 in the "More about pointers"
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

int *getMax(int *m, int *n) {

  if (*m > *n)
    return m;
  else
    return n;

}

int main() {

  int x = 100;
  int y = 200;

  int *max = getMax(&x, &y);

  printf("The maximum value is: %d\n", *max);

  return 0;

}

