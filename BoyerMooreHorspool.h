#ifndef GRP07_ALGDATII_BOYERMOORE_H
#define GRP07_ALGDATII_BOYERMOORE_H

#include <string>
#include <map>
#include <vector>

using namespace std;

/**
 * Klasse repräsentiert den Boyer Moore Suchalgorithmus für dynamische Texte.
 * Genauere beschreibung siehe Textsearch.h.
 */
class BoyerMooreHorspool {

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
     * Variable für Badmatchtable. Implementiert als Map.
     */
    map<char,int> badMatchTable;

    /**
     * Methode generiert html File mit den im Text gefundenen Wörtern, der Anzahl der gefundenen Wörter,
     * sowie der benötigten Gesamtzeit.
     */
    void writeHtmlFile();

    /**
     * Generiert die Badmatchtable.
     * @param pattern Das Pattern das gesucht wird. Aus diesem wird Table generiert.
     */
    void generateBadMatchTable(string pattern);

    /**
     * Führt BM-Algorithmus aus.
     * @param subText Der noch zu durchsuchende Text.
     * @return Index bei dem Suchwort gefunden wurde (Ende des Suchwortes).
     */
    int boyerMooreHorspoolSearch(string text);

public:

    /**
     * Konstruktor für einen BM-Algorithmus.
     * @param t Der zu durchsuchende Text als String.
     * @param p Der zu suchende String.
     */
    BoyerMooreHorspool(string t, string p) : text(t), pattern(p) {};

    /**
     * Führt BM-Algorithmus mehrmals aus,
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
};

#endif //GRP07_ALGDATII_BOYERMOORE_H