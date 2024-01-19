/*!
 * @file    program2.c
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
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define CONV_FACTOR 60

struct motor {
    
  int port;
  double volts;
  double rpm;    
    
};

int main() {

  int freq = 0;
  int num = 3;
  struct motor motors[num];

  srand(time(NULL));

  for (int k = 0; k < num; k++) {

    motors[k].port = k + 1;
    motors[k].volts = rand() % 20;

    printf("Enter the frequency (Hz) # %d: ", k + 1);
    scanf("%d", &freq);

    motors[k].rpm = CONV_FACTOR * freq;

  }

  for (int k = 0; k < num; k++) {

    printf("Motor # %d details\n", k + 1);
    printf("  Port:    %d\n", motors[k].port);
    printf("  Voltage: %.2f\n", motors[k].volts);
    printf("  RPM:     %.2f\n", motors[k].rpm);

  }

  return 0;

}

