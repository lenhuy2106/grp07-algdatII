#include "TextSearch.h"
#include "KnuthMorrisPratt.h"
#include <fstream>
#include <iostream>

using namespace std;

void TextSearch::readFile(const string inputFilePath) {
    ifstream ifStream;
    string s;
    string result;
    ifStream.open(inputFilePath);
    if (ifStream.is_open()) {
        cout << "reading ... " << endl;

        while (!ifStream.eof()) {
            getline(ifStream, s);
            result.append("\n");
            result.append(s);
        }
        ifStream.close();
        
        setText(result);      
        
        cout << "file read" << endl;
    } else {
        cout << "File not found" << endl;
    }
}

int main() {
    string input;
    TextSearch textSearch;
    
    cout << "Hallo Dudeberger, gib mal Textdatei !" << endl;
    cin >> input;
    cout << input << endl;

    textSearch.readFile(input);
    
    cout << "Nach welchem Pattern soll gesucht werden?" << endl;
    cin >> input;
    cout << input << endl;
    
    KnuthMorrisPratt(textSearch.getText(), input);
    
    return 0;
}