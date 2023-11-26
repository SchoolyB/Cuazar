/****************************************************************
 * Author: Marshall Burns
 * Date: 11/24/2023
 * Description: The CUAZAR test library is a simple library that allows you
 * to test your C code.
 *
 * Currently, the library supports the following:
 * - Basic Logic & Arithmetic
 * - Strings
 * - Return Values
 *
 *
 ***************************************************************/
#ifndef CUAZAR_H
#define CUAZAR_H

#include <stdio.h>
#include <string.h>
#include <stdio.h>

#define RED "\x1b[31m"
#define GREEN "\x1b[32m"
#define YELLOW "\x1b[33m"
#define BLUE "\x1b[34m"
#define RESET "\x1b[0m"

// Font macros
#define BOLD "\x1b[1m"
#define UNDERLINE "\x1b[4m"
#define RESET "\x1b[0m"

#define TRUE 1
#define FALSE 0

extern int testModeIsOn;

int Init_Cuazar(void);
int Kill_Cuazar(void);

/************************************************************************************
 * Module(s): Basic Logic & Arithmetic
 * Macro: __CUAZAR_EQUALS__
 * Description: Used to compare the expected result with the actual
 * Example:
 * int a = 1;
 * int b = 2;
 * __CUAZAR_EQUALS__(1, 4, a + b, return 1); //This would fail
 *
 * Author: Marshall Burns
 * Date: 11/24/2023
 ************************************************************************************/
#define __CUAZAR_EQUALS__(testNum, expected, result)                                                                                                                              \
  do                                                                                                                                                                              \
  {                                                                                                                                                                               \
    if ((testModeIsOn == TRUE))                                                                                                                                                   \
    {                                                                                                                                                                             \
      do                                                                                                                                                                          \
      {                                                                                                                                                                           \
        if ((expected) != (result))                                                                                                                                               \
        {                                                                                                                                                                         \
          printf(RED "TEST " BOLD "#%d " RESET RED "FAILED. Expected " BOLD "%d" RESET RED " but got " BOLD "%d" RESET RED " as the result.\n" RESET, testNum, expected, result); \
        }                                                                                                                                                                         \
        else                                                                                                                                                                      \
        {                                                                                                                                                                         \
          printf(GREEN "TEST " BOLD "#%d " RESET GREEN "PASSED.\n" RESET, testNum);                                                                                               \
        }                                                                                                                                                                         \
      } while (0);                                                                                                                                                                \
    }                                                                                                                                                                             \
  } while (0)

/************************************************************************************
 * Module(s): Basic Logic & Arithmetic / Strings
 * Macro: __CUAZAR_EQUALS_STR__
 * Description: Used to compare the expected string result with the actual string result
 * Example:
 * __CUAZAR_EQUALS_STR__(TRUE, 1, "Hello", "HELLO"); //This would fail
 *
 * Author: Marshall Burns
 * Date: 11/24/2023
 ************************************************************************************/
#define __CUAZAR_EQUALS_STR__(testNum, expectedStr, resultStr)                                                                                                                          \
  do                                                                                                                                                                                    \
  {                                                                                                                                                                                     \
    if ((testModeIsOn == TRUE))                                                                                                                                                         \
    {                                                                                                                                                                                   \
      do                                                                                                                                                                                \
      {                                                                                                                                                                                 \
        if (strcmp((expectedStr), (resultStr)) != 0)                                                                                                                                    \
        {                                                                                                                                                                               \
          printf(RED "TEST " BOLD "#%d " RESET RED "FAILED. Expected " BOLD "%s" RESET RED " but got " BOLD "%s" RESET RED " as the result.\n" RESET, testNum, expectedStr, resultStr); \
        }                                                                                                                                                                               \
        else                                                                                                                                                                            \
        {                                                                                                                                                                               \
          printf(GREEN "TEST " BOLD "#%d " RESET GREEN "PASSED.\n" RESET, testNum);                                                                                                     \
        }                                                                                                                                                                               \
      } while (0);                                                                                                                                                                      \
    }                                                                                                                                                                                   \
  } while (0)

/************************************************************************************
 * Module(s): Return Values
 * Macro: __CUAZAR_RETURN__
 * Description: Used to compare the expected return value with the actual return value
 * !NOTE:  Before using this macro there  are a few things to know:
 * ! 1.The macro CAN NOT be used inside the function that is being tested.
 * ! 2.The function that is being tested MUST be called inside the macro.
 * ! 3.The function that is being tested MUST return a value.
 * Example:
 * __CUAZAR_RETURN__(TRUE, 1, 0, new_func()); //This would fail
 *
 * Author: Marshall Burns
 * Date: 11/24/2023
 * **********************************************************************************/
#define __CUAZAR_RETURN__(testNum, expected, func)                                                                                                                                                         \
  do                                                                                                                                                                                                       \
  {                                                                                                                                                                                                        \
    if ((testModeIsOn == TRUE))                                                                                                                                                                            \
    {                                                                                                                                                                                                      \
      do                                                                                                                                                                                                   \
      {                                                                                                                                                                                                    \
        if ((expected) != (func))                                                                                                                                                                          \
        {                                                                                                                                                                                                  \
          printf(RED "TEST " BOLD "#%d " RESET RED "FAILED. Expected a return value of " BOLD "%d" RESET RED " but received a return value of " BOLD "%d" RESET RED ".\n" RESET, testNum, expected, func); \
        }                                                                                                                                                                                                  \
        else                                                                                                                                                                                               \
        {                                                                                                                                                                                                  \
          printf(GREEN "TEST " BOLD "#%d " RESET GREEN "PASSED.\n" RESET, testNum);                                                                                                                        \
        }                                                                                                                                                                                                  \
      } while (0);                                                                                                                                                                                         \
    }                                                                                                                                                                                                      \
  } while (0)

/************************************************************************************
 * Module: Basic Logic & Arithmetic
 * Macro: __CUAZAR_BOOL__
 * Description: Used to compare the expected boolean result with the actual boolean result
 * Example:
 * __CUAZAR_BOOL__(TRUE, 1, 1, 1); //This would pass
 * Author: Marshall Burns
 * Date: 11/24/2023
 ************************************************************************************/
#define __CUAZAR_BOOL__(testNum, expectedBool, resultBool)                                                                                                     \
  do                                                                                                                                                           \
  {                                                                                                                                                            \
    if ((testModeIsOn == TRUE))                                                                                                                                \
    {                                                                                                                                                          \
      do                                                                                                                                                       \
      {                                                                                                                                                        \
        if ((expectedBool) != (resultBool))                                                                                                                    \
        {                                                                                                                                                      \
          printf(RED "TEST " BOLD "#%d " RESET RED "FAILED. Expected " BOLD "%s" RESET RED " but got " BOLD "%s" RESET RED " as the result.\n" RESET, testNum, \
                 (expectedBool == TRUE) ? "TRUE" : "FALSE",                                                                                                    \
                 (resultBool == TRUE) ? "TRUE" : "FALSE");                                                                                                     \
        }                                                                                                                                                      \
        else                                                                                                                                                   \
        {                                                                                                                                                      \
          printf(GREEN "TEST " BOLD "#%d " RESET GREEN "PASSED.\n" RESET, testNum);                                                                            \
        }                                                                                                                                                      \
      } while (0);                                                                                                                                             \
    }                                                                                                                                                          \
  } while (0)
#endif
