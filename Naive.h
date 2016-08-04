#ifndef DYNAMICTEXTSEARCH_NAIVE_H
#define DYNAMICTEXTSEARCH_NAIVE_H

#include <string>
#include <vector>

using namespace std;

/**
 * Klasse repräsentiert den Naiven Suchalgorithmus für dynamische Texte.
 * Genauere beschreibung siehe Textsearch.h.
 */
class Naive {
   
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
         * Variable für den generierten HTML-Output-String.
         */
        string htmlOutput;

        /**
         * Variable für Anzahl gefundener Strings.
         */
        int counter;

        /**
        * Variable für die Zeitmessung. Insgesamt benötigte Zeit. In Mikrosekunden.
        */
        double elapsedTime;

        /**
         * Variable um HTML Output in Performance Messung auszublenden.
         */
        bool perfomanceTest;

        /**
         * Führt Naiven-Algorithmus aus.
         * @param subText Der noch zu durchsuchende Text.
         * @return Index bei dem Suchwort gefunden wurde (Ende des Suchwortes).
         */
        int doNaiveAlgorithmn(string subText) const;

        /**
         * Methode generiert html File mit den im Text gefundenen Wörtern, der Anzahl der gefundenen Wörter,
         * sowie der benötigten Gesamtzeit.
         */
        void writeHtmlFile();

        
    public:

        /**
         * Konstruktor für einen Naiven-Algorithmus.
         * @param t Der zu durchsuchende Text als String.
         * @param p Der zu suchende String.
         */
        Naive(string t, string p, bool perfomanceTest) : text(t), pattern(p), perfomanceTest(perfomanceTest) {}

        /**
         * Führt Naiven-Algorithmus mehrmals aus,
         * berchnet Anzahl gefundener Strings,
         * loggt Ergebnisse auf der Konsole
         * und erzeugt ein HTML-File als Output
         */
        vector<int> run();

        /**
         * Gettter für die benötigte Zeit.
         * @return Die benötigte Zeit als Gleitkommazahl. In Mikrosekunden.
         */
        double getElapsedTime() { return elapsedTime; };
};

#endif //DYNAMICTEXTSEARCH_NAIVE_H
