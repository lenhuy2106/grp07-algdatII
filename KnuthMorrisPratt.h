#ifndef GRP07_ALGDATII_KNUTHMORRISPRATT_H
#define GRP07_ALGDATII_KNUTHMORRISPRATT_H

#include <string>
#include <vector>

using namespace std;

/**
 * Klasse repräsentiert den Knuth-Morris-Pratt Suchalgorithmus für dynamische Texte.
 * Genauere beschreibung siehe Textsearch.h.
 */
class KnuthMorrisPratt{

    private:

        /**
         * Der zu suchende String (Pattern).
         */
        string pattern;

        /**
         * Der zu durchsuchende Text.
         */
        string text;

        /**
         * Zeiger auf den Prefixtable.
         */
        int* prefixTable;

        /**
         * Variable für den generierten HTML-Output-String.
         */
        string htmlOutput;

        /**
         * Variable für Anzahl gefundener Strings.
         */
        int counter;

        /**
         * Variable für die Gesamtzeit die benötigt wurde. In Mikrosekunden.
         */
        double elapsedTime;

        /**
        * Variable um HTML Output in Performance Messung auszublenden.
        */
        bool perfomanceTest;

        /**
         * Methode generiert Prefixtable für den KMP-Algorithmus.
         */
        void generatePrefixTable();

        /**
         * Führt KMP-Algorithmus aus.
         * @param subText Der noch zu durchsuchende Text.
         * @return Index bei dem Suchwort gefunden wurde (Ende des Suchwortes).
         */
        int doKMPAlgorithmn(string subText);

        /**
         * Methode generiert html File mit den im Text gefundenen Wörtern, der Anzahl der gefundenen Wörter,
         * sowie der benötigten Gesamtzeit.
         */
        void writeHtmlFile();

    public:

        /**
         * Konstruktor für einen KMP-Algorithmus.
         * @param t Der zu durchsuchende Text als String.
         * @param p Der zu suchende String.
         */
        KnuthMorrisPratt(string t, string p, bool perfomanceTest) : text(t), pattern(p), perfomanceTest(perfomanceTest){}

        /**
         * Führt KMP-Algorithmus mehrmals aus,
         * berchnet Anzahl gefundener Strings,
         * loggt Ergebnisse auf der Konsole
         * und erzeugt ein HTML-File als Output
         */
        vector<int> run();

        /**
         * Getter für die benötigte Gesamtzeit.
         * @return Die Zeit als Gleitkommazahl. In Mikrosekunden.
         */
        double getElapsedTime() { return elapsedTime; };

        /**
         * Getter für Prefix Table. Wird für HTML Output benötigt.
         * @return Prefix Table als vector.
         */
        vector<int> getPrefixTable() {
                vector<int> result;
                for (int index = 0; index < pattern.length(); ++index) {
                        result.push_back(prefixTable[index]);
                }
                return result;
        }
};

#endif //GRP07_ALGDATII_KNUTHMORRISPRATT_H