/*!
 * @file    program9.c
 * 
 * @brief   This program accompanies the slide # 12 in the "Structures"
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
#include <string.h>
#include <stdio.h>

typedef union number {

  int i;
  float f;
  char s[20];

} number_t;

int main() {

  number_t num;

  printf("Size of number_t: %ld\n", sizeof(union number_t));

  num.i = 2700;
  printf("%d\n", num.i);

  num.f = 2.45;
  printf("%d %f\n", num.i, num.f);

  strcpy(num.s, "HvA HBO-ICT TI EM2");
  printf("%d %f %s\n", num.i, num.f, num.s);

  return 0;

}
