#pragma once
#include <iostream>
#include <string>

// Helper function to validate binary input
bool isValidBinary(const std::string& binary);

// Helper function to convert a decimal number to a string in a given base
std::string decimalToBase(int decimal, int base);

// Displays menu and validates and returns user option
char menuOption();

// Takes binary input and returns a decimal value
int binaryToDecimal();

// Function to convert binary to another base (2 to 16)
int binaryToOtherBase();

// Takes a decimal input and returns a binary value
void decimalToBinary();

// Takes a number in user-given base (2-16) and converts it to binary
void otherBaseToBinary();
