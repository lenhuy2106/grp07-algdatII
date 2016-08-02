#include "TextSearch.h"
#include "KnuthMorrisPratt.h"
#include "naive.h"
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
    /*string input;
    TextSearch textSearch;
    
    cout << "Hallo Dudeberger, gib mal Textdatei !" << endl;
    cin >> input;
    cout << input << endl;

    textSearch.readFile(input);
    
    cout << "Nach welchem Pattern soll gesucht werden?" << endl;
    cin >> input;
    cout << input << endl;
    
    KnuthMorrisPratt(textSearch.getText(), input);
    */
    
    Naive naive;
    
    int result = 0;
    int alreadyCutOff = 0;
    int counter = 0;
    string htmlOutput;
    
    string text = "acabzzazzab";
    string pattern = "ab";
    
    string subText = string(text);
    
    while(result >= 0) {
       result = naive.naiveSearch(subText, pattern);
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
    
    return 0;
}