/**
 ***********************************************************************************
 *
 *
 * Exam of Embedded Systems 2
 * Date: November 7th 2023
 * Time: 11:00 - 13:30
 *
 * TODO: Exercise 1A
 * Student's name: Lars Grit
 * Student's number: 500906332
 *
 *
 * Preface:
 *
 * In this exam you will simulate the behavior of a basic flood barrier system
 * to be deployed in the city. Your system will consider the following hardware
 * components:
 *
 *   Potentiometer:  A three-terminal variable resistor which simulates the
 *                   sensor for the water level.
 *   Barrier LED:    A single LED which indicates the behavior (stays low,
 *                   raising slow or raising fast) of the barrier.
 *
 * The system monitors the working behavior of a basic flood barrier system. A
 * water level sensor indicates the amount of water accumulating in the system.
 * When the water has reached a certain level (LOW/MEDIUM), the system must be
 * activated, starting to slowly close the barrier to prevent more water to
 * come in. If a second level is reached (MEDIUM/HIGH), the closing speed must
 * be incremented to avoid further damages in the city. While the barrier is
 * closing, either slow or fast, the corresponding LED indicates such operation
 * by blinking at a specific frequency.
 *
 *
 * IMPORTANT: WHEN YOU HAVE FINISHED, DELIVER THE MAIN FOLDER CONTAINING YOUR
 *            COMPLETE PROJECT!! COPY THE flood_barrier DIRECTORY AND PASTE IT
 *            ON YOUR USB STICK!
 *
 * Good luck!
 *
 *
 ***********************************************************************************
 *
 * EXERCISES:
 *
 * Exercise 1: Getting started
 *
 * 1A: Enter your name and student number in the lines at the beginning of this
 *     file.
 *
 * 1B: Create a new (empty) project for your exam. Call this project
 *     "flood_barrier" and look carefully where this is stored. Copy the
 *     content of this file with the exercises and code in the main.c file of
 *     your project.
 *
 * 1C: If you are using the ESP32 board, you will have to provide the wiring
 *     diagram of your project using Fritzing or any other tool. The wiring
 *     diagram must be included in the project that you will deliver. Do not
 *     forget to copy it in the USB stick.
 *
 *     If you are using the PSoC board, the wiring diagram must be completed
 *     in the top-design area of your project.
 *
 * 1D: If the water level has not changed, there is no need to do w. 
 *     We might as well wait for a while until we check the water level
 *     again. Fill in the code in the main loop to let the program sleep for a
 *     while before we check the water level again. How long do you let the
 *     program sleep?
 *
 *
 ***********************************************************************************
 * 
 * Exercise 2: Declarations
 * 
 * Before starting your project, you are going to declare some elements
 * (variables, structures, enumerations, etc.) that will help you to develop
 * your solution.
 *
 * 2A: Your system should recognize/handle, at least, 3 different levels for
 *     the water: LOW, MEDIUM and HIGH. Declare an enumeration to handle these
 *     three levels. Use the typedef keyword to create your own data type for
 *     the levels.
 *
 * 2B: Your system should recognize/handle, at least, 3 status for the barrier:
 *     DOWN, RAISING SLOW and RISING FAST. Define an enumeration to handle
 *     these three different barrier status. Use the typedef keyword to create
 *     your own data type for the barrier status.
 *
 * 2C: Create your own structure, called flood_barrier_t, to represent your
 *     system. This structure must contain the most important information of 
 *     your system. Explain what and why did you choose to be part of your
 *     structure.
 *
 *         Explanation: I have created a struct with the waterLevel and BarrierStatus
 *
 *
 * 2D: Define a local variable, called barrier, to represent your system.
 *     Initialize this variable with your desired information.
 *
 * 2E: Define a local variable, called cur_water_level, to represent the
 *     current level of water in the city. Initialize this variable with your
 *     desired information.
 *
 *
 ***********************************************************************************
 * 
 * Exercise 3: Water level sensing
 * 
 * The system has to sense the current water level. We simulate this with the
 * use of a variable resistor (potentiometer) from your kit. 
 *
 * 3A: Connect the variable resistor to you board (ESP32 or PSOC) such that you
 *     will be able to read its setting. Draw in your Fritzing project (or in
 *     the top-design, if you are using PSoC) how you have connected your
 *     resistor.
 *
 * 3B: Complete the code of the function readWaterSensor() to read the resistor
 *     value. 
 *
 * 3C: Complete the code of the function convertReadingIntoHeight() to convert
 *     the resistor value into a height value between 0.0 and 1.5 meters
 *
 * 3D: Use two macros to define the amount of water that separate the LOW and
 *     the MEDIUM levels, and the MEDIUM and HIGH levels.
 *
 * 3E: Complete the code of the function obtainWaterLevel() to convert the
 *     height reading into a water level. Use the macros that you defined in
 *     the previous question.
 *
 * 3F: As mentioned in Exercise 1D, the system only works when the water level
 *     has changed (e.g., when there is a difference between the water level
 *     stored in the system and the current water level). Complete the
 *     IF-THEN-ELSE statement to ensure that the system works when the water
 *     level has changed.
 *
 * 3G: It is important to keep the system updated. Whenever the water level
 *     changes, that information must be updated in the system so the system
 *     can always work in the desired way. Ensure that the current water level
 *     is properly updated.
 *
 *
 ***********************************************************************************
 * 
 * Exercise 4: Barrier Behavior Indication
 *
 * The behavior of the barrier has to be indicated with a single LED:
 *   LED STAYS ON:    Barrier stays in low position.
 *   LED BLINKS SLOW: Barrier is raising slow.
 *   LED BLINKS FAST: Barrier is raising fast.
 *
 * The blinking rate of the LED should be controlled by a PWM module
 *
 * 4A: Connect a LED to your board (ESP32 or PSOC) to be used for the barrier
 *     indicator. Draw in your Fritzing project (or in the top-design, if you
 *     are using PSoC) how you have connected your LED.
 *
 * 4B: Configure a PWM module and connect it to your LED. Explain the choices
 *     you have made for your PWM module: I have created a define for a vTaskDelay with a fast and slow value for blinking the light
 *
 *       Fast blinking frequency and corresponding PWM duty cycle setting:
 *       Slow blinking frequency and corresponding PWM duty cycle setting:
 *
 * 4C: Complete the code of the function setBarrierStatus() such that the
 *     status (behavior) of the barrier is properly updated. DO NOT modify the
 *     signature of this function.
 *
 * 4D: Complete the code of the function setBarrierIndicator() such that the 
 *     barrier indicator LED performs the correct function. DO NOT modify the
 *     signature of this function.
 *
 * 4E: Complete the code corresponding to the proper calling of the functions
 *     implemented in Exercises 4C and 4D. DO NOT modify the signature of such
 *     functions.
 *
 *
 ***********************************************************************************
 *
 * Exercise 5: Theoretical Questions
 *
 * 5A: Assume that you are compiling a program in your computer and you obtain
 *     the following error message:
 *
 *          $ gcc main.c 
 *            /tmp/ccoXhwF0.o: In function `main':
 *            main.c:(.text+0x15): undefined reference to `readActivationSensor'
 *            collect2: error: ld returned 1 exit status
 *          $
 *
 *     At which stage of the compilation process is this error recognized?
 *     What is the most probable cause for this type of errors?
 *
 * 5B: A difference between RISC and CISC architectures is given by the number
 *     of bits used to encode the instructions: fixed or variable. Explain this
 *     concept using your own words and how it affects the design of the
 *     processor.
 *
 * 5C: Assuming the following statement:
 *
 *       typedef union em2 {
 *         double num[10];
 *         char msg[20];
 *       } em2_t;
 *
 *     What will print out the instruction: printf("%ld", sizeof(em2_t))?
 *     If we change the declaration to: typedef struct em2. What will print now
 *     the previous instruction?
 *
 * 5D: Regarding structures in C. When do you use the "arrow" operator (->) and
 *     when the "dot" (.) operator.
 *
 * 5E: What does it mean "passing arguments by reference" to a C function? Why
 *     this approach consumes less memory space?
 *
 *
 * REMINDER: Hand in the main folder ("flood_barrier") of your complete
 *           project!!
 *
 *
 ***********************************************************************************/
