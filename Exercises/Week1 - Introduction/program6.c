/*!
 * @file    program6.c
 * 
 * @brief   This program accompanies the slide # 14 in the "Introduction to C
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

  char *p;
  p = "test";

  /* Address of the pointer itself */
  printf("Address of p: %p\n", &p);

  /* Letter: t */
  printf("First character:  %c\n", *p);

  /* Letter: e */
  printf("Second character: %c\n", *(p + 1));

  /* Closing string: 0 */
  printf("Closing string:   %d\n", *(p + 4));

  return 0;

}

