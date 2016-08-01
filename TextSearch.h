#ifndef TEXTSEARCH_TEXTSEARCH_H
#define TEXTSEARCH_TEXTSEARCH_H

#include <string>

using namespace std;

class TextSearch {

private:

    string text;

public:

    void readFile(const string);
    void setText(const string text) {this->text = text;};
    string getText() {return text;};
};

#endif //BBTREE_BBTREE_H