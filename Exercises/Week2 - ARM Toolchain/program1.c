/*!
 * @file    program1.c
 * 
 * @brief   This program accompanies the slide # 16 in the "ARM Toolchain"
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

  int num, res;

  /* Enter a number */
  printf("Enter a number: ");
  scanf("%d", &num);

  /* Store the input value into the register eax */
  asm("movl %0, %%eax;" : : "b" (num));

  /* Store the value 5 into the register ebx */
  asm("movl $5, %ebx;");

  /* Add the registers */
  asm("addl %ebx, %eax");

  /* Store the result into the corresponding variable */
  asm ("movl %%eax, %0;" : "=a" (res));
  printf("Result: %d\n", res);

  return 0 ;

}
