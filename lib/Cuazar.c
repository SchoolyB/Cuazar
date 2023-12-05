#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include "Cuazar.h"

/************************************************************************************
 * Module(s): Core
 * Function: Init_Cuazar
 * Description: Sets test mode to on and logs messgaes to terminal and log file.
 * !NOTE: Before using this core function there are a few things to know:
 * !Note: The function must be called BEFORE using any Cuazar tests.
 * !Note: The optional parameter is used to clear the terminal.
 * !Note: Pass in TRUE to clear the terminal or FALSE leave it as is.
 * -----------------------------------------------------------------------------------
 * Example Usage:
 * int main()
 * {
 *  Init_Cuazar(clear()); // initialize Cuazar and clear the terminal
 *  Your code and test here
 * }
 ************************************************************************************/
int testModeIsOn = FALSE;

int Init_Cuazar(int func)
{
  testModeIsOn = TRUE;
  printf(GREEN "Cuazar testing initialized...\n" RESET);
  openLogFile();
  FILE *testLogFile = fopen("cuazar-test-history.log", "a");
  time_t currentTime;
  time(&currentTime);
  fprintf(testLogFile, "\nNEW TEST SESSION INITIALIZED @ %s", ctime(&currentTime));
  fprintf(testLogFile, "======================================================================");
  fclose(testLogFile);
  return 0;
}

/************************************************************************************
 * Module(s): Core
 * Function: Kill_Cuazar
 * Description: Sets test mode to off and logs messgaes to terminal and log file.
 * !Note: Technically this use of this function is OPTIONAL.
 * -----------------------------------------------------------------------------------
 * Example Usage:
 * int main()
 * {
 *  Init_Cuazar(clear());;
 *  Your code and test here
 *  Kill_Cuazar();
 * }
* -----------------------------------------------------------------------------------
 * Author: Marshall Burns
 * Date: 12/5/2023
 ************************************************************************************/
