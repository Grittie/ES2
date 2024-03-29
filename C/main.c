/**
 ***********************************************************************************
 *
 *
 * Programming Exercises for Embedded Systems 2
 *
 *
 * Preface:
 *
 * In this example exam you will simulate the behavior of an anti-missiles
 * shield operating on a conflict area. A proximity sensor indicates the 
 * approach of a missile to the city. In this exercise, this sensor is
 * simulated by you, manually entering the distance between the city and the
 * missile.
 *
 * The distance between city and the missile determines the status of the
 * system. The missile can have 5 different status from which 3 status
 * (UNDETECTABLE, DETECTED and INTERCEPTABLE) depend on the distance, and 2
 * status (INTERCEPTED and NOT_INTERCEPTED) depend on the outcome of the
 * preventive actions.
 *
 * When the missile has been detected by the sensor, the system must be
 * activated (simulated by showing a message), enabling the anti-missile shield
 * and preparing the interception phase.
 *
 * When the missile is within interception range, the interception missiles are
 * fired (simulated by showing a message) and the system have to analyze the
 * result. If the missile was intercepted (randomly decided by you), then the
 * system indicates the success of the shield and it goes back to normal.
 *
 * If the missile was not intercepted, then the system shows the corresponding
 * message and instructs the user to fire the evacuation alarm (pressing
 * CTRL-Z). This will generate a software interrupt (a signal) that must be
 * handled properly to print an evacuation message.
 *
 * Remember that you have a reasonable amount of freedom to implement your
 * solution and solve the project. However, I am expecting to read a brief
 * explanation on your procedure.
 *
 * Also consider that your solution MUST NOT USE GLOBAL VARIABLES. Find better
 * alternatives in your programming. You are only allowed to use 1 global
 * variable to interact with the interrupt.
 *
 * Good luck!
 *
 *
 ***********************************************************************************
 *
 * EXERCISES:
 *
 * Detection phase
 * 
 * The system has to sense the proximity of the missile. You simulate this by
 * manually entering the distance when asked by the system. As soon as a
 * missile has been detected by your system, an alarm message should indicate
 * it.
 *
 *  1: Complete the code of the function readProximitySensor() to ask the user
 *     and read the distance from the keyboard. Define your own signature for
 *     the function, explaining how does it help you in your proposed solution.
 *
 *       Explanation: I have designed the read promixity sensor to be prepared for overloads. Utilizing a do-while
 *                    to repeatedly promt the user until a valid integer is inputted. This way it handles both integers 
 *                    outside of the pre determined scope and invalid inputs like strings.
 *
 *
 *  2: Define two thereshold values to setup the distance-dependent status.
 *     For instance: the missile is UNDETECTABLE until it passes a certain
 *     threshold (read from the proximity sensor) and then it becomes DETECTED.
 *     In the same way, after a certain threshold it passes from DETECTED to
 *     INTERCEPTABLE. These 3 states depend on the distance read from the
 *     proximity sensor; hence, you need two thereshold values.
 *
 * 
 *  3: Complete the code of the function determineMissileStatus() to establish
 *     the status of the missile. Make sure you use the previously defined
 *     macros. Define your own signature for the function, explaining how does
 *     it help you in your proposed solution.
 *
 *       Explanation: For this function I have set up a few macros. To begin I have defined UNDETECTABLE, DETECTABLE and INTERCEPTABLE
 *                    as 1, 2 and 3. This makes the setMissleIndicator function more readable because I can return these macros instead of integers, 
 *                    removing magic numbers and making my code more readable. I have also set a macro for the thresholds for the INTERCEPTABLE and DETECTABLE status.
 *                    The function simply checks if the distance given from the proximity sensor is below these thresholds and then returns the correct status.
 *
 *
 *  4: Complete the code of the function setMissileIndicator() such that the
 *     user receives an alarm message indicating the status of the system.
 *     Define your own signature for the function, explaining how does it help
 *     you in your proposed solution.
 *
 *       Explanation: In this function I give the missleStatus as an arguement, these are the defined macros in the previous function.
 *                    The switch case simply checks what status out of the 3 these are and prints the notification accordingly.
 *
 *
 * After the missile has been detected and it is in interception range, you can
 * proceed to launch your interception missiles. This is an automatic process
 * triggered by the status of the missile. Launching your own missiles is
 * simulated by a message.
 *
 *  5: After "firing" the interceptors, you could pass to the next phase:
 *     confirming whether the missile was destroyed or not. This confirmation
 *     relies on a random process (use a uint8_t data type for the generated
 *     number). The general idea is that some times (randomly), the missile
 *     will be intercepted; while some other times, it will not. Evidently, this
 *     result will affect the status of the system. Complete the code of the
 *     function fireMissileInterceptor() to solve this issue. Define your own
 *     signature for the function, explaining how does it help you in your
 *     proposed solution.
 *
 *       Explanation: for the fireMissileInterceptor() function I simply create a uint8_t variable called randomResult
 *                    that calls the srand() (we use srand() instead or rand() because rand() is not truly random and actually uses a seed) 
 *                    and modulos by 2 to either get a random 1 or 2 result. The result decided if the missile is intercepted or not.
 *
 *
 *  6: In the cases in which the missile was successfully destroyed, then your
 *     system has to go back to its initial status to continue monitoring the
 *     approach of other missiles. On the other hand, if the missile was not
 *     destroyed, then you should alert the user to fire the alarm for
 *     evacuation. Complete the code of the function confirmInterception() to
 *     solve this issue. Define your own signature for the function, explaining
 *     how does it help you in your proposed solution.
 *
 *       Explanation: The confirmInterceptionFunctiong gets a integer from fireMissleInterceptor that tells it if the missile
 *                    was intercepted or not, I can now implement further logic into this function,
 *
 *
 * Assuming the worst-case scenario, the missile could not be destroyed and it
 * will hit the city. Therefore, the operators have to trigger a notification
 * (pressing CTRL-Z) to the inhabitants to evacuate their homes and move to the
 * closest underground shelter. This behavior is modeled using a software
 * interrupt (a signal).
 *
 *  7: Complete the code of the interruptServiceRoutine() function to trigger
 *     the activation of the evacuation alarm. The alarm will consists on
 *     priting 5 times a message and terminating the program. Feel free to
 *     implement this code as you wish (add the required code in this project).
 *     Additionally, explain your solution here.
 *
 *       Explanation: I have added prints to the interruptServiceRoutine to showcase the urgancy of the situation and then I exit the program
 *                    by calling the exit(EXIT_FAILURE) function. In the confirmInterception when the missile is not intercepted the program sends out the notification
 *                    and tells the user to press CRTL-Z, the program has a while loop to wait for the user to terminate the program witha a usleep to avoid high CPU usage.
 *
 *
 *  8: Update the code to ensure that the sensor reading (the distance that you
 *     enter) follows a reasonable pattern. The missile is approaching; hence,
 *     the distance should decrease at each iteration. Define a structure for
 *     the missile which keeps the following information of the missile: id,
 *     status, previous distance and current distance. Use these previous and
 *     current distances to validate that the missile is actually approaching
 *     the city.
 *
 *
 *  9: Update your code to accept command line arguments. Include 2 different 
 *     options that the user can setup from the command line:
 * 
 *       a) Extracting bits option (-b or --bits): Using this argument, the user
 *          can choose which implementation to execute for deciding whether the
 *          interceptor missile destroyed the missile or not. The default
 *          executed code was implemented in Exercise 5; hence, when the main
 *          program is executed without the -b argument, then your program
 *          executes the solution of Exercise 5. If the user executes the main
 *          program with the -b argument, then your program will execute the
 *          solution of Exercise 10.
 * 
 *       b) Multiple missiles option (-m or --multiple): Using this argument,
 *          the user can decide whether the system can track 1 or more than 1
 *          missiles. The default code deals with 1 single missile. On the other
 *          hand, when executed with the -m argument, the program should act
 *          according to the Exercises 11-14.
 * 
 * 
 * 10: Update your code to allow the user to choose the way in which it is
 *     decided whether the missile was intercepted or not. The alternative
 *     implementation has to extract the 4 bits at the center of the original
 *     number (the original string of 8 bits) and use those 4 bits for the
 *     decision. If the new number (4 bits number) is smaller or equal than 7,
 *     then the missile was intercepted; otherwise, the missile was not
 *     intercepted.
 * 
 *     Therefore, do not overwrite your solution to Exercise 5 (the function
 *     fireMissileInterceptor() must remain). Instead, use your implementation
 *     of Exercise 9 to decide which version of the code will be executed. If
 *     the user selects the "decimal" version, then you execute the code from
 *     Exercise 5. If the user does not select the "decimal" version, then you
 *     execute the above implemented alternative.
 * 
 *     Complete the code of the function extractDecisionBits() to solve this 
 *     issue. Define your own signature for the function, explaining how does it
 *     help you in your proposed solution.
 *     
 * 
 * 11: Assume that your system is able to detect multiple missiles. When the
 *     system is launched, the user is asked to enter the maximum number of
 *     missiles that the system can detect. Then, the system automatically
 *     monitors the approaching missiles and takes the appropriate actions.
 *     Implement the code that allows the user to enter the maximum number of
 *     missiles and creates an array of missiles to be handled. Feel free to
 *     implement this code as you wish (add the required code in this project).
 *     Additionally, explain your solution here.
 *
 *       Explanation:
 *
 *
 * 12: When dealing with multiple missiles, your system operates in an automatic
 *     fashion. The user is no longer required to enter the distance of the
 *     missiles, but the distances for each missile have to be generated from a
 *     random process (ensuring that the distance decreases every time). Define
 *     a macro to determine the maximum possible decrement and implement the
 *     code that computes a new distance (for each missile) at each iteration.
 *     Feel free to implement this code as you wish (add the required code in
 *     this project). Additionally, explain your solution here.
 *
 *       Explanation:
 *
 *
 * 13: Since now you are dealing with, possibly, multiple missils, your entire
 *     code must be updated to handle the array of missile . Be sstructuresure
 *     that you update the code without breaking the already implemented
 *     functionality. The system must be tested to work while detecting only
 *     one missile but also when handling multiple ones.
 * 
 * 
 * 14: Ensure that every single function that you wrote has the proper (and
 *     accurate) documentation. Follow the examples provided in the utilities.h
 *     and periodic_tasks.h files. Your function documentation should consists
 *     of:
 * 
 *       /// @brief One-line description of the function.
 *       ///
 *       /// More detailed explanation of the function including any possible
 *       /// design decision that must be useful to understand the code.
 *       ///
 *       /// @param p1:  name and brief description of the parameter.
 *       /// @param p2:  name and brief description of the parameter.
 *       ///
 *       /// @return brief description of the returning value.
 *
 *
 ***********************************************************************************/

