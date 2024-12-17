/*
Advent of code 2024, day one - Historian Hysteria.
*/

#include <iostream>
#include <algorithm>
#include <fstream>
#include <cstdlib> 
#include <cmath>   

using namespace std;

void pairUp(int vector1[], int vector2[], int size) {
    sort(vector1, vector1 + size);
    sort(vector2, vector2 + size);
}

void printIDsVectors(int vector1[], int vector2[], int size) {
    cout << "Vector 1: ";
    for (int i = 0; i < size; i++) {
        cout << vector1[i];
        if (i < size - 1) {
            cout << ", ";
        } else {
            cout << ".\n";
        }
    }

    cout << "Vector 2: ";
    for (int i = 0; i < size; i++) {
        cout << vector2[i];
        if (i < size - 1) {
            cout << ", ";
        } else {
            cout << ".\n";
        }
    }
}

void findTheDistance(int vector1[], int vector2[], int size) {
    int totalDistances = 0;

    for (int i = 0; i < size; i++) {
        totalDistances += abs(vector1[i] - vector2[i]);
    }

    cout << "The total distance is: " << totalDistances << ".\n";
}

//function (subroutine) for the second part of the test
void similarityScore(int vector1[], int vector2[], int size){
    int similarityVector[1000], similarityScore;

    for(int i=0; i<size ; i++){
    int similarityCounter = 0;
        for(int j=0; j<size; j++){
            if(vector1[i] == vector2[j]){
                similarityCounter ++;
            }
        }
        similarityVector[i] = vector1[i] * similarityCounter;
    }

    for(int i=0; i<size; i++){
        similarityScore += similarityVector[i];
    }

    cout << "The similarity score is: " << similarityScore;
}

int main() {
    int IDOne[1000]; // Array for the first column
    int IDTwo[1000]; // Array for the second column
    int currentLine = 0;
    
    string filePath = "C:/Users/cinti/OneDrive/Área de Trabalho/AdventofCode2024inputs.txt"; // Input file path
    ifstream inputFile(filePath);
    string line;

    if (!inputFile.is_open()) {
        cerr << "Error opening file: " << filePath << endl;
        return 1;
    }

    // Read data from the file and store it in arrays
    while (getline(inputFile, line) && currentLine < 1000) {
        if (line.empty()) continue; // Ignore empty lines

        size_t pos = line.find(' '); // Search for delimiter (space)
        if (pos != string::npos) {
            try {
                // Convert strings to integers and store in arrays
                IDOne[currentLine] = stoi(line.substr(0, pos));             // Part before space
                IDTwo[currentLine] = stoi(line.substr(pos + 1, line.size())); // Part after space
                currentLine++;
            } catch (const invalid_argument& e) {
                cerr << "Conversion error for number on line: " << line << endl;
            }
        } else {
            cerr << "Invalid line or no delimiter: " << line << endl;
        }
    }

    inputFile.close();

    // Process the data
    pairUp(IDOne, IDTwo, currentLine);
    printIDsVectors(IDOne, IDTwo, currentLine);
    findTheDistance(IDOne, IDTwo, currentLine);
    similarityScore(IDOne, IDTwo, currentLine); //function (subroutine) for the second part of the test

    return 0;
}
