/*!
 * @file    program3.c
 * 
 * @brief   This program accompanies the slide # 11 in the "Using pointers"
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

int main() {

  FILE *log_sensors;
  int num_readings, reactor1, reactor2;

  log_sensors = fopen("sensor_data.txt", "a+");

  printf("Enter number of readings: ");
  scanf("%d", &num_readings);

  srand(time(NULL));

  for (int i = 0; i < num_readings; i++) {

    reactor1 = rand() % 100;
    reactor2 = rand() % 100;

    fprintf(log_sensors,"%d %d\n", reactor1, reactor2);

  }

  fclose(log_sensors);

  return 0;

}