#include "periodic_tasks.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <signal.h>
#include <unistd.h>
#include <getopt.h>
#include <time.h>

#define MAX_MISSILES 10  // Adjust the maximum number of missiles as needed
#define MAX_DECREMENT 100
#define MAX_ALLOWED_DISTANCE 10000
#define MIN_ALOWED_DISTANCE 0

// Define symbolic constants for missile status
#define UNDETECTABLE 1
#define DETECTABLE 2
#define INTERCEPTABLE 3

// Maximum distance for the missile to be interceptable and detectable
#define INTERCEPTABLE_THRESHOLD 100
#define DETECTABLE_THRESHOLD 1000

#define FIRE_MISSILE 1


struct Missile {
  int id[MAX_MISSILES];               // Unique identifier for the missile
  int status[MAX_MISSILES];           // Status of the missile
  int prevDistance[MAX_MISSILES];     // Previous distance of the missile
  int currentDistance[MAX_MISSILES];  // Current distance of the missile
  int maxMissiles;                    // Maximum number of missiles the system can handle
};

/* Interrupt Service Routine for the CTRL-Z signal */
void interruptServiceRoutine(int s) {
  // Trigger the evacuation alarm
  printf("\nEVACUATION ALARM: Seek shelter immediately! Missile impact imminent!\n");

  // Print the message five times for emphasis
  for (int i = 0; i < 5; ++i) {
    printf("EVACUATE!\n");
  }

  // Terminate the program
  exit(EXIT_FAILURE);
}