#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"
#include "driver/adc.h"

#define MAX_HEIGHT 1.5
#define MEDIUM_HEIGHT 0.5
#define HIGH_HEIGHT 1.0
#define LED_PIN 13
#define LED_FAST 0.1
#define LED_SLOW 1.0

typedef enum {
    LOW,
    MEDIUM,
    HIGH
} WaterLevel;

typedef enum {
    DOWN,
    RISING_SLOW,
    RISING_FAST
} BarrierStatus;

typedef struct {
    WaterLevel waterLevel;
    BarrierStatus barrierStatus;
} flood_barrier_t;

void app_main() {

  flood_barrier_t barrier;
  barrier.waterLevel = LOW;
  barrier.barrierStatus = DOWN;

  WaterLevel cur_water_level = LOW;
  
  /* Initialize/Startup your components */
  initComponents();

  for (;;) {

    /* Obtain the current water level */
    cur_water_level = obtainWaterLevel();

    if (cur_water_level != barrier.waterLevel) {

      /* TODO: Exercise 4E
       * Complete the function calling according to the function's signature.
       */

      barrier = (cur_water_level, barrier);
      setBarrierStatus(&barrier);
      setBarrierIndicator();
      
      barrier.waterLevel = cur_water_level;

    }

    /* The water level has not changed, sleep for a while */
    else { 
      vTaskDelay(5000 / portTICK_PERIOD_MS);
    }

  }

}



