#include "PerformanceChecker.h"
#include "KnuthMorrisPratt.h"
#include "BoyerMooreHorspool.h"
#include "Naive.h"
#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <unistd.h>
#include <chrono>

PerformanceChecker::PerformanceChecker() {
    vector<string> test1 = {"test1.txt", "ipsum", "rutrum"};
    vector<string> test2 = {"test2.txt", "AB", "ABCDABD"};
    vector<string> test3 = {"test3.txt", "Passagiere", "der"};
    vector<string> test4 = {"test4.txt", "von", "Konsonantien"};
    vector<string> test5 = {"test5.txt", "Hooligans", "girls"};
    vector<string> test6 = {"RandomBinary.txt", "01001100001", "001000"};


    this->filesAndSearchValues.push_back(test1);
    this->filesAndSearchValues.push_back(test2);
    this->filesAndSearchValues.push_back(test3);
    this->filesAndSearchValues.push_back(test4);
    this->filesAndSearchValues.push_back(test5);
    this->filesAndSearchValues.push_back(test6);

    this->numberOfTestRuns = 5;
}

void PerformanceChecker::generateHTMLOutput() {

    ofstream myfile;
    myfile.open("performance_output.html");
    myfile << "<html><head><link rel=\"stylesheet\" href=\"http://maxcdn.bootstrapcdn.com/bootstrap/3.3.7/css/bootstrap.min.css\"></head><body style='width: 700px; margin: 0 auto;'>";
    for(int i=0; i<this->dataObjects.size(); i++) {
        myfile << "</br><a href='" + dataObjects[i].fileName + "'><h1>" + dataObjects[i].fileName + "  ( &bdquo;" + dataObjects[i].searchValue + "&ldquo; )</h1></a>";
        myfile << "<table class='table'><tr><th></th>";
        for(int i=0; i<numberOfTestRuns; i++) {
            myfile << "<th>";
            myfile << i+1;
            myfile << ". </th>";
        }
        myfile << "<th>Schnitt</th></tr>";

        myfile << "<tr><td>Naive</td>";

        double counter = 0;

        for(int j=0; j<dataObjects[i].runTimesNaive.size(); j++) {
            counter += dataObjects[i].runTimesNaive[j];
            myfile << "<td>";
            myfile << dataObjects[i].runTimesNaive[j];
            myfile << " &micro;s</td>";
        }
        myfile.flush();

        myfile << "<td>";
        myfile << (counter/numberOfTestRuns);
        myfile << " &micro;s</td></tr>";

        myfile << "<tr><td>KMP</td>";

        counter = 0;

        for(int j=0; j<dataObjects[i].runTimesKmp.size(); j++) {
            counter += dataObjects[i].runTimesKmp[j];
            myfile << "<td>";
            myfile << dataObjects[i].runTimesKmp[j];
            myfile << " &micro;s</td>";
        }
        myfile.flush();

        myfile << "<td>";
        myfile << (counter/numberOfTestRuns);
        myfile << " &micro;s</td></tr>";

        myfile << "<tr><td>BMH</td>";

        counter = 0;

        for(int j=0; j<dataObjects[i].runTimesBmh.size(); j++) {
            counter += dataObjects[i].runTimesBmh[j];
            myfile << "<td>";
            myfile << dataObjects[i].runTimesBmh[j];
            myfile << " &micro;s</td>";
        }
        myfile.flush();

        myfile << "<td>";
        myfile << (counter/numberOfTestRuns);
        myfile << " &micro;s</td></tr></table></br>";

        myfile << "<div style='width: 100%; height: 100px;'>";

        myfile << "<div style='width: 45%; float: left;'>PrefixTable:";
        if(dataObjects[i].prefixTable.size() > 0) {
            myfile << "<table class='table'><tr>";
            for(int p=0; p<dataObjects[i].prefixTable.size(); p++) {
                myfile << "<th>";
                myfile << dataObjects[i].searchValue.at(p);
                myfile << "</th>";
            }
            myfile << "</tr><tr>";
            for(int p=0; p<dataObjects[i].prefixTable.size(); p++) {
                myfile << "<td>";
                myfile << dataObjects[i].prefixTable.at(p);
                myfile << "</td>";
            }
            myfile << "</tr></table></div>";
        }
        myfile.flush();


        myfile << "<div style='width: 45%; float: right;'>Bad-Match-Table:</br>";
        if(dataObjects[i].badMatchTable.size() > 0) {
            myfile << "<table class='table'><tr>";
            for(auto kv : dataObjects[i].badMatchTable) {
                myfile << "<th>";
                myfile << kv.first;
                myfile << "</th>";
            }
            myfile << "<th>#</th>";
            myfile << "</tr><tr>";
            for(auto kv : dataObjects[i].badMatchTable) {
                myfile << "<td>";
                myfile << kv.second;
                myfile << "</td>";
            }
            myfile << "<td>";
            myfile << dataObjects[i].searchValue.length();
            myfile << "</td>";

            myfile << "</tr></table></br></div></div></br>";
        }
        myfile.flush();

    }

    myfile << "</body></html>";

    myfile.close();
}

