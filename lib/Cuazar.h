/****************************************************************
 * Author: Marshall Burns
 * Date: 11/24/2023
 * Description: The CUAZAR test library is a simple library that allows you
 * to test your C code.
 *
 * Currently, the library supports the following:
 * - Auto incrementing test numbers
 * - Basic Logic & Arithmetic tests
 * - String Comparisons tests
 * - Functions return values tests
 * - Function Execution Time tests
 *
 *
 ***************************************************************/
#ifndef CUAZAR_H
#define CUAZAR_H

#include <stdio.h>
#include <string.h>
#include <stdio.h>
#include <time.h>

#ifdef RED
#undef RED
#endif
#define RED "\x1b[31m"

#ifdef GREEN
#undef GREEN
#endif
#define GREEN "\x1b[32m"

#ifdef YELLOW
#undef YELLOW
#endif
#define YELLOW "\x1b[33m"

#ifdef BLUE
#undef BLUE
#endif
#define BLUE "\x1b[34m"

#ifdef RESET
#undef RESET
#endif
#define RESET "\x1b[0m"

#ifdef BOLD
#undef BOLD
#endif
#define BOLD "\x1b[1m"

#ifdef UNDERLINE
#undef UNDERLINE
#endif
#define UNDERLINE "\x1b[4m"

#ifdef RESET
#undef RESET
#endif
#define RESET "\x1b[0m"

#ifdef TRUE
#undef TRUE
#endif
#define TRUE 1

#ifdef FALSE
#undef FALSE
#endif
#define FALSE 0

static int testModeIsOn = FALSE;
static int testNum = 1;

// Declarations
static int Init_Cuazar(int clear);
static int bumpT(void);
static int clear(void);

/************************************************************************************
 * Module(s): Core
 * Function: Init_Cuazar
 * Description: Sets test mode to on.
 * !NOTE: Before using this core function there are a few things to know:
 * !Note: The function must be called BEFORE using any Cuazar tests.
 * !Note: The optional parameter is used to clear the terminal.
 * !Note: Pass in TRUE to clear the terminal or FALSE leave it as is.
 * -----------------------------------------------------------------------------------
 * Example Usage:
 * int main()
 * {
 *  Init_Cuazar(TRUE); // initialize Cuazar and clear the terminal
 *  Your code and test here
 * }
 ************************************************************************************/
int Init_Cuazar(int func) // definition
{
  testModeIsOn = TRUE;
  printf(GREEN "Cuazar initialized...\n" RESET);
  return 0;
}

/************************************************************************************
 * Module(s): Core
 * Function: clear
 * Description: Clears the terminal
 * !Note: This function is called inside Init_Cuazar()
 * -----------------------------------------------------------------------------------
 * Example Usage:
 * Init_Cuazar(clear()); // initialize Cuazar and clear the terminal
 * -----------------------------------------------------------------------------------
 * Author: Marshall Burns
 * Date: 11/24/2023
 * **********************************************************************************/
int clear(void)
{
  system("clear");
}

/************************************************************************************
 * Module(s): Helper
 * Function: bumpT // short for 'bump test'
 * Description: Called inside Cuazar functions to increment the test number automatically
 * !Note: Using bumpT() is OPTIONAL. See example usage below
 * Note: Big thanks to @CobbCoding for this idea
 * -----------------------------------------------------------------------------------
 * Example Usage(Using bumpT() -OR- int values):
 * __CUAZAR_EQUALS__(bumpT(), 1, 1); -OR- __CUAZAR_EQUALS__(1, 1, 1); = Test #1
 * __CUAZAR_EQUALS__(bumpT(), 2, 2); -OR- __CUAZAR_EQUALS__(2, 2, 2); = Test #2
 * __CUAZAR_RETURN__(bumpT(), 3, 3); -OR- __CUAZAR_RETURN__(3, 3, 3); = Test #3
 ************************************************************************************/
int bumpT(void)
{
  return testNum++;
}