/* Declaring functions */
int readProximitySensor(struct Missile *missile, int index);
int determineMissileStatus(int distance);
void setMissileIndicator(int missileStatus);
int fireMissileInterceptor();
void confirmInterception(int interceptionResult, struct Missile missiles[], int index, int multipleOption);
int extractDecisionBits();



int main(int argc, char *argv[]) {
  struct periodic_task *task;

  // Variables to toggle bits mode or multiple modes
  int bitsOption = 0;
  int multipleOption = 0;

  // Parse command line arguments
  int opt;
  while ((opt = getopt(argc, argv, "bm")) != -1) {
    switch (opt) {
      case 'b':
        bitsOption = 1;
        printf("b option has been selected\n");
        break;
      case 'm':
        printf("m option has been selected\n");
        multipleOption = 1;
        break;
      default:
        fprintf(stderr, "Usage: %s [-b] [-m]\n", argv[0]);
        exit(EXIT_FAILURE);
    }
  }

  /* This will ignore the Ctrl+Z behavior and it will call the ISR */
  signal(SIGTSTP, interruptServiceRoutine);

  /* Define the periodic timer to make the program sleep */
  task = start_periodic_timer(0, 25 * NSEC_PER_SEC);

  /* Check that the timer was properly created */
  if (task == NULL) {
    printf("ERROR: Start periodic timer!\n");
  }

  if (multipleOption) {
    // Inside main function after parsing command line arguments
    struct Missile missiles[MAX_MISSILES];

    printf("Enter the maximum number of missiles the system can detect: ");
    scanf("%d", &missiles[0].maxMissiles);

    if (missiles[0].maxMissiles <= 0 || missiles[0].maxMissiles > MAX_MISSILES) {
      printf("Invalid input for the maximum number of missiles. Exiting.\n");
      exit(EXIT_FAILURE);
    }

    // Initialize missile data for multiple missiles
    for (int i = 0; i < missiles[0].maxMissiles; ++i) {
      missiles[i].id[i] = i + 1;  // Assign unique identifier
      missiles[i].status[i] = UNDETECTABLE;  // Initial status
      missiles[i].prevDistance[i] = 0;  // Initial previous distance
      missiles[i].currentDistance[i] = 0;  // Initial current distance(s)
    }

    for (;;) {
      /* Wait for the next activation */
      wait_next_periodic_activation(task);

      // Inside a function where the 'missiles' array is defined and initialized
      srand(time(NULL));  // Seed the random number generator

      /* Update the distances for each missile */
      for (int i = 0; i < missiles[0].maxMissiles; ++i) {
        // Generate a random distance decrement for each missile
        int decrement = rand() % (MAX_DECREMENT - 100 + 1) + 100;

        if (i == 0) {
            // First missile, generate a random distance without any constraints
            missiles[i].currentDistance[i] = rand() % (MAX_ALLOWED_DISTANCE + 1);
        } else {
            // Subsequent missiles, ensure at least 100 less than the previous missile
            int maxPossibleDistance = missiles[i - 1].currentDistance[i - 1] - 100;
            missiles[i].currentDistance[i] = rand() % (maxPossibleDistance + 1);
        }

        // Update previous distance
        missiles[i].prevDistance[i] = missiles[i].currentDistance[i];
      }
      
      /* Print the distances for each missile */
      printf("\nDistances for each missile:\n");
      for (int i = 0; i < missiles[0].maxMissiles; ++i) {
        printf("Missile %d: %d\n", missiles[i].id[i], missiles[i].currentDistance[i]);
      }

      /* Update the status of each missile */
      for (int i = 0; i < missiles[0].maxMissiles; ++i) {
        missiles[i].status[i] = determineMissileStatus(missiles[i].currentDistance[i]);
      }

      /* Notify the user about each missile */
      for (int i = 0; i < missiles[0].maxMissiles; ++i) {
        setMissileIndicator(missiles[i].status[i]);
      }

      /* Attempt to destroy each missile */
      for (int i = 0; i < missiles[0].maxMissiles; ++i) {
        if (missiles[i].status[i] == INTERCEPTABLE) {
          int interceptionResult;
          if (bitsOption == 0) {
            // Default implementation
            printf("normal implementation\n");
            interceptionResult = fireMissileInterceptor();
          } else {
            // Alternative implementation
            printf("-b implementation\n");
            interceptionResult = extractDecisionBits();
          }

          /* Reset the system */
          confirmInterception(interceptionResult, missiles, i, multipleOption);
        }
      }
      break;
    }

  } else {
    // Original single missile implementation
    struct Missile missile;
    missile.maxMissiles = 1;  // Default to handling a single missile

    for (;;) {
      /* Wait for the next activation */
      wait_next_periodic_activation(task);

      /* Read the measurement from the proximity sensor */
      missile.prevDistance[0] = missile.currentDistance[0];  // Update previous distance
      missile.currentDistance[0] = readProximitySensor(&missile, 0); // Read current distance


      /* Update the status of the missile */
      missile.status[0] = determineMissileStatus(missile.currentDistance[0]);

      /* Notify the user about the missile */
      setMissileIndicator(missile.status[0]);

      /* Attempt to destroy the missile */
      if (missile.status[0] == INTERCEPTABLE) {
        int interceptionResult;
        if (bitsOption == 0) {
          // Default implementation
          printf("normal implementation\n");
          interceptionResult = fireMissileInterceptor();
        } else {
          // Alternative implementation
          printf("-b implementation\n");
          interceptionResult = extractDecisionBits();
        }

        /* Reset the system */
        confirmInterception(interceptionResult, &missile, 0, multipleOption);
      }
    }
  }

  /* Release the allocated memory */
  return 0;
}
/**
 * Function: readProximitySensor
 * ------------------------------
 * Asks the user to enter the distance of a missile for the proximity sensor.
 * The function continues to prompt until a valid integer within the allowed range
 * (set by the define MAX_ALLOWED_DISTANCE) is provided. It also handles invalid inputs
 * by informing the user and clearing the input buffer.
 *
 * @param struct Missile *missile: Pointer to the Missile structure.
 * @return int: The valid distance entered by the user.
 */


