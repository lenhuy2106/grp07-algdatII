//
// Created by lenovo on 8/1/2016.
//

#ifndef GRP07_ALGDATII_BOYERMOORE_H
#define GRP07_ALGDATII_BOYERMOORE_H

using namespace std;

class BoyerMoore {

    map<char,int> generateBadMatchTable(string pattern);
    int boyerMooreSearch(string text, string pattern, int *prefixTable);

};


#endif //GRP07_ALGDATII_BOYERMOORE_H
