# Cuazar
## Description
Cuazar is a basic testing library for C code. It is designed to be simple, easy to use, and easy to integrate into existing projects.

## Table of Contents
- [Cuazar](#cuazar)
- [Description](#description)
- [Table of Contents](#table-of-contents)
- [Current Features:](#current-features)
- [Including Cuazar](#including-cuazar)
- [CMake & Cuazar](#cmake-&-cuazar)
  

### Current Features:
 - Arithmetic Testing With `__CUAZAR_EQUALS_INT__`
 - String comparison Testing with `__CUAZAR_EQUALS_STR__`
 - Pointer Comparison Testing With `__CUAZAR_EQUALS_PTR__`
 - Boolean Testing With `__CUAZAR_BOOL__`
 - Return value Testing With `__CUAZAR_RETURN__`
 - Function Execution Timing With `__CUAZAR_EXEC_TIME__`
  
## Including Cuazar
To include Cuazar in your project simply follow the steps below.
#### NOTE: If using CMake, see [CMake & Cuazar](#cmake-&-cuazar) for extra instructions on how to include Cuazar in your project.
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
#### Note: You will need to pass in `NULL` or call the `clear()` function when calling `Init_Cuazar()`. Calling `clear()` will clear the terminal before running your code, while passing in `NULL` will not clear the terminal.
```c
// main.c
#include "Cuazar/lib/Cuazar.h"

int main(int argc, char** argv) {
    Init_Cuazar(clear()); //Initialize Cuazar and clear the terminal
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
    Init_Cuazar(clear());
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

#### Note
Be sure to link the Cuazar.c file when compiling
```bash
# Using GCC

  gcc main.c  path/to/the/lib/Cuazar.c 
``` 

# Output:
`TEST #1 PASSED`
<hr>

## CMake & Cuazar
To include Cuazar in your CMake project all the steps are the same except but there are just one extra step.

## Step 6: (If using CMake)
Simply add the Cuazar directory in your CMakeLists.txt file
```cmake
# CMakeLists.txt
set(SOURCES_C
    main.c
    otherFile.c
    path/to/the/lib/Cuazar.c
)
```




