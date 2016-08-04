#include "TextSearch.h"
#include "KnuthMorrisPratt.h"
#include "BoyerMooreHorspool.h"
#include "Naive.h"
#include "PerformanceChecker.h"
#include <fstream>
#include <iostream>
#include <unistd.h>
#include <string>

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

string convertFileToString(const string inputFilePath) {
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
    }
    return result;
}

int main() {

    string input;
    int i, j;
    TextSearch textSearch;

    cout << "Textdatei durchsuchen oder Performance-Vergleich? " << endl;
    cout << "0 : Textdatei durchsuchen" << endl;
    cout << "1 : Performance-Vergleich" << endl;
    cin >> j;

    if(j==0) {
        cout << "Geben Sie die Textdatei an: " << endl;
        cin >> input;

        textSearch.readFile(input);

        cout << "Nach welchem Pattern soll gesucht werden? " << endl;
        cin >> input;
        cout << input << endl;

        cout << "Mit welchem Algorithmus soll die Textdatei dursucht werden?" << endl;
        cout << "0 : Naiver-Algorithmus" << endl;
        cout << "1 : Knuth-Morris-Pratt-Algorithmus" << endl;
        cout << "2 : Boyer-Moore-Algorithmus" << endl;
        cin >> i;

        switch (i) {
            case 0:
                Naive(textSearch.getText(), input, false).run();
                break;
            case 1:
                KnuthMorrisPratt(textSearch.getText(), input, false).run();
                break;
            case 2:
                BoyerMooreHorspool(textSearch.getText(), input, false).run();
                break;
            default:
                break;
        }
    }

    if(j==1) {
        PerformanceChecker *performanceChecker = new PerformanceChecker();
        sleep(1);
        performanceChecker->executeAlgorithms();
        sleep(1);
        performanceChecker->generateHTMLOutput();
    }

}