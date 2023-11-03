#include <iostream>
#include <limits>

void clearScreen()
{
  std::cout << "\033[2J\033[1;1H";
}

void waitForEnter()
{
  std::cin.clear();
  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
  std::cin.get();
}

std::string padString(const std::string &input, size_t desiredLength)
{
  if (input.length() >= desiredLength)
  {
    // No padding needed, return the original string
    return input;
  }
  else
  {
    // Calculate the number of spaces needed for padding
    size_t spacesToAdd = desiredLength - input.length();

    // Create a string of spaces and append it to the original string
    return input + std::string(spacesToAdd, ' ');
  }
}

std::string truncateString(const std::string &input, size_t maxLength)
{
  if (input.length() <= maxLength)
  {
    // No truncation needed, return the original string with padding
    return padString(input, maxLength);
  }
  else
  {
    // Truncate the string and add "..."
    return input.substr(0, maxLength - 3) + "...";
  }
}