/**
 ******************************************************
 *
 * IMPLEMENTATION
 * 
 * Please, implement your functions here.
 *
 * Attention: Under no circumstances, NEVER!!!, move this section to a
 * different part of the file.
 *
 * Additionally, as mentioned in class. DO NOT USE GLOBAL VARIABLES!
 *
 ******************************************************
 */

void initComponents(void) {

  /* Put here the initialization code of your components */
  adc1_config_width(ADC_WIDTH_BIT_12);
  adc1_config_channel_atten(ADC1_CHANNEL_3, ADC_ATTEN_DB_11);
  gpio_set_direction(LED_PIN, GPIO_MODE_OUTPUT);
}


int readWaterSensor() {
  int sensor_reading = adc1_get_raw(ADC1_CHANNEL_3);
  return sensor_reading;
}

// values for potentiometer
#define ADC_MAX_VALUE 4095  // Maximum ADC reading for 12-bit resolution
#define MAX_HEIGHT 1.5

convertReadingIntoHeight() {

  /* Temporary initialization for debugging purposes */
  float height = 0.35;

  int sensor_reading = readWaterSensor();

  // Map the ADC reading to the range [0.0, 1.0]
  float normalized_reading = (float)sensor_reading / ADC_MAX_VALUE;

  // Map the normalized reading to the desired height range [0.0, 1.5]
  float height = normalized_reading * MAX_HEIGHT;

  return height;
}


obtainWaterLevel() {
  WaterLevel level = LOW;

  float height = convertReadingIntoHeight();

  if (height < MEDIUM_HEIGHT)
  {
    level = LOW;
  } else if (height < HIGH_HEIGHT) 
  {
    level = MEDIUM;
  } else 
  {
    level = HIGH;
  }

  return level;
}

setBarrierStatus(cur_water_level, flood_barrier_t *barrier) {
  if (cur_water_level == LOW)
  {
    barrier->barrierStatus = DOWN;
  } else if(cur_water_level == MEDIUM)
  {
    barrier->BarrierStatus = RISING_SLOW;
  } else {
    barrier->BarrierStatus = RISING_FAST;
  }
  
}

setBarrierIndicator(flood_barrier_t *barrier) {
  if (barrier->barrierStatus == DOWN) {
    gpio_set_level(LED_PIN, 1);
  } else if(barrier->barrierStatus == RISING_SLOW)
  {
    gpio_set_level(LED_PIN, 0);
    vTaskDelay(LED_SLOW / portTICK_PERIOD_MS);
    gpio_set_level(LED_PIN, 1);
    vTaskDelay(LED_SLOW / portTICK_PERIOD_MS);
  } else {
    gpio_set_level(LED_PIN, 0);
    vTaskDelay(LED_FAST / portTICK_PERIOD_MS);
    gpio_set_level(LED_PIN, 1);
    vTaskDelay(LED_FAST / portTICK_PERIOD_MS);
  }
}


/* [] END OF FILE */