int readProximitySensor(struct Missile *missile, int index) {
  int missileDistance;

  do {
    // Ask the user to enter the distance of the missile
    printf("\nEnter distance of missile %d: ", index + 1);

    // Read the entered distance from the user
    if (scanf("%d", &missileDistance) != 1) {
      // If the user fails to input an integer, let them know
      printf("Invalid input. Please provide a valid integer.\n");
      // Clear the input buffer
      while (getchar() != '\n');
      // Set the distance to 0 to request missile distance again
      missileDistance = 0;
    }

    if (missileDistance > MAX_ALLOWED_DISTANCE) {
      printf("Entered distance exceeds the maximum allowed distance. Please input distance again.\n");
    } else if (missile->currentDistance[index] > 0 && missileDistance > missile->currentDistance[index]) {
      printf("Warning: The missile should be approaching, but the entered distance is greater than the current distance.\n");
      printf("Try to input a lower distance.\n");
      missileDistance = 0;
    }
  } while (missileDistance > MAX_ALLOWED_DISTANCE || missileDistance <= 0);

  // Print the entered distance
  printf("\nDistance of missile %d is: %d\n", index + 1, missileDistance);

  return missileDistance;
}


/**
 * Function: determineMissileStatus
 * --------------------------------
 * Determines the status of the missile based on the provided distance.
 * The function uses predefined macros for threshold values.
 *
 * @param int distance: The distance of the missile from the proximity sensor.
 * @return int: The status of the missile (UNDETECTABLE, DETECTABLE, INTERCEPTABLE).
 */
