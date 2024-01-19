/*!
 * @file    program10.c
 * 
 * @brief   This program accompanies the slide # 13 in the "Structures"
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

typedef enum BATT_LEVELS {
  LOW_LEVEL,
  FULL_LEVEL
} BATT_LEVELS_T;

typedef enum CHARGE_STATES {
  NO_CHARGE,
  REGULAR_CHARGE,
  UNKNOWN_CHARGE
} CHARGE_STATES_T;

int main() {

  int option = 0;
  CHARGE_STATES_T charger_state = UNKNOWN_CHARGE;

  while (option < 2) {

    printf("Enter the battery level [0-1]: ");
    scanf("%d", &option);

    switch (option) {

      case LOW_LEVEL:
      charger_state = REGULAR_CHARGE;
      break;

      case FULL_LEVEL:
      charger_state = NO_CHARGE;
      break;

      default:
      charger_state = UNKNOWN_CHARGE;
      ;

    }

    if (charger_state == REGULAR_CHARGE)
      printf("Charger on REGULAR CHARGE mode\n");
    else if (charger_state == NO_CHARGE)
      printf("Charger on NO CHARGE mode\n");

  }

  return 0;

}
