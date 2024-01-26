/**
 ***********************************************************************************
 *
 *
 * Exam of Embedded Systems 2
 * Date: January 26th 2024
 * Time: 14:00 - 16:30
 *
 * TODO: Exercise 1A
 * Student's name: Lars Arie Grit
 * Student's number: 500906332
 *
 *
 * Preface:
 *
 * In this exam you will simulate the behavior of a basic robotic welding
 * machine. Your system will consider the following hardware components:
 *
 *   Potentiometer:  A three-terminal variable resistor which determines the
 *                   heat intensity of the welding machine.
 *   Push button:    A button switch that simulates the activation of the
 *                   welding machine.
 *   Welding LED:    A single LED which indicates the operation mode of the
 *                   welding machine.
 *   Heat LEDS:      An array of three LEDs which indicates the level of heat
 *                   intensity of the welding machine.
 *
 * The system monitors the working behavior of a robotic welding system. The
 * user sets the heat intensity (3 different levels: LOW, MEDIUM and HIGH) of
 * the welding machine using the potentiometer (POT). The heat LEDs (HEAT_LEDS)
 * are used to indicate the corresponding level (LOW: 1 LED ON, MEDIUM: 2 LEDs
 * ON and HIGH: 3 LEDs ON).
 * 
 * The welding machine starts working when the push button (SW_WELDING) is
 * pressed and it stops when the push button is pressed again. An interrupt
 * controls this event.
 *
 * The operational mode of the welding machine is shown by the welding LED
 * (WELDING_LED). This LED turns on when the welding machine is in operation
 * and turns off when the machine is off.
 *
 *
 * IMPORTANT: WHEN YOU HAVE FINISHED, DELIVER THE MAIN FOLDER CONTAINING YOUR
 *            COMPLETE PROJECT!! COPY THE welding_machine DIRECTORY AND PASTE
 *            IT ON YOUR USB STICK!
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
 *     file. // DONE
 *
 * 1B: Create a new (empty) project for your exam. Call this project
 *     "welding_machine" and look carefully where this is stored. Copy the
 *     content of this file with the exercises and code in the main.c file of
 *     your project. // DONE
 *
 * 1C: If you are using the ESP32 board, you will have to provide the wiring
 *     diagram of your project using Fritzing or any other tool. The wiring
 *     diagram must be included in the project that you will deliver. Do not
 *     forget to copy it in the USB stick. // DONE
 *
 *     If you are using the PSoC board, the wiring diagram must be completed
 *     in the top-design area of your project.
 *
 * 1D: If the push button has not been pressed, there is no need to do anything. 
 *     We might as well wait for a while until the interrupt is raised. Fill in
 *     the code in the main loop to let the program sleep for a while. // DONE
 *
 *
 ***********************************************************************************
 * 
 * Exercise 2: Setting the heat intensity
 * 
 * The system has to set the current heat intensity of the welding machine. We
 * simulate this with the use of a variable resistor (potentiometer) from your
 * kit. 
 *
 * 2A: Connect the variable resistor to you board (ESP32 or PSOC) such that you
 *     will be able to read its setting. Draw in your Fritzing project (or in
 *     the top-design, if you are using PSoC) how you have connected your
 *     resistor. // DONE
 *
 * 2B: Complete the code of the function readHeatValue() to read the resistor
 *     value.  // DONE
 *
 * 2C: Depending on the configuration of your components, the values read from
 *     your variable resistor will vary. What are the maximum and the minimum
 *     values that you can read from your resistor? // DONE
 *
 *       Maximum: 0
 *       Minimum: 4095 
 *
 * 2D: The system offers 3 heat levels (LOW, MEDIUM and HIGH), hence you have
 *     to define the thereshold values that separate those levels. Use 2 macros
 *     to define the limit values between LOW and MEDIUM, and between MEDIUM
 *     and HIGH. // DONE
 *
 * 2E: Complete the code of the function obtainHeatLevel() to convert the
 *     resistor value into a heat level (LOW, MEDIUM or HIGH) using the
 *     previously defined macros. // DONE
 *
 * 2F: In its current implementation, the system uses a global variable
 *     (cur_heat_level -> Lines 236 and 250) to store the current heat level
 *     and display the heat intensity. However, you know that global variables
 *     should be avoided at all costs; hence, modify the structure of the code
 *     so that it will use a local variable instead. // DONE
 *
 *
 ***********************************************************************************
 * 
 * Exercise 3: Displaying the heat intensity
 *
 * The current setting of the heat intensity has to be indicated by three
 * consecutive LEDs according to the following scheme:
 *
 *       LOW heat level:     1 LED ON
 *       MEDIUM heat level:  2 consecutives LEDs ON
 *       HIGH heat level:    3 consecutives LEDs ON
 *       UNKNOWN heat level: 3 consecutive LEDs OFF
 *
 * 3A: Connect three LEDs to your board (ESP32 or PSOC) to be used for the
 *     intensity indicator. Draw in your Fritzing project (or in the top-design,
 *     if you are using PSoC) how you have connected your LED. // DONE
 *
 * 3B: Fill in the code of the function displayHeatIntensity() to turn on the
 *     LEDs as described in the previous explanation. // DONE
 *
 *
 ***********************************************************************************
 * 
 * Exercise 4: Activating the welding machine
 *
 * When the user has prepared the setup of the welding machine, the welding
 * process can start. By pressing a button switch, the welding machine will
 * be activated. Pressing again the switch will turn off the machine. This
 * behavior must be modeled using an interrupt.
 *
 * When the welding machine is activated/operating, a welding LED (WELDING_LED)
 * will indicate the current operational mode by turning ON. When the welding
 * machine is deactivated/turned off, the WELDING_LED must be OFF.
 *
 * 4A: Connect a button switch to a pin on your board (ESP32 or PSOC). Draw in
 *     your Fritzing project (or in the top-design, if you are using PSoC) how
 *     you have connected your button. // DONE
 *
 * 4B: Connect a LED to your board (ESP32 or PSOC) to be used for the
 *     operational indicator. Draw in your Fritzing project (or in the
 *     top-design, if you are using PSoC) how you have connected your button. // DONE
 *
 * 4C: Complete the code of the Interrupt Service Routine function to trigger
 *     the activation/deactivation of the welding machine. The indicator LED
 *     should be ON/OFF depending of the status. Beware that the heat level
 *     should be reset (UNKNOWN) everytime that the welding machine is OFF. // TO-DO
*
 *
 ***********************************************************************************
 * 
 * Exercise 5: Theoretical Questions
 *
 * 5A: Assume that you have a code using an external library and that you can
 *     decide to use static linking or dynamic linking when compiling. Explain
 *     the advantages and disadvantages of each one and how would affect your
 *     code any update in the library.
 *
 *     Answer: Static linking means including the library code directly into the executable, this means that the executable is larger, but it is not dependent on external libraries. 
 *             Dynamic linking, means not including the library code directly into the executable, this means that the executable is smaller, but it is dependent on external libraries. 
 *
 *
 * 5B: Assuming the following piece of code:
 *
 *       typedef struct em2 {
 *         char student[20];
 *         int grade;
 *       } em2_t;
 *
 *       em2_t student1;
 *       em2_t *student2;
 *
 *     What operator should you use to access the members of student2? ->
 *     What operator should you use to access the members of student1? . 
 *
 * 5C: What are the stack and the heap in the memory? Explain their main
 *     characteristcs.
 *
 *     Answer: The stack is a region of static memory for local variables with a fixed size
 *             The heap is dynamic memory used for data with a size that can change during the program
 *
 *
 * 5D: What is the purpose of the malloc() and free() functions in C? Provide
 *     an example of how to use them.
 *
 *     Answer: malloc() allocates a specified amount of memory on the heap 
 *             free() releases that allocated memory.
 * 
 *     Example:
 *              int *arr = (int *)malloc(5 * sizeof(int));
 *              free(arr);
 *
 *
 * 5E: During the compilation process, the linker is responsible for handling
 *     the defined and undefined symbols. Explain what are these types of
 *     symbols and provide a clear example of each one of them.
 *
 *     Answer: Defined symbols are present in the code and have memory allocated, like variables. 
 *             Undefined symbols are placeholders for values or functions that are resolved by the linker.
 * 
 *      // Defined symbol
 *       int x = 5;
 * 
 *      // Undefined symbol
 *       extern int y;
 *
 *
 * REMINDER: Hand in the main folder ("welding_machine.cydsn") of your complete
 *           project!!
 * 
 ***********************************************************************************/
