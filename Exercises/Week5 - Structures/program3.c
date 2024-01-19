/*!
 * @file    program3.c
 * 
 * @brief   This program accompanies the slide # 4 in the "Structures"
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

#define CONV_FACTOR 60

struct motor {
    
  int port;
  double volts;
  double rpm;    
    
};

int main() {

  int freq = 0;
  struct motor *m1;

  (*m1).port = 2;
  m1->volts = 5.0;

  printf("Enter the frequency (Hz): ");
  scanf("%d", &freq);

  m1->rpm = CONV_FACTOR * freq;

  printf("Motor details\n");
  printf("  Port:    %d\n", m1->port);
  printf("  Voltage: %.2f\n", m1->volts);
  printf("  RPM:     %.2f\n", m1->rpm);

  return 0;

}

