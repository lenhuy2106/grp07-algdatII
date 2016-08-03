#ifndef DYNAMICTEXTSEARCH_PERFORMANCECHECKER_H
#define DYNAMICTEXTSEARCH_PERFORMANCECHECKER_H

#include <string>
#include <map>
#include <vector>
#include <unordered_map>

using namespace std;

class PerformanceChecker {

    private:

        struct DataObject {
            string fileName;
            string searchValue;
            vector<double> runTimesNaive = {};
            vector<double> runTimesKmp = {};
            vector<double> runTimesBmh = {};
            vector<int> prefixTable = {};
            unordered_map<char,int> badMatchTable;
            DataObject(string f, string s) : fileName(f), searchValue(s) {};
        };


        vector<vector<string>> filesAndSearchValues = {};
        vector<DataObject> dataObjects = {};
        int numberOfTestRuns;
        string convertFileToString(const string inputFilePath);

    public:

        PerformanceChecker();
        void executeAlgorithms();
        void generateOutput();
        void generateHTMLOutput();

};


#endif //DYNAMICTEXTSEARCH_PERFORMANCECHECKER_H
