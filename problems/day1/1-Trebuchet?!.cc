// Advent of Code 2023: Trebuchet?!
#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;


int computeCalibrationValues(const vector<string>& lines) {
    int sum = 0;

    for (int i = 0; i < lines.size(); ++i) {
        string l = lines[i];

        char firstD, lastD;
        int lIndex = 0;
        
        while (lIndex < l.length()) {
            char c = l[lIndex];

            if (c >= '0' && c <= '9') {
                firstD = c;
                break;
            }

            ++lIndex;
        }

        while (lIndex < l.length()) {
            char c = l[lIndex];

            if (c >= '0' && c <= '9') lastD = c;

            ++lIndex;
        }

        sum += 10*(firstD-'0') + (lastD-'0');
    }

    return sum;
}


int main() {
    string file = "input.txt";

    ifstream inputFile(file);

    if (!inputFile.is_open()) {
        cerr << "Error al abrir el archivo: " << file << std::endl;
        return 1;
    }
    
    vector<string> lines;
    string line;
    while (getline(inputFile, line)) {
        lines.push_back(line);
    }
    inputFile.close();

    cout << "The calibration value for the Trebuchet is: " << computeCalibrationValues(lines) << endl;
}