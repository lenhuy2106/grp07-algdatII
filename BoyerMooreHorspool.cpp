#include <map>
#include <iostream>
#include <fstream>
#include <chrono>
#include <unordered_map>
#include "BoyerMooreHorspool.h"

using namespace std;

void BoyerMooreHorspool::generateBadMatchTable(string pattern) {

    int patternLength = pattern.length();

    unordered_map<char,int> badMatchTable = {};

    for(int i = 0; i < patternLength - 1; i++){
        char currentChar = pattern[i];
        int badMatchValue =  patternLength - i - 1;
        badMatchTable[currentChar] = badMatchValue;
    }

    //badMatchTable['*'] = patternLength;
    this->badMatchTable = badMatchTable;
}

int BoyerMooreHorspool::boyerMooreHorspoolSearch(string subText) {

    //int patternLength = pattern.length();
    int patternIndex = 0;
    int subTextIndex = 0;
    char startingChar = ' ';

    if(subText.length() >= patternLength) {
        while(subTextIndex <= (subText.length() - patternLength) && patternIndex < patternLength){
            startingChar = subText[subTextIndex + patternLength - 1];
            if(subText[subTextIndex + (patternLength - patternIndex - 1)] == pattern[patternLength - patternIndex - 1]){
                patternIndex++;
            }else{
                if(badMatchTable.find(startingChar) != badMatchTable.end()){
                    subTextIndex += badMatchTable.at(startingChar);
                } else {
                    subTextIndex += patternLength;
                }
                patternIndex = 0;
            }
        }
    }


    if(patternIndex == pattern.length()){
        return subTextIndex + patternLength ;
    }

    return -1;
}

void BoyerMooreHorspool::writeHtmlFile() {
    ofstream myfile;
    myfile.open ("output.html");
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