#include "TextSearch.h"
#include "KnuthMorrisPratt.h"
#include "BoyerMooreHorspool.h"
#include "Naive.h"
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
    int i;
    TextSearch textSearch;

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
            Naive(textSearch.getText(), input).run();
            break;
        case 1:
            KnuthMorrisPratt(textSearch.getText(), input).run();
            break;
        case 2:
            BoyerMooreHorspool(textSearch.getText(), input).run();
            break;
        default:
            break;
    }

    /*
    string input;
    int i;
    TextSearch textSearch;

    cout << "Taste drücken zum starten: " << endl;
    cin >> input;

    int numberOfTests = 8;
    vector<string> files(numberOfTests);
    files={"test1.txt",
           "test1.txt",
           "test2.txt",
           "test2.txt",
           "test3.txt",
           "test3.txt",
           "test4.txt",
           "test4.txt"};

    vector<string> pattern(numberOfTests);
    pattern={"ipsum",
             "rutrum",
             "AB",
             "ABCDABD",
             "Passagiere",
             "der",
             "von",
             "Konsonantien"};

    double *elapsedTimeNaive = new double[numberOfTests];
    double *elapsedTimeKnuthMorrisPratt = new double[numberOfTests];
    double *elapsedTimeBoyerMooreHorspool = new double[numberOfTests];

    for (int i = 0; i < numberOfTests; i++) {

        string text = convertFileToString(files[i]);

        Naive *naive = new Naive(text, pattern[i]);
        naive->run();
        elapsedTimeNaive[i] = naive->getElapsedTime();


        KnuthMorrisPratt *kmp = new KnuthMorrisPratt(text, pattern[i]);
        kmp->run();
        elapsedTimeKnuthMorrisPratt[i] = kmp->getElapsedTime();

        BoyerMooreHorspool *bmh = new BoyerMooreHorspool(text, pattern[i]);
        bmh->run();
        elapsedTimeBoyerMooreHorspool[i] = bmh->getElapsedTime();
    }

    ofstream myfile;
    myfile.open("benchmarks.html");
    for (int i = 0; i < numberOfTests; i++) {
        myfile << files[i] + ":" + pattern[i] + ":";
        myfile << elapsedTimeNaive[i];
        myfile << ":";
        myfile << elapsedTimeKnuthMorrisPratt[i];
        myfile << ":";
        myfile << elapsedTimeBoyerMooreHorspool[i];
        myfile << "\n";
    }
    myfile.close();
    */
}