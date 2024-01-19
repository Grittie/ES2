/*!
 * @file    program8.c
 * 
 * @brief   This program accompanies the slide # 10 in the "Structures"
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

typedef signed char smallint_t;

int main() {

  smallint_t i;

  for (i = 0; i < 10; i++)
    printf("%d ", i);

  printf("\nNumber of bytes (smallint_t): %li\n", sizeof(smallint_t));

  return 0;

}

