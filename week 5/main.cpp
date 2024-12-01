#include <iostream>
#include <fstream>
#include <string>
#include <algorithm> // For std::reverse
using namespace std;

// Function to reverse file content and save to a new file
void reverseFileContent(const string& inputFileName, const string& outputFileName) {
    ifstream inputFile(inputFileName);
    ofstream outputFile(outputFileName);
    
    if (!inputFile.is_open() || !outputFile.is_open()) {
        cerr << "Error: Unable to open file(s)." << endl;
        return;
    }

    string content((istreambuf_iterator<char>(inputFile)), istreambuf_iterator<char>());
    reverse(content.begin(), content.end()); // Reverse the file content
    outputFile << content; // Write reversed content to the new file

    inputFile.close();
    outputFile.close();
}

int main() {
    string inputFileName = "CSC450_CT5_mod5.txt";
    string outputFileName = "CSC450-mod5-reverse.txt";

    // Open the original file in append mode
    ofstream outputFile(inputFileName, ios::app);
    if (!outputFile.is_open()) {
        cerr << "Error: Unable to open the file for appending." << endl;
        return 1;
    }

    // Get user input and append to the file
    cout << "Enter data to append to the file:" << endl;
    string userInput;
    getline(cin, userInput);
    outputFile << userInput << endl; // Append user input
    outputFile.close();

    // Reverse the content of the file and save to a new file
    reverseFileContent(inputFileName, outputFileName);

    cout << "Data appended and reversed content stored in " << outputFileName << endl;

    return 0;
}
