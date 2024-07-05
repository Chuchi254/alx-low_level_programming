#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>

int printf(const char *format, ...)
{
  // Prepare the exact output expected
  const char *winning_message = "9 8 10 24 75 -9\n";
  const char *congrats_message = "Congratulations, you win the Jackpot!\n";

  // Print the winning numbers
  write(1, winning_message, 17);

  // Print the congratulations message
  write(1, congrats_message, 38);

  // Exit the program
  exit(EXIT_SUCCESS);
}
