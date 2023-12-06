// Advent of Code 2023: 2-Trebuchet?!
#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <string>

using namespace std;

map<string, string> digits = {
    {"one", "1"},
    {"two", "2"},
    {"three", "3"},
    {"four", "4"},
    {"five", "5"},
    {"six", "6"},
    {"seven", "7"},
    {"eight", "8"},
    {"nine", "9"}
};

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


string stringToDigit(const string& s) {
    string digit;

    auto it = digits.find(s);
    if (it != digits.end()) digit = (*it).second;
    else digit = "-1";

    return digit;
}


void parseDigits(string& s) {
    cout << s << endl;
    for (int i = 0; i < s.length(); ++i) {
        for (int j = 3; j <= 5; ++j) {
            cout << s << " i = " << i << "j = " << j << endl;
            string d = stringToDigit(s.substr(i, j));
            if (d != "-1") {
                s.replace(i, j - 1, d);
                break;
            }
        }
    }

    cout << s << endl;
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
        parseDigits(line);
        lines.push_back(line);
    }
    inputFile.close();

    cout << "The calibration value for the Trebuchet is: " << computeCalibrationValues(lines) << endl;
}