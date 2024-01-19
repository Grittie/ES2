/*!
 * @file    program4.c
 * 
 * @brief   This program accompanies the slide # 5 in the "Structures"
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

void set_motor(struct motor *m) {

  int p, freq;
  double v;

  printf("Enter the port: ");
  scanf("%d", &p);
  m->port = p;

  printf("Enter the voltage: ");
  scanf("%lf", &v);
  m->volts = v;

  printf("Enter the frequency (Hz): ");
  scanf("%d", &freq);
  m->rpm = CONV_FACTOR * freq;

}

int main() {

  struct motor m1;

  set_motor(&m1);

  printf("Motor details\n");
  printf("  Port:    %d\n", m1.port);
  printf("  Voltage: %.2f\n", m1.volts);
  printf("  RPM:     %.2f\n", m1.rpm);

  return 0;

}

