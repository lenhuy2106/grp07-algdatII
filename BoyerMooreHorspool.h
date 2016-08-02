#ifndef GRP07_ALGDATII_BOYERMOORE_H
#define GRP07_ALGDATII_BOYERMOORE_H
#include <string>
#include <map>
#include <vector>

using namespace std;

class BoyerMooreHorspool {

private:

    string pattern;
    string text;
    string htmlOutput;
    int counter;

    double elapsedTime;
    map<char,int> badMatchTable;

    void writeHtmlFile(double elapsedTime);

    void generateBadMatchTable(string pattern);
    int boyerMooreHorspoolSearch(string text);

public:

    BoyerMooreHorspool(string t, string p) : text(t), pattern(p) {};

    vector<int> run();

    double getElapsedTime() { return elapsedTime; };
};



#endif //GRP07_ALGDATII_BOYERMOORE_H