int determineMissileStatus(int distance) {
  if (distance > DETECTABLE_THRESHOLD) {
    return UNDETECTABLE;
  } else if (distance > INTERCEPTABLE_THRESHOLD) {
    return DETECTABLE;
  } else {
    return INTERCEPTABLE;
  }
}

/**
 * Function: setMissileIndicator
 * ------------------------------
 * Sets the missile indicator based on the status of the missile system.
 * The function takes the status as a parameter and prints an alarm message accordingly.
 *
 * @param int missileStatus: The status of the missile system (undetectable, detectable, interceptable).
 */
void setMissileIndicator(int missileStatus) {
  switch (missileStatus) {
    case UNDETECTABLE:
      printf("ALARM: Missile is undetectable. Activate anti-missile shield!\n");
      break;
    case DETECTABLE:
      printf("ALARM: Missile is detectable. Prepare for interception!\n");
      break;
    case INTERCEPTABLE:
      printf("ALARM: Missile is interceptable. Launch interception missiles!\n");
      break;
    default:
      printf("ALARM: Unknown missile status. Take appropriate action!\n");
  }
}

/**
 * Function: fireMissileInterceptor
 * -------------------------------
 * Simulates the firing of interception missiles and determines whether
 * the missile has been intercepted based on a random process.
 * @return int: 1 if the missile was intercepted, 0 otherwise.
 */

