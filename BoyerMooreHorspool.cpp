#include <map>
#include <iostream>
#include <fstream>
#include <chrono>
#include <unordered_map>
#include "BoyerMooreHorspool.h"
#include <math.h>

using namespace std;

void BoyerMooreHorspool::generateBadMatchTable(string pattern) {

    int R = 256;

    // position of rightmost occurrence of c in the pattern
    vector<int> right = vector<int>(R);
    for (int c = 0; c < R; c++)
        right[c] = -1;

    for (int j = 0; j < pattern.length(); j++)
        right[pattern.at(j)] = j;

    this->badMatchTable = right;

}

int BoyerMooreHorspool::boyerMooreHorspoolSearch(string subText) {

    int m = pattern.length();
    int n = subText.length();
    int skip;
    for (int i = 0; i <= n - m; i += skip) {
        skip = 0;
        for (int j = m-1; j >= 0; j--) {
            if (pattern.at(j) != subText.at(i+j)) {
                skip = fmax(1, j - badMatchTable[subText.at(i+j)]);
                break;
            }
        }
        if (skip == 0) return i+patternLength;    // found
    }
    return -1;                       // not found

}

void BoyerMooreHorspool::writeHtmlFile() {
    ofstream myfile;
    myfile.open (pattern + ".html");
    myfile << "<html><head><style>.p-colored em {background: #7FFF00;}</style></head><body><div class=\"p-colored\"><h1>Suche nach Pattern (\"";
    myfile << pattern;
    myfile << "\") ergab ";
    myfile << counter;
    myfile << " Treffer</h1>";
    if(!perfomanceTest) {
        myfile << "<h1> Ben&ouml;tigte Zeit: ";
        myfile << elapsedTime;
        myfile << " (Microsekunden) </h1>";
    }
    myfile << htmlOutput;
    myfile << "</div></body></html>";
    myfile.close();
}

vector<int> BoyerMooreHorspool::run() {

    //string pattern = "am";
    //string text = "Money ist am fly sein";
    counter = 0;
    int result = 0;
    int alreadyCutOff = 0;
    htmlOutput = "";

    generateBadMatchTable(pattern);

    // hold all resulting indices
    vector<int> indices = {};

    chrono::steady_clock::time_point startTime;
    chrono::steady_clock::time_point endTime;
    chrono::duration<double, std::micro> elapsedTime;

    // show content:
    //for (unordered_map<char,int>::iterator it=badMatchTable.begin(); it!=badMatchTable.end(); ++it)
    //   std::cout << it->first << " => " << it->second << '\n';

    string subText = text;

    while(result >= 0) {
        //cout << "\nnew\n";

        startTime = chrono::steady_clock::now();
        result = boyerMooreHorspoolSearch(subText);
        endTime = chrono::steady_clock::now();

        elapsedTime += (endTime - startTime);

        if(result >= 0) {

            indices.push_back(alreadyCutOff+((result-pattern.length())));
            htmlOutput += subText.substr(0, result - pattern.length());
            htmlOutput += "<em>" + pattern + "</em>";

            cout << "Pattern found at Index: ";
            cout << alreadyCutOff+(result - pattern.length());
            cout << " - ";
            cout << alreadyCutOff+(result );
            cout << "\n";

            alreadyCutOff += result;
            subText = subText.substr(result);
            //cout << "while " << subText;
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