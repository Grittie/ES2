/*!
 * @file    program2.c
 * 
 * @brief   This program accompanies the slide # 3 in the "More about pointers"
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

  int row_int[10] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
  char *row_char = "AMSTERDAM";
  int *p = row_int;
  char *q = row_char;

  for (int k = 1; k <= 10; k++)
    printf("%p - %p\n", p++, q++);

  return 0;

}

