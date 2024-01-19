/*!
 * @file    program13.c
 * 
 * @brief   This program accompanies the slide # 17 in the "More about pointers"
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

void doprint (char **q) {

  for (int k = 0; k <= 3; k++)
    printf("\n%s", *(q+k));

  for (int k = 0; k <= 3; k++)
    printf("\n%s", q[k]);

  for ( int k = 0; k <= 3; k++)
    printf("\n%s", *q++);

}

int main() {

  char *p[4] = {"Winter", "Spring", "Summer", "Autumn"};

  for (int k = 0; k <= 3; k++)
    printf("%c\t", *(p[k] + 2));  // Prints the third letter of each string

  doprint(&p[0]);  //doprint(p);
  printf("\n");

  return 0;

}


