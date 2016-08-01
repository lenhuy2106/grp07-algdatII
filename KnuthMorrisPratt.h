//
// Created by lenovo on 7/27/2016.
//

#ifndef GRP07_ALGDATII_KNUTHMORRISPRATT_H
#define GRP07_ALGDATII_KNUTHMORRISPRATT_H
#include <string>

using namespace std;

class KnuthMorrisPratt{

    private:
        
        string pattern;
        string text;
        int* prefixTable;
        string htmlOutput;
        int counter;

        void generatePrefixTable();
        int doKMPAlgorithmn(string subText);
        void writeHtmlFile();
        void run();

    public:
        
        KnuthMorrisPratt(string t, string p) : text(t), pattern(p){
            run();
        }
                
};

#endif //GRP07_ALGDATII_KNUTHMORRISPRATT_H