int Kill_Cuazar(void)
{
  testModeIsOn = FALSE;
  printf(GREEN "Cuazar testing complete!\n" RESET);
  openLogFile();
  FILE *testLogFile = fopen("cuazar-test-history.log", "a");
  time_t currentTime;
  time(&currentTime);
  fprintf(testLogFile, "======================================================================");
  fprintf(testLogFile, "\nALL TESTS COMPLETED @ %s\n\n\n", ctime(&currentTime));
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
int testNum = 1;
int bumpT(void)
{
  return testNum++;
}

/************************************************************************************
* Module(s): Core
* Function: passedT // short for 'passed test'
* Description: Called inside Cuazar functions to print a message when a test passes
* -----------------------------------------------------------------------------------
* Author: Marshall Burns
* Date: 12/5/2023
***********************************************************************************/
void passedT(int testNum)
{
  printf(GREEN "TEST " BOLD "#%d" RESET GREEN " PASSED!\n" RESET, testNum);
}

/************************************************************************************
 * Module(s): Core
 * Function: failedT // short for 'failed test'
 * Description: Called inside Cuazar functions to print a message when a test fails
 *------------------------------------------------------------------------------------
 * Author: Marshall Burns
 * Date: 12/5/2023
 ************************************************************************************/
void failedT(int testNum)
{
  printf(RED "TEST " BOLD "#%d" RESET RED " FAILED.\n" RESET, testNum);
}

/************************************************************************************
 * Module(s): Core
 * Function: openLogFile
 * Description: Called inside Cuazar functions to open the log file
 * -----------------------------------------------------------------------------------
 *  Author: Marshall Burns
 *  Date: 12/5/2023
 ************************************************************************************/
int openLogFile(void)
{
  FILE *testLogFile = fopen("cuazar-test-history.log", "a");
  if (testLogFile == NULL)
  {
    perror("Error opening test log file");
    return 1;
  }
  fclose(testLogFile);
}

/************************************************************************************
 * Module(s): Core
 * Function: logT // short for 'log test'
 * Description: Called inside Cuazar functions to log test status' to a file
 * !Note: Takes in an unlimited amount of arguments
 * -----------------------------------------------------------------------------------
 *  Author: Marshall Burns
 *  Date: 12/5/2023
 ************************************************************************************/
int logT(int testNum, ...)
{
  openLogFile();
  FILE *testLogFile = fopen("cuazar-test-history.log", "a");
  time_t currentTime;
  time(&currentTime);
  fprintf(testLogFile, "\n");
  fprintf(testLogFile, "\nLogged @ %s", ctime(&currentTime));

  va_list args;            // initialize variable argument list
  va_start(args, testNum); // start variable argument list from testNum

 
  int expectedInt = va_arg(args, int);
  int resultInt = va_arg(args, int);

  /*For __CUAZAR_EQUALS_STR__*/
  char *expectedStr = va_arg(args, char *);
  char *resultStr = va_arg(args, char *);

  /*For __CUAZAR_EQUALS_PTR__*/
  int *expectedPtr = va_arg(args, int *);
  int *resultPtr = va_arg(args, int *);

  /*For __CUAZAR_RETURN__*/
  int expectedRet = va_arg(args, int);
  int func = va_arg(args, int);

  /*For __CUAZAR_BOOL__*/
  int expectedBool = va_arg(args, int);
  int resultBool = va_arg(args, int);

  va_end(args); // end variable argument list after args

  if (expectedInt != resultInt)
  {

    fprintf(testLogFile, "TEST #%d FAILED. Expected %d but instead received %d.\n", testNum, expectedInt, resultInt);
    fclose(testLogFile);
  }
  else if (expectedInt == resultInt)
  {
    fprintf(testLogFile, "TEST #%d PASSED! Expected %d and got %d as the result.\n", testNum, expectedInt, resultInt);
    fclose(testLogFile);
  }

  else if (expectedStr != resultStr)
  {
    fprintf(testLogFile, "TEST #%d FAILED. Expected a string of %s but instead received %s.\n", testNum, expectedStr, resultStr);
    fclose(testLogFile);
  }
  else if (expectedStr == resultStr)
  {
    fprintf(testLogFile, "TEST #%d PASSED! Expected a string of %s and got %s as the result.\n", testNum, expectedStr, resultStr);
    fclose(testLogFile);
  }

  else if (expectedPtr != resultPtr)
  {
    fprintf(testLogFile, "TEST #%d FAILED. Expected to point to %p but instead is pointing to %p.\n", testNum, expectedPtr, resultPtr);
    fclose(testLogFile);
  }
  else if (expectedPtr == resultPtr)
  {
    fprintf(testLogFile, "TEST #%d PASSED! Expected to point to %p and got %p.\n", testNum, expectedPtr, resultPtr);
    fclose(testLogFile);
  }
  else if (expectedRet != func)
  {
    fprintf(testLogFile, "TEST #%d FAILED. Expected a return value of %d but received a return value of %d.\n", testNum, expectedRet, func);
    fclose(testLogFile);
  }
  else if (expectedRet == func)
  {
    fprintf(testLogFile, "TEST #%d PASSED! Expected a return value of %d and got %d.\n", testNum, expectedRet, func);
    fclose(testLogFile);
  }
  else if (expectedBool != resultBool)
  {
    fprintf(testLogFile, "TEST #%d FAILED. Expected %d and got %d as the result.\n", testNum, expectedBool, resultBool);
    fclose(testLogFile);
  }
  else if (expectedBool == resultBool)
  {
    fprintf(testLogFile, "TEST #%d PASSED! Expected %d and got %d as the result.\n", testNum, expectedBool, resultBool);
    fclose(testLogFile);
  }
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
void __CUAZAR_EQUALS_INT__(int testNum, int expectedInt, int resultInt)
{
  if (testModeIsOn == TRUE)
  {
    do
    {
      if (expectedInt != resultInt)
      {
        failedT(testNum);
        logT(testNum, expectedInt, resultInt);
      }
      else
      {
        passedT(testNum);
        logT(testNum, expectedInt, resultInt);
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
void __CUAZAR_EQUALS_STR__(int testNum, char *expectedStr, char *resultStr)
{
  if (testModeIsOn == TRUE)
  {
    do
    {
      if (strcmp(expectedStr, resultStr) != 0)
      {
        failedT(testNum);
        logT(testNum, expectedStr, resultStr);
      }
      else
      {
        passedT(testNum);
        logT(testNum, expectedStr, resultStr);
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

int __CUAZAR_EQUALS_PTR__(int testNum, int *expectedPtr, int *resultPtr)
{
  if (testModeIsOn == TRUE)
  {
    do
    {
      if (expectedPtr != resultPtr)
      {
        logT(testNum, expectedPtr, resultPtr);
        failedT(testNum);
      }
      else
      {
        logT(testNum, expectedPtr, resultPtr);
        passedT(testNum);
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
int __CUAZAR_RETURN__(int testNum, int expectedRet, int func)
{
  if (testModeIsOn == TRUE)
  {
    do
    {
      if (expectedRet != func)
      {
        logT(testNum, expectedRet, func);
        failedT(testNum);
      }
      else
      {
        logT(testNum, expectedRet, func);
        passedT(testNum);
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
        failedT(testNum);
        logT(testNum, expectedBool, resultBool);
      }
      else
      {
        passedT(testNum);
        logT(testNum, expectedBool, resultBool);
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
      printf(GREEN "TEST " BOLD "#%d " RESET GREEN "FINISHED! Execution time: " BOLD "%f" RESET GREEN " seconds.\n" RESET, testNum, time_spent);
      openLogFile();
      FILE *testLogFile = fopen("cuazar-test-history.log", "a");
      time_t currentTime;
      time(&currentTime);
      fprintf(testLogFile, "\nLogged @ %s", ctime(&currentTime));
      fprintf(testLogFile, "TEST #%d FINISHED! Executed in: %f seconds.", testNum, time_spent);
      fclose(testLogFile);
    } while (0);
  }
  return 0;
}
