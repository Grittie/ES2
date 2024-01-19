/*!
 * @file    program2.c
 * 
 * @brief   This program accompanies the slide # 6 in the "Introduction to C
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
#include <stdbool.h>

int main() {

  bool is_detected = false;

  if (!is_detected)
    printf("First attempt: %d\n", is_detected);

  is_detected = true;

  if (is_detected)
    printf("Second attempt: %d\n", is_detected);

  return 0;

}
