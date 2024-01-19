/*!
 * @file    program6.c
 * 
 * @brief   This program accompanies the slide # 9 in the "More about pointers"
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

double average (int p[], int n) {

  double sum = 0.0;

  for (int k = 0; k < n; k++)
    sum += p[k];

  return sum / n;

}

int main() {

  int row[10] = {2, 6, 5, 8, 7, 9, 1, 4, 10, 3};

  printf("The average is: %.4f\n", average(row, 10));

  return 0;

}

