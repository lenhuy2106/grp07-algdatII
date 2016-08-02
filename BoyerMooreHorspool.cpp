//
// Created by lenovo on 8/1/2016.
//


#include <map>
#include <iostream>
#include <fstream>
#include "BoyerMooreHorspool.h"

using namespace std;

void BoyerMooreHorspool::generateBadMatchTable(string pattern) {

    int patternLength = pattern.length();

    map<char,int> badMatchTable = {};

    for(int i = 0; i < patternLength; i++){
        char currentChar = pattern[i];
        int badMatchValue =  patternLength - i - 1;
        badMatchTable[currentChar] = badMatchValue;

        if(badMatchValue == 0) {
            badMatchTable[currentChar] = patternLength;
        }
    }

    //badMatchTable['*'] = patternLength;
    this->badMatchTable = badMatchTable;
}

int BoyerMooreHorspool::boyerMooreHorspoolSearch(string subText) {

    int patternLength = pattern.length();
    int patternIndex = 0;
    int subTextIndex = 0;
    char currentChar = ' ';
    //cout << pattern;
    //cout << subText;

    while(subTextIndex < (subText.length() - patternLength) && patternIndex < pattern.length()){
        if(subText[subTextIndex + (patternLength - patternIndex)] == pattern[patternLength - patternIndex - 1]){
            //cout << "\nmatched\n";
            patternIndex++;
        }else{
            //[subTextIndex + (patternLength - patternIndex)]
            string tmp = subText.substr(subTextIndex, patternLength);
            //cout << "\n TID :" << subTextIndex << " PID :" << patternLength;
            //cout << "\nskipped\n" << tmp << " & " << pattern[patternLength - patternIndex - 1];
            currentChar = subText[subTextIndex + (patternLength - patternIndex)];
            if(badMatchTable.find(currentChar) != badMatchTable.end()){
                subTextIndex += badMatchTable.at(currentChar);
                //cout << " Char:" << currentChar << " Val: " << badMatchTable.at(currentChar);
            } else {
                subTextIndex += patternLength;
            }
            patternIndex = 0;
        }
    }

    if(patternIndex >= pattern.length()){
        return subTextIndex;
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
    myfile << htmlOutput;
    myfile << "</div></body></html>";
    myfile.close();
}

void BoyerMooreHorspool::run() {

    //string pattern = "am";
    //string text = "Money ist am fly sein";
    counter = 0;
    int result = 0;
    int alreadyCutOff = 0;
    htmlOutput = "";

    generateBadMatchTable(pattern);
    // show content:
    for (map<char,int>::iterator it=badMatchTable.begin(); it!=badMatchTable.end(); ++it)
       std::cout << it->first << " => " << it->second << '\n';

    string subText = text;

    while(result >= 0 && subText.length() >= pattern.length()) {
        //cout << "\nnew\n";

        result = boyerMooreHorspoolSearch(subText);

        if(result >= 0) {

            htmlOutput += subText.substr(0, result + 1);
            htmlOutput += "<em>" + pattern + "</em>";

            cout << "Pattern found at Index: ";
            cout << alreadyCutOff+(result + 1);
            cout << " - ";
            cout << alreadyCutOff+(result + 1 + pattern.length());
            cout << "\n";

            alreadyCutOff += result + 1 + pattern.length();
            subText = subText.substr(result + 1 + pattern.length());
            //cout << "while " << subText;
            counter++;
        } else {
            htmlOutput += subText;
        }
    }

    cout << "\nPattern found ";
    cout << counter;
    cout << " times\n";

    writeHtmlFile();

}