/*!
 * @file    program6.c
 * 
 * @brief   This program accompanies the slide # 7 in the "Structures"
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
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define PI 3.14159

struct position {

  int x;
  int y;

};

struct circle {

  struct position center;
  int radius;

};

int main() {

  int num = 0, radius;
  double area;
  struct circle *ptr;

  srand(time(NULL));

  printf("Enter the number of circles: ");
  scanf("%d", &num);

  ptr = (struct circle*) malloc(num * sizeof(struct circle));

  for (int k = 0; k < num; k++) {

    (ptr + k)->center.x = rand() % 40;
    (ptr + k)->center.y = rand() % 40;

    printf("Enter the radius # %d: ", k + 1);
    scanf("%d", &radius);

    (ptr + k)->radius = radius;

  }

  for (int k = 0; k < num; k++) {

    area = PI * ((ptr + k)->radius * (ptr + k)->radius);

    printf("Circle at position (%d, %d) with area = %.2f\n", (ptr + k)->center.x, (ptr + k)->center.y, area);

  }

  return 0;

}