void PerformanceChecker::generateOutput() {
    for(int i=0; i<this->dataObjects.size(); i++) {
        cout << dataObjects[i].fileName;
        cout << " - ";
        cout << dataObjects[i].searchValue;
        cout << "\n";
        cout << "Naive: ";

        double counter = 0;

        for(int j=0; j<dataObjects[i].runTimesNaive.size(); j++) {
            counter += dataObjects[i].runTimesNaive[j];
            cout << dataObjects[i].runTimesNaive[j];
            cout << " ";
        }

        cout << "  ~ ";
        cout << (counter/numberOfTestRuns);
        cout << "\n";

        cout << "KMP: ";
        counter = 0;

        for(int j=0; j<dataObjects[i].runTimesKmp.size(); j++) {
            counter += dataObjects[i].runTimesKmp[j];
            cout << dataObjects[i].runTimesKmp[j];
            cout << " ";
        }

        cout << "  ~ ";
        cout << (counter/numberOfTestRuns);
        cout << "\n";

        cout << "BMH: ";
        counter = 0;

        for(int j=0; j<dataObjects[i].runTimesBmh.size(); j++) {
            counter += dataObjects[i].runTimesBmh[j];
            cout << dataObjects[i].runTimesBmh[j];
            cout << " ";
        }

        cout << "  ~ ";
        cout << (counter/numberOfTestRuns);
        cout << "\n\n\n";
    }
}

void PerformanceChecker::executeAlgorithms() {

    for(int i=0; i<this->filesAndSearchValues.size(); i++) {
        vector<string> searchValues = this->filesAndSearchValues[i];
        string fileText = convertFileToString(searchValues[0]);
        for(int j=1; j<searchValues.size(); j++) {

            DataObject dataObject = DataObject(searchValues[0], searchValues[j]);
            for(int n=0; n<numberOfTestRuns; n++) {
                Naive *naive = new Naive(fileText, searchValues[j]);
                naive->run();
                dataObject.runTimesNaive.push_back(naive->getElapsedTime());
            }

            sleep(1);

            for(int n=0; n<numberOfTestRuns; n++) {
                KnuthMorrisPratt *kmp = new KnuthMorrisPratt(fileText, searchValues[j]);
                kmp->run();
                dataObject.runTimesKmp.push_back(kmp->getElapsedTime());

                if(n==numberOfTestRuns-1) {
                    dataObject.prefixTable = kmp->getPrefixTable();
                }
            }

            sleep(1);

            for(int n=0; n<numberOfTestRuns; n++) {
                BoyerMooreHorspool *bmh = new BoyerMooreHorspool(fileText, searchValues[j]);
                bmh->run();
                dataObject.runTimesBmh.push_back(bmh->getElapsedTime());

                if(n==numberOfTestRuns-1) {
                    dataObject.badMatchTable = bmh->getBadMatchTable();
                }
            }

            sleep(1);

            dataObjects.push_back(dataObject);
        }

    }

}

string PerformanceChecker::convertFileToString(const string inputFilePath) {
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
    }
    return result;
}