#include <freertos/FreeRTOS.h>
#include <freertos/task.h>
#include <freertos/semphr.h>
#include <driver/gpio.h>
#include <driver/adc.h>

// Defining all the GPIO pins for the POT and 3 LEDS
#define LED_PIN_1 GPIO_NUM_21
#define LED_PIN_2 GPIO_NUM_47 
#define LED_PIN_3 GPIO_NUM_48
#define POT_CHANNEL ADC1_CHANNEL_3

// Defining all the GPIO pins for the button and interupt LED
#define SW_WELDING GPIO_NUM_40
#define WELDING_LED_PIN GPIO_NUM_6

// Defining MEDIUM and HIGH for to obtain Heat Level
#define MEDIUM 2048
#define HIGH 4095

// Declaring functions
void initComponents();
int readHeatValue();
int obtainHeatLevel();
void displayHeatIntensity();

// enum for the HEAT_LEVEL
typedef enum HEAT_LEVEL {
  LEVEL_UNKNOWN,
  LEVEL_HIGH,
  LEVEL_MEDIUM,
  LEVEL_LOW
} HEAT_LEVEL;

volatile bool weldingMachineActive = false;

void IRAM_ATTR buttonISR(void* arg) {
  HEAT_LEVEL *heat_level = (HEAT_LEVEL *)arg; 

  printf("Button has been pressed.\n");

  weldingMachineActive = !weldingMachineActive;

  if (weldingMachineActive) {
    gpio_set_level(WELDING_LED_PIN, 1);
    *heat_level = LEVEL_UNKNOWN;
  } else {
    gpio_set_level(WELDING_LED_PIN, 0);
    *heat_level = LEVEL_UNKNOWN;
  }
}

