# Cuazar
## Description
Cuazar is a basic testing library for C code. It is designed to be simple and easy to use and integrate into existing projects.
## Including Cuazar
To include Cuazar in your project simply clone the repository into your project directory.
Ideally youd want to clone it into a subdirectory of your project, but you can clone it anywhere you want.

# Step 1:
Navigate to your project directory
```bash
cd my/project/root/subdir
```

# Step 2:
Clone the repository
```bash
git clone https://github.com/SchoolyB/Cuazar.git
```

# Step 3:
Include the Cuazar source and header files in your main file
Be sure to use the correct file path.
```c
#include "Other/files.h"
#include "Cuazar/lib/Cuazar.c"
#include "Cuazar/lib/Cuazar.h"
```

# Step 4:
To enable the library
Call `Init_Cuazar()` function;
```c
#include "Other/files.h"
#include "Cuazar/lib/Cuazar.c"
#include "Cuazar/lib/Cuazar.h"

int main(int argc, char** argv) {
    Init_Cuazar();
    // Your code here
    return 0;
}
```

# Step 5:
Call the Cuazar functions where needed
```C

#include <stdio.h>
#include "Other/files.h"
#include "Cuazar/lib/Cuazar.c"
#include "Cuazar/lib/Cuazar.h"



int main(int argc, char **argv)
{
    Init_Cuazar();
  /*
  __CUAZAR_RETURN__ tests the return value of a function
  Params:
  1 = The test number. This could be 2,3,47,50,150,etc...
  3 = The Expected return value from the function
  myCoolFunc() = The function whose return value we are testing
  */
  __CUAZAR_RETURN__(1, 3, myCoolFunc());
  return 0;
}

int myCoolFunc(void)
{
  int schoolIsCool = FALSE; // or 0

  if (schoolIsCool == TRUE)
  {
    puts("You think school is cool?");
    return 1;
  }
  else
  {
    puts("School is not cool.");
    return 3;
  }
}
```
# Output:
`TEST #1 PASSED`


