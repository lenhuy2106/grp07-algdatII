#include <iostream>
#include <fstream>
#include "Naive.h"

int Naive::doNaiveAlgorithmn(string subText) const {
        int i=0;
        int j=0;
        int k=0;
        while(i < subText.length() && j < pattern.length()){
            if(subText[i] == pattern[j]){
                i++;
                j++;
            }else{
                j=0;
                k++;
                i = k;
            }
        }
        if(j == pattern.length()){
            return k+j;
        }
        return -1;
}

void Naive::writeHtmlFile() {
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

void Naive::run() {
    
    int result = 0;
    int alreadyCutOff = 0;
        
    counter = 0;
    htmlOutput = "";
    
    string subText = string(text);
    
    while(result >= 0) {
       result = doNaiveAlgorithmn(subText);
       if(result >= 0) {
           
            htmlOutput += subText.substr(0, result-pattern.length());
            htmlOutput += "<em>" + pattern + "</em>";

            cout << "Pattern found at Index: ";
            cout << alreadyCutOff+((result-pattern.length()));
            cout << " - ";
            cout << alreadyCutOff+result;
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
    
    writeHtmlFile();
}
