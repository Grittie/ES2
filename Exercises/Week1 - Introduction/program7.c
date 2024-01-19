/*!
 * @file    program7.c
 * 
 * @brief   This program accompanies the slide # 15 in the "Introduction to C
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

  unsigned char *p;
  int a = 0xFA27BE93;

  p = (unsigned char *) &a;

  printf("%i %i %i %i\n", *p, *(p + 1), *(p + 2), *(p + 3));

  return 0;

}
