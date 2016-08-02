#ifndef GRP07_ALGDATII_KNUTHMORRISPRATT_H
#define GRP07_ALGDATII_KNUTHMORRISPRATT_H

#include <string>

using namespace std;

/**
 * Klasse repräsentiert den Knuth-Morris-Pratt Suchalgorithmus für dynamische Texte.
 * Genauere beschreibung siehe Textsearch.h.
 */
class KnuthMorrisPratt{

    private:

        /**
         *
         */
        string pattern;

        /**
         *
         */
        string text;

        /**
         *
         */
        int* prefixTable;

        /**
         *
         */
        string htmlOutput;

        /**
         *
         */
        int counter;

        /**
         *
         */
        void generatePrefixTable();

        /**
         *
         * @param subText
         * @return
         */
        int doKMPAlgorithmn(string subText);

        /**
         *
         */
        void writeHtmlFile();

        /**
         *
         */
        void run();

    public:

        /**
         * 
         * @param t
         * @param p
         * @return
         */
        KnuthMorrisPratt(string t, string p) : text(t), pattern(p){
            run();
        }
};

#endif //GRP07_ALGDATII_KNUTHMORRISPRATT_H