// For some reason using ESP-IDF I had to change main to app_main 
int app_main(void) {
    HEAT_LEVEL cur_heat_level = LEVEL_UNKNOWN;
    /* Enable global interrupts */
    gpio_intr_enable(SW_WELDING);

    /* Initialize components */
    initComponents();
    
    for (;;) {
        /* Get the desired heat level */
        cur_heat_level = obtainHeatLevel(&cur_heat_level);
        
        /* Display the heat level */
        displayHeatIntensity(cur_heat_level);

        /* Wait for a while */
        vTaskDelay(1000 / portTICK_PERIOD_MS);
    }
  return 0;
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
 ******************************************************
 */

void initComponents() {
    // Initializing POT
    adc1_config_width(ADC_WIDTH_BIT_12);
    adc1_config_channel_atten(POT_CHANNEL, ADC_ATTEN_DB_11);
    
    // Initializing 3 LEDS to show Heat Level
    gpio_set_direction(LED_PIN_1, GPIO_MODE_OUTPUT);
    gpio_set_direction(LED_PIN_2, GPIO_MODE_OUTPUT);
    gpio_set_direction(LED_PIN_3, GPIO_MODE_OUTPUT);
    
    // Initializing Welding button and LED_PIN
    gpio_set_direction(SW_WELDING, GPIO_MODE_INPUT);
    gpio_set_direction(WELDING_LED_PIN, GPIO_MODE_OUTPUT);

    // Initialiing ISR Service
    gpio_install_isr_service(0);
    gpio_isr_handler_add(SW_WELDING, buttonISR, NULL);
}

int readHeatValue() {
  const adc_channel_t channel = POT_CHANNEL;  
  int potentiometer_value = adc1_get_raw(channel);
  return potentiometer_value;
}

int obtainHeatLevel() {
  int potentiometer_value = readHeatValue();
  printf("Potentiometer value: %d\n", potentiometer_value);

  if (potentiometer_value == 0) {
    printf("UNKNOWN\n");
    return LEVEL_UNKNOWN;
  } else if (potentiometer_value < MEDIUM) {
    printf("LOW\n");
    return LEVEL_LOW;
  } else if (potentiometer_value >= MEDIUM && potentiometer_value < HIGH) {
    printf("MEDIUM\n");
    return LEVEL_MEDIUM;
  } else {
    printf("HIGH\n");
    return LEVEL_HIGH;
  }

  // Returns LEVEL_UNKNOWN if no potentiometer_value
  return LEVEL_UNKNOWN;
}

void displayHeatIntensity(HEAT_LEVEL heat_level) {

  switch (heat_level) {
    case LEVEL_LOW:
      gpio_set_level(LED_PIN_1, 1);
      gpio_set_level(LED_PIN_2, 0);
      gpio_set_level(LED_PIN_3, 0);
      break;
    case LEVEL_MEDIUM:
      gpio_set_level(LED_PIN_1, 1);
      gpio_set_level(LED_PIN_2, 1);
      gpio_set_level(LED_PIN_3, 0);
      break;
    case LEVEL_HIGH:
      gpio_set_level(LED_PIN_1, 1);
      gpio_set_level(LED_PIN_2, 1);
      gpio_set_level(LED_PIN_3, 1);
      break;
    default:
      gpio_set_level(LED_PIN_1, 0);
      gpio_set_level(LED_PIN_2, 0);
      gpio_set_level(LED_PIN_3, 0);
  }
}

/* [] END OF FILE */