/*!
 * @file    program8.c
 * 
 * @brief   This program accompanies the slide # 11 in the "More about pointers"
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

void makecapitals (char *p) {

  while (*p != 0) {

    if ((*p >= 'a') && (*p <= 'z'))
      *p = *p + 'A' - 'a';

    p++;

  }

}

int main() {

  char msg[20];

  printf("Type a string: ");
  fgets(msg, 20, stdin);

  makecapitals(msg);

  printf("Changing to capitals ...\n");
  printf("%s", msg);

  return 0;

}

