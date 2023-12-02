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

// Declarations
int Init_Cuazar(int clear);
int bumpT(void);
int clear(void);
void __CUAZAR_EQUALS_INT__(int testNum, int expectedInt, int resultInt);
void __CUAZAR_EQUALS_STR__(int testNum, char *expectedStr, char *resultStr);
int __CUAZAR_EQUALS_PTR__(int testNum, int *expectedPtr, int *resultPtr);
void __CUAZAR_RETURN__(int testNum, int expectedRet, int func);
void __CUAZAR_BOOL__(int testNum, int expectedBool, int resultBool);
int __CUAZAR_EXEC_TIME__(int testNum, int func);

#endif
