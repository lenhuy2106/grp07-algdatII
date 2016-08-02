#ifndef GRP07_ALGDATII_BOYERMOORE_H
#define GRP07_ALGDATII_BOYERMOORE_H
#include <string>
#include <map>

using namespace std;

class BoyerMooreHorspool {

private:

    string pattern;
    string text;
    string htmlOutput;
    int counter;
    map<char,int> badMatchTable;

    void writeHtmlFile(double elapsedTime);
    void run();

    void generateBadMatchTable(string pattern);
    int boyerMooreHorspoolSearch(string text);

public:

    BoyerMooreHorspool(string t, string p) : text(t), pattern(p){
        run();
    }

};



#endif //GRP07_ALGDATII_BOYERMOORE_H
