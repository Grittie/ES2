/*!
 * @file    program4.c
 * 
 * @brief   This program accompanies the slide # 12 in the "Using pointers"
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

int main() {

  FILE *data_sensors;
  int data1, data2;

  data_sensors = fopen("sensor_data.txt", "r");

  if (data_sensors == NULL)
    printf("ERROR: Failed to open the file.\n"); 
  else {

    while (fscanf(data_sensors,"%d %d", &data1, &data2) != EOF)
      printf("The data is: %d - %d\n", data1, data2);

  }

  fclose(data_sensors);

  return 0;

}
