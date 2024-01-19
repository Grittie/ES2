/*!
 * @file    program5.c
 * 
 * @brief   This program accompanies the slide # 14 in the "Using pointers"
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

int main(int argc, char *argv[]) {

  if (argc >= 2) {

    printf("The list of arguments is:\n");

    for(int i = 1; i < argc; i++)
      printf("  %s\n", argv[i]);

  }
  else
    printf("The list of arguments is empty\n");

  return 0;

}
