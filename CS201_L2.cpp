#include "Header1.h"
#include <iostream>
#include <string>
#include <cmath>

using namespace std;

//Created using ChatGPT, prompted with lab instructions
// Helper function to validate binary input
bool isValidBinary(const std::string& binary) {
    for (char c : binary) {
        if (c != '0' && c != '1') {
            return false;
        }
    }
    return true;
}

//Created using ChatGPT, prompted with lab instructions
// Helper function to convert a decimal number to a string in a given base
std::string decimalToBase(int decimal, int base) {
    if (decimal == 0) return "0";

    std::string result = "";
    while (decimal > 0) {
        int remainder = decimal % base;
        if (remainder < 10) {
            result = char('0' + remainder) + result;
        }
        else {
            result = char('A' + remainder - 10) + result;
        }
        decimal /= base;
    }
    return result;
}

//Created using ChatGPT, prompted with lab instructions
// Convert binary to decimal
int binaryToDecimal() {
    string binary;
    cout << "Enter a binary number: ";
    cin >> binary;

    // Validate binary input
    if (!isValidBinary(binary)) {
        cout << "Invalid binary number. Only 0s and 1s are allowed." << endl;
        return -1;
    }

    // Calculate decimal value from binary
    int decimal = 0;
    int len = binary.length();
    for (int i = 0; i < len; i++) {
        if (binary[i] == '1') {
            decimal += pow(2, len - i - 1);
        }
    }

    // Display the results
    cout << "Binary value: " << binary << endl;
    cout << "Decimal value: " << decimal << endl;

    return 1;
}

//Created using ChatGPT, prompted with lab instructions
// Convert binary to another base (2 to 16)
int binaryToOtherBase() {
    string binary;
    int base;

    // Get and validate binary input
    cout << "Enter a binary number: ";
    cin >> binary;
    if (!isValidBinary(binary)) {
        cout << "Invalid binary number. Only 0s and 1s are allowed." << endl;
        return -1;
    }

    // Get and validate base input
    cout << "Enter a base (2 to 16): ";
    cin >> base;
    if (base < 2 || base > 16) {
        cout << "Invalid base. Please enter a base between 2 and 16." << endl;
        return -1;
    }

    // Convert binary to decimal
    int decimal = 0;
    int len = binary.length();
    for (int i = 0; i < len; i++) {
        if (binary[i] == '1') {
            decimal += 1 << (len - i - 1);
        }
    }

    // Convert decimal to the specified base
    string result = decimalToBase(decimal, base);

    // Display the results
    cout << "Binary value: " << binary << endl;
    cout << "Value in base " << base << ": " << result << endl;

    return 1;
}

//Created using ChatGPT, prompted with lab instructions
// Convert decimal number to binary
void decimalToBinary() {
    int decimal;
    cout << "Enter a decimal number: ";
    cin >> decimal;

    string binary = "";
    if (decimal == 0) {
        binary = "0";
    }
    else {
        while (decimal > 0) {
            binary = (decimal % 2 == 0 ? "0" : "1") + binary;
            decimal /= 2;
        }
    }

    // Display the results
    cout << "Decimal value: " << decimal << endl;
    cout << "Binary value: " << binary << endl;
}

//Created using ChatGPT, prompted with lab instructions
// Convert number in user-given base (2-16) to binary
void otherBaseToBinary() {
    string input;
    int base;

    cout << "Enter a number: ";
    cin >> input;

    cout << "Enter the base of the number (2 to 16): ";
    cin >> base;

    if (base < 2 || base > 16) {
        cout << "Invalid base. Please enter a base between 2 and 16." << endl;
        return;
    }

    int decimal = 0;

    // Convert input to decimal
    for (char c : input) {
        if (c >= '0' && c <= '9') {
            decimal = decimal * base + (c - '0');
        }
        else if (c >= 'A' && c <= 'F') {
            decimal = decimal * base + (c - 'A' + 10);
        }
        else if (c >= 'a' && c <= 'f') {
            decimal = decimal * base + (c - 'a' + 10);
        }
        else {
            cout << "Invalid character in input for the given base." << endl;
            return;
        }
    }

    // Convert decimal to binary
    string binary = "";
    if (decimal == 0) {
        binary = "0";
    }
    else {
        while (decimal > 0) {
            binary = (decimal % 2 == 0 ? "0" : "1") + binary;
            decimal /= 2;
        }
    }

    // Display the results
    cout << "Number in base " << base << ": " << input << endl;
    cout << "Binary value: " << binary << endl;
}

// Display menu and validate user option
char menuOption() {
    char choice;
    cout << "MENU" << endl;
    cout << "a. Convert from binary to decimal" << endl;
    cout << "b. Convert from binary to another base" << endl;
    cout << "c. Convert a decimal number into binary" << endl;
    cout << "d. Convert another base value into binary" << endl;
    cout << "e. Exit" << endl;
    cout << "Choose a function: ";
    cin >> choice;
    while (choice < 'a' || choice > 'e') {
        cout << "Invalid input. Please try again." << endl;
        cout << "Choose a function: ";
        cin >> choice;
    }
    return choice;
}

int main() {
    char choice = menuOption();
    while (choice != 'e') {
        if (choice == 'a') {
            binaryToDecimal();
        }
        else if (choice == 'b') {
            binaryToOtherBase();
        }
        else if (choice == 'c') {
            decimalToBinary();
        }
        else if (choice == 'd') {
            otherBaseToBinary();
        }

        choice = menuOption();
    }
    cout << "Thank you for using the program, now exiting." << endl;
    system("pause"); // Keeps the console window open
    return 0;
}
