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
         * Variable für die Gesamtzeit die benötigt wurde.
         */
        double elapsedTime;

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
        KnuthMorrisPratt(string t, string p) : text(t), pattern(p){}

        /**
         * Führt KMP-Algorithmus mehrmals aus,
         * berchnet Anzahl gefundener Strings,
         * loggt Ergebnisse auf der Konsole
         * und erzeugt ein HTML-File als Output
         */
        vector<int> run();

        /**
         * Getter für die benötigte Gesamtzeit.
         * @return Die Zeit als Gleitkommazahl.
         */
        double getElapsedTime() { return elapsedTime; };
};

#endif //GRP07_ALGDATII_KNUTHMORRISPRATT_H