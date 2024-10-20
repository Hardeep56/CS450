#include <iostream>  // Includes the standard input/output stream library
#include <string>    // Includes the string library for handling strings

int main() {
    // Declare three string variables:
    // - str1: will hold the first input string from the user
    // - str2: will hold the second input string from the user
    // - result: will store the concatenated result of str1 and str2
    std::string str1, str2, result;

    // This 'for' loop will run 3 times, as indicated by the condition (i <= 3)
    // Each time, it will prompt the user for two strings, concatenate them, and print the result.
    for (int i = 1; i <= 3; i++) {
        // Prompt the user to enter the first string
        std::cout << "Enter string 1 (Trial " << i << "): ";
        // Use std::getline to capture the entire line of input, including spaces
        std::getline(std::cin, str1);

        // Prompt the user to enter the second string
        std::cout << "Enter string 2 (Trial " << i << "): ";
        // Again, use std::getline to capture the entire line of input
        std::getline(std::cin, str2);

        // Concatenate the two input strings using the '+' operator
        // The result is stored in the 'result' variable
        result = str1 + str2;

        // Output the concatenated result to the console
        // The "\n\n" at the end adds two newline characters to separate each trial's output
        std::cout << "Concatenated result (Trial " << i << "): " << result << "\n\n";
    }

    // Return 0 to indicate that the program ended successfully
    return 0;
}

