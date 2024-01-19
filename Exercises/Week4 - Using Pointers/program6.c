/*!
 * @file    program6.c
 * 
 * @brief   This program accompanies the slide # 15 in the "Using pointers"
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
#include <getopt.h>
#include <stdlib.h>
#include <stdio.h>

/* Short description for the arguments */
static const char short_options[] = "n:u:h";

/* Long description for the arguments */
static struct option long_options[] = {

  {"number",    required_argument, NULL, 'n'},
  {"until",     required_argument, NULL, 'u'},
  {"help",      no_argument,       NULL, 'h'},
  {0, 0, 0, 0},

};

static int opts_parse(int argc, char *argv[], int *num, int *up) {

  int opt;

  while ((opt = getopt_long(argc, argv, short_options, long_options, 0)) != -1) {

    switch (opt) {

      case 'n':
        *num = atoi(optarg);
        break;

      case 'u':
        *up = atoi(optarg);
        break;

      case 'h':
        printf("Usage: %s [options]\n\n"
               "Version 1.0\n"
               "Options:\n"
               "-n | --number\t  Number for which compute the multiplication table [%d]\n"
               "-u | --until\t  Up to which number the multiplication is performed [%d]\n"
               "-h | --help\t  Print this message\n\n"
               "Example:\n~$ %s -n 4 -u 15\n"
               "~$ %s --number 4 --until 15\n\n",
               argv[0], *num, *up, argv[0], argv[0]);
        exit(0);

      default:
        printf("ERROR: Argument not recognized.\n"); 
        exit(0);

    }

  }

  return optind;

}

int main(int argc, char *argv[]) {

  int number = 1;
  int until = 10;

  opts_parse(argc, argv, &number, &until);

  for(int i = 1; i <= until; i++)
    printf("%d x %d = %d\n", number, i, number * i);


  return 0;

}
