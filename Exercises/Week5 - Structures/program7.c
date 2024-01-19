/*!
 * @file    program7.c
 * 
 * @brief   This program accompanies the slide # 9 in the "Structures"
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

#define PI 3.14159

typedef struct position {

  int x;
  int y;

} point_t;

typedef struct circle {

  point_t center;
  int radius;

} circle_t;

int main() {

  int radius = 0;
  double area;
  circle_t circ1;

  circ1.center.x = 10;
  circ1.center.y = 20;

  printf("Enter the radius: ");
  scanf("%d", &radius);

  circ1.radius = radius;

  area = PI * (circ1.radius * circ1.radius);

  printf("Circle at position (%d, %d) with area = %.2f\n", circ1.center.x, circ1.center.y, area);

  return 0;

}
