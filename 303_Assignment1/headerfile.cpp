#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <stdexcept>

const int MAX_SIZE = 1000; // Maximum size of the array

// Function that finds the index of the integer the user asks
int findIndex(const int array[], int size, int target);

// Function to modify the value in the array
void modifyvalue(int array[], int index, int newvalue, int& oldvalue, int& returnednewvalue);

// Function to add an integer to the end of the array
void addIntToArray(int array[], int& size, int newnumber, int index);

// Function to replace or remove an integer at a specified index
void replaceint(int array[], int& size, int indextomodify, bool remove);

#endif // FUNCTIONS_H
