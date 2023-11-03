#ifndef T_UTILS
#define T_UTILS

#include <string>

void clearScreen();
void waitForEnter();
std::string truncateString(const std::string &input, size_t maxLength);
std::string padString(const std::string &input, size_t desiredLength);

#endif