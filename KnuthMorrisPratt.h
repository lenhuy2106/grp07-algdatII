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
         * Methode generiert Prefixtable für den KMP-Algorithmus.
         */
        void generatePrefixTable();

        /**
         * Führt KMP-Algorithmus aus.
         * @param subText Der noch zu durchsuchende Text.
         * @return Index bei dem Suchwort gefunden wurde (Ende des Suchwortes).
         */
        int doKMPAlgorithmn(string subText);

        void writeHtmlFile(double elapsedTime);

        /**
         * Führt KMP-Algorithmus mehrmals aus,
         * berchnet Anzahl gefundener Strings, 
         * loggt Ergebnisse auf der Konsole
         * und erzeugt ein HTML-File als Output
         */
        void run();

    public:

        /**
         * Konstruktor für einen KMP-Algorithmus.
         * @param t Der zu durchsuchende Text als String.
         * @param p Der zu suchende String.
         */
        KnuthMorrisPratt(string t, string p) : text(t), pattern(p){
            run();
        }
};

#endif //GRP07_ALGDATII_KNUTHMORRISPRATT_H