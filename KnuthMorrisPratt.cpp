#include <iostream>
#include <fstream>
#include <chrono>
#include "KnuthMorrisPratt.h"

using namespace std;

void KnuthMorrisPratt::generatePrefixTable() {

    prefixTable = new int[pattern.length()];

    for (int i = 0; i < pattern.length(); i++) {
        prefixTable[i] = 0;
    }

    int index = 0;
    for (int i = 1; i < pattern.length();) {
        if (pattern[i] == pattern[index]) {
            prefixTable[i] = index + 1;
            index++;
            i++;
        } else {
            if (index != 0) {
                index = prefixTable[index - 1];
            } else {
                prefixTable[i] = 0;
                i++;
            }
        }
    }
}

int KnuthMorrisPratt::doKMPAlgorithmn(string subText) {

    int i = 0;
    int j = 0;

    while (i < subText.length() && j < pattern.length()) {
        if (subText[i] == pattern[j]) {
            i++;
            j++;
        } else {
            if (j != 0) {
                j = prefixTable[j - 1];
            } else {
                i++;
            }
        }
    }

    if (j == pattern.length()) {
        return i;
    }

    return -1;
}

void KnuthMorrisPratt::writeHtmlFile() {
    ofstream myfile;
    myfile.open("output.html");
    myfile << "<html><head><style>.p-colored em {background: #7FFF00;}</style></head><body><div class=\"p-colored\"><h1>Suche nach Pattern (\"";
    myfile << pattern;
    myfile << "\") ergab ";
    myfile << counter;
    myfile << " Treffer</h1>";
    myfile << "<h1> Ben&ouml;tigte Zeit: ";
    myfile << elapsedTime;
    myfile << " (Millisekunden) </h1>";
    myfile << htmlOutput;
    myfile << "</div></body></html>";
    myfile.close();
}

vector<int> KnuthMorrisPratt::run() {

    generatePrefixTable();

    chrono::steady_clock::time_point startTime;
    chrono::steady_clock::time_point endTime;
    chrono::duration<double, std::milli> elapsedTime;

    // hold all resulting indices
    vector<int> indices = {};

    int result = 0;
    int alreadyCutOff = 0;

    counter = 0;
    htmlOutput = "";

    string subText = string(text);

    while (result >= 0) {

        startTime = chrono::steady_clock::now();
        result = doKMPAlgorithmn(subText);
        endTime = chrono::steady_clock::now();

        elapsedTime += (endTime - startTime);

        if (result >= 0) {

            indices.push_back(alreadyCutOff+((result-pattern.length())));
            htmlOutput += subText.substr(0, result - pattern.length());
            htmlOutput += "<em>" + pattern + "</em>";

            cout << "Pattern found at Index: ";
            cout << alreadyCutOff + ((result - pattern.length()));
            cout << " - ";
            cout << alreadyCutOff + result;
            cout << "\n";

            alreadyCutOff += result;
            subText = subText.substr(result);
            counter++;
        } else {
            htmlOutput += subText;
        }
    }

    cout << "\nPattern found ";
    cout << counter;
    cout << " times\n";

    this->elapsedTime = elapsedTime.count();
    writeHtmlFile();

    return indices;
}