int fireMissileInterceptor() {
  printf("ALARM: FIRING INTERCEPTION MISSILES\n");

  // Seed the random number generator with the current time
  srandom(time(NULL));

  // Generate a random number (0 or 1)
  uint8_t randomResult = random() % 2;

  if (randomResult == 1) {
    printf("SUCCESS! THE MISSILE HAS BEEN INTERCEPTED!\n");
    return 1;
  } else {
    printf("ALARM! THE MISSILE HAS NOT BEEN INTERCEPTED!\n");
    return 0;
  }
}

/**
 * Function: extractDecisionBits
 * -----------------------------
 * Simulates the extraction of 4 bits from a random 4-bit number, 
 * representing the center bits of an 8-bit number. 
 * The function then determines whether the extracted number is smaller
 * or equal to 7, simulating the interception decision process.
 * @return int: 1 if the simulated missile was intercepted, 0 otherwise.
 */
int extractDecisionBits() {
  printf("\ncurrently in extractDecisionBits\n");

  // Seed the random number generator with the current time
  srand(time(NULL));

  // Extract the 4 bits at the center of the original number (the original string of 8 bits)
  uint8_t randomResult = rand() % 16;  // Fix: Use 16 to get a number between 0 and 15
  uint8_t extractedBits = (randomResult >> 2) & 0x0F;

  printf("\nExtractedBits: %d", extractedBits);

  // If the new number (4 bits number) is smaller or equal to 7, then the missile was intercepted
  if (extractedBits <= 7) {
    printf("\nThe new 4 bit number is smaller or equal to 7");
    return 1;
  } else {
    printf("\nThe new 4 bit number is NOT smaller or equal to 7");
    return 0;
  }
}

/**
 * Function: confirmInterception
 * ------------------------------
 * Confirms the interception result and takes appropriate actions.
 * If the missile was successfully intercepted, reset the system.
 * If the missile was not intercepted, alert the user for evacuation. 
 * and wait for the user to interupt the program.
 */
void confirmInterception(int interceptionResult, struct Missile missiles[], int index, int multipleOption) {
  if (interceptionResult) {
    printf("SUCCESS! The missile has been intercepted. Resetting the system.\n");
    missiles[index].prevDistance[index] = 0;  // Set prevDistance to a suitable value
    missiles[index].currentDistance[index] = 0;  // Set currentDistance to a suitable value
  } else {
    printf("ALERT: Evacuate all residents of the city immediately!\n");
    printf("Press CTRL-Z to trigger the evacuation alarm.\n");

    while (1) {
      // Sleep for a short duration to avoid high CPU usage in the loop
      usleep(500000);
    }
  }
}
/* [] END OF FILE */