/************************************************************************************
 * Module(s): Basic Logic & Arithmetic / Integers
 * Function: __CUAZAR_EQUALS__
 * Description: Used to compare the expected result with the actual result
 * -----------------------------------------------------------------------------------
 * Example Usage:
 * int a = 1;
 * int b = 2;
 * __CUAZAR_EQUALS__(bumpT(), 4, a + b);
 *
 * Example Output: "TEST #1 FAILED. Expected 4 but received 3 as the result."
 * -----------------------------------------------------------------------------------
 * Author: Marshall Burns
 * Date: 11/24/2023
 ************************************************************************************/
void __CUAZAR_EQUALS_INT__(int testNum, int expected, int result)
{
  if (testModeIsOn == TRUE)
  {
    do
    {
      if (expected != result)
      {
        printf(RED "TEST " BOLD "#%d " RESET RED "FAILED. Expected " BOLD "%d" RESET RED " but received " BOLD "%d" RESET RED " as the result.\n" RESET, testNum, expected, result);
      }
      else
      {
        printf(GREEN "TEST " BOLD "#%d " RESET GREEN "PASSED! Expected " BOLD "%d" RESET GREEN " and got " BOLD "%d" RESET GREEN " as the result.\n" RESET, testNum, expected, result);
      }
    } while (0);
  }
}

/************************************************************************************
 * Module(s): Basic Logic & Arithmetic / Strings
 * Function: __CUAZAR_EQUALS_STR__
 * Description: Used to compare the expected string result with the actual string result
 * -----------------------------------------------------------------------------------
 * Example Usage:
 * char input[10] = "Jello";
 * __CUAZAR_EQUALS_STR__(bumpT(), 1, "Hello", input);
 *
 * Example Output: "TEST #2 FAILED. Expected "Hello" but received "Jello" as the result."
 * -----------------------------------------------------------------------------------
 * Author: Marshall Burns
 * Date: 11/24/2023
 ************************************************************************************/
void __CUAZAR_EQUALS_STR__(int testNum, char *expected, char *result)
{
  if (testModeIsOn == TRUE)
  {
    do
    {
      if (strcmp(expected, result) != 0)
      {
        printf(RED "TEST " BOLD "#%d " RESET RED "FAILED. Expected " BOLD "%s" RESET RED " but received " BOLD "%s" RESET RED " as the result.\n" RESET, testNum, expected, result);
      }
      else
      {
        printf(GREEN "TEST " BOLD "#%d " RESET GREEN "PASSED! Expected " BOLD "%s" RESET GREEN " and got " BOLD "%s" RESET GREEN " as the result.\n" RESET, testNum, expected, result);
      }
    } while (0);
  }
}
/************************************************************************************
 * Module(s): Basic Logic & Arithmetic / Pointers
 * Function: __CUAZAR_EQUALS_PTR__
 * Description: Used to compare the expected pointer result with the actual pointer result
 * Note: Big thanks to @CobbCoding for the feedback on this one
 * -----------------------------------------------------------------------------------
 * Example Usage:
 * int age = 21;
 * int *ptr = &age;
 * __CUAZAR_EQUALS_PTR__(bumpT(), &age, ptr);
 *
 * Example Output: "TEST #3 FAILED. Expected to point to 0x7ffeeb but instead is pointing to 0x3faabb."
 * -----------------------------------------------------------------------------------
 * Author: Marshall Burns
 * Date: 11/28/2023
 ************************************************************************************/

void __CUAZAR_EQUALS_PTR__(int testNum, int *expected, int *result)
{
  if (testModeIsOn == TRUE)
  {
    do
    {
      if (expected != result)
      {
        printf(RED "TEST " BOLD "#%d " RESET RED "FAILED. Expected to point to " BOLD "%p" RESET RED " but instead is pointing to " BOLD "%p" RESET RED ".\n" RESET, testNum, expected, result);
      }
      else
      {
        printf(GREEN "TEST " BOLD "#%d " RESET GREEN "PASSED! Expected to point to " BOLD "%p" RESET GREEN " and got " BOLD "%p" RESET GREEN " as the result.\n" RESET, testNum, expected, result);
      }
    } while (0);
  }
}
/************************************************************************************
 * Module(s): Return Values
 * Function: __CUAZAR_RETURN__
 * Description: Used to compare the expected return value with the actual return value
 * !NOTE:  Before using this function there are a few things to know:
 * ! 1.The function CAN NOT be used inside the function that is being tested.
 * ! 2.The function that is being tested MUST be called inside the function.
 * ! 3.The function that is being tested MUST return a value.
 * -----------------------------------------------------------------------------------
 * Example Usage:
 * __CUAZAR_RETURN__(BumpT(), 0, new_func());
 *
 * Example Output: "TEST #4 FAILED. Expected a return value of 1 but received a return value of 0."
 * -----------------------------------------------------------------------------------
 * Author: Marshall Burns
 * Date: 11/24/2023
 * **********************************************************************************/
