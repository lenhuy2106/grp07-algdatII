#include "TextSearch.h"
#include <fstream>
#include <iostream>

using namespace std;

void readFile(const string inputFile) {
    ifstream ifStream;
    string s;
    string result;
    ifStream.open(inputFile);
    if (ifStream.is_open()) {
        cout << "reading ... " << endl;

        while (!ifStream.eof()) {
            getline(ifStream, s);
            result.append("\n");
            result.append(s);
        }
        ifStream.close();

        cout << result << endl;
        cout << "file read" << endl;
    } else {
        cout << "File not found" << endl;
    }
}

int main() {
    string input;

    cout << "Hallo Dudeberger, gib mal Textdatei !" << endl;
    cin >> input;
    cout << input << endl;

    readFile(input);

    return 0;
}