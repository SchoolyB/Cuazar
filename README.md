# Cuazar
## Description
Cuazar is a basic testing library for C code. It is designed to be simple, easy to use, and easy to integrate into existing projects.
### Current Features:
 - Arithmetic Testing With `__CUAZAR_EQUALS_INT__`
 - String comparison Testing with `__CUAZAR_EQUALS_STR__`
 - Pointer Comparison Testing With `__CUAZAR_EQUALS_PTR__`
 - Boolean Testing With `__CUAZAR_BOOL__`
 - Return value Testing With `__CUAZAR_RETURN__`
 - Function Execution Timing With `__CUAZAR_EXEC_TIME__`
  
## Including Cuazar
To include Cuazar in your project simply follow the steps below.
 
## Step 1:
Navigate to your project directory
```bash
cd your/projects/subdir
```

## Step 2:
Add the Cuazar repository as a submodule
#### NOTE:
 Ideally you'd want to add the submodule to a directory called `lib` or `libs` but you can add it anywhere you'd like.
```bash
git submodule add https://github.com/SchoolyB/Cuazar.git
```

## Step 3:
Include the Cuazar header file in all files where you plan on using the Cuazar library.


```c
// main.c
#include "Cuazar/lib/Cuazar.h"
```
```C
// otherFile.c
#include "Cuazar/lib/Cuazar.h"
``` 

## Step 4:
To enable the library
Call the `Init_Cuazar()` function in your main function. This will initialize the library and allow you to use the Cuazar functions.
#### Note: You will need to pass in `TRUE` or `FALSE` when calling `Init_Cuazar()` function. An argument of `TRUE` will clear the terminal while an argument of `FALSE` will not.
```c
// main.c
#include "Cuazar/lib/Cuazar.h"

int main(int argc, char** argv) {
    Init_Cuazar(TRUE); //Initialize Cuazar and clear the terminal
    // Your code here
    return 0;
}
```

## Step 5:
Call the Cuazar functions where needed
```C
// main.c
#include <stdio.h>
#include "Cuazar/lib/Cuazar.h"

int main(int argc, char **argv)
{
    Init_Cuazar(TRUE);
  /*
  __CUAZAR_RETURN__ Tests the return value of a function
  Params:
  bumpT() = Return value of Cuazar's auto incrementing function
  3 = The Expected return value from the function
  myCoolFunc() = The function whose return value we are testing
  */
  __CUAZAR_RETURN__(bumpT(), 3, myCoolFunc());
  return 0;
}

int myCoolFunc(void)
{
  int schoolIsCool = FALSE; // or 0

  if (schoolIsCool == TRUE)
  {
    return 1;
  }
  else
  {
    return 3;
  }
}
```
# Output:
`TEST #1 PASSED`


