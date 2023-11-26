#include <stdio.h>
#include "Cuazar.h"

int Init_Cuazar(void)
{
  int testModeIsOn = TRUE;
  printf(GREEN "Cuazar initialized...\n" RESET);
  return 0;
}

int Kill_Cuazar(void)
{
  int testModeIsOn = FALSE;
  printf(YELLOW "Killing Cuazar..." RESET);
  return 0;
}