void __CUAZAR_RETURN__(int testNum, int expected, int func)
{
  if (testModeIsOn == TRUE)
  {
    do
    {
      if (expected != func)
      {
        printf(RED "TEST " BOLD "#%d " RESET RED "FAILED. Expected a return value of " BOLD "%d" RESET RED " but received a return value of " BOLD "%d" RESET RED ".\n" RESET, testNum, expected, func);
      }
      else
      {
        printf(GREEN "TEST " BOLD "#%d " RESET GREEN "PASSED! Expected " BOLD "%d" RESET GREEN " and got a return value of " BOLD "%d" RESET GREEN ".\n" RESET, testNum, expected, func);
      }
    } while (0);
  }
}

/************************************************************************************
 * Module: Basic Logic & Arithmetic / Booleans / Integers
 * Function: __CUAZAR_BOOL__
 * Description: Used to compare the expected boolean result with the actual boolean result
 * -----------------------------------------------------------------------------------
 * Example Usage:
 *
 * int isProgramRunning = TRUE;
 *  __CUAZAR_BOOL__(bumpT(), FALSE, isProgramRunning);
 *
 * Example Output: "TEST #5 FAILED. Expected FALSE and got TRUE as the result."
 * -----------------------------------------------------------------------------------
 * Author: Marshall Burns
 * Date: 11/24/2023
 ************************************************************************************/

void __CUAZAR_BOOL__(int testNum, int expectedBool, int resultBool)
{
  if (testModeIsOn == TRUE)
  {
    do
    {
      if (expectedBool != resultBool)
      {
        printf(RED "TEST " BOLD "#%d " RESET RED "FAILED. Expected " BOLD "%s" RESET RED " but received " BOLD "%s" RESET RED " as the result.\n" RESET, testNum,
               (expectedBool == TRUE) ? "TRUE" : "FALSE",
               (resultBool == TRUE) ? "TRUE" : "FALSE");
      }
      else
      {
        printf(GREEN "TEST " BOLD "#%d " RESET GREEN "PASSED! Expected " BOLD "%s" RESET GREEN " and got " BOLD "%s" RESET GREEN " as the result.\n" RESET, testNum,
               (expectedBool == TRUE) ? "TRUE" : "FALSE",
               (resultBool == TRUE) ? "TRUE" : "FALSE");
      }
    } while (0);
  }
}
/************************************************************************************
 * Module: Execution Time
 * Function: __CUAZAR_EXEC_TIME__
 * Description: Used to test how long it takes for a function to fully execute.
 * !NOTE:  Before using this function there are a couple things to note:
 * ! 1. The function CAN NOT be used inside the function that is being tested.
 * ! 2. This function only works on functions that do not take in any kind of user input
 * ! 3. The function that is being tested MUST be called inside the function
 * ! 4. Uses the C standard library <time.h>
 *------------------------------------------------------------------------------------
 * Example Usage:
 * __CUAZAR_EXEC_TIME__(bumpT(), myCoolFunc());
 *
 * Example Output: "TEST #6 PASSED! Execution time: 0.000020 seconds."
 *------------------------------------------------------------------------------------
 * Author: Marshall Burns
 * Date: 11/25/2023
 ************************************************************************************/

int __CUAZAR_EXEC_TIME__(int testNum, int func)
{
  if ((testModeIsOn == TRUE))
  {
    do
    {
      clock_t start = clock();
      func;
      clock_t end = clock();
      double time_spent = (double)(end - start) / CLOCKS_PER_SEC;
      printf(GREEN "TEST " BOLD "#%d " RESET GREEN "PASSED! Execution time: " BOLD "%f" RESET GREEN " seconds.\n" RESET, testNum, time_spent);
    } while (0);
  }
  return 0;
}

#endif
