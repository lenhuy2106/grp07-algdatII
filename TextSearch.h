/* Algorithmen & Datenstrukturen II
 * Prof. Dr. Oliver Braun
 *
 * Blatt 2 - Teamprojekt
 * Thema: Suche in dynamischen Texten
 *
 * Team: Maximilian Keil, Long Mathias Yan, Andreas Buchmann, Huy Nu Le
 */
#ifndef TEXTSEARCH_TEXTSEARCH_H
#define TEXTSEARCH_TEXTSEARCH_H

#include <string>

using namespace std;

/**
 * Hauptanwendung zur Suche in dynamischen Texten. Anwendung liest über einen Userdialog einen Text, einen Suchstring,
 * sowie einen Parameter für den zu verwendenden Suchalgorithmus ein, sucht dann alle Vorkommen des Suchstrings im
 * Text, und gibt das Ergebnis in der Konsole aus.
 * Außerdem erzeugt die Anwendung ein html, welches den Text enthält, und in dem alle gefundenen Wörter in dem Text grün
 * hinterlegt sind.
 */
class TextSearch {

private:

    /**
     * Der text der durchsucht werden soll. Gespeichert als String.
     */
    string text;

public:

    /**
     * Methode liest eine .txt Datei ein  und legt diese im String text ab.
     * @param inputFilePath Pfad zur Textdatei die eingelesen werden soll.
     */
    void readFile(const string inputFilePath);

    /**
     * Setter für Text.
     * @param text Der Text als String.
     */
    void setText(const string text) {this->text = text;};

    /**
     * Getter für Text.
     * @return Den Text als String.
     */
    string getText() {return text;};
};

#endif //BBTREE_BBTREE_H