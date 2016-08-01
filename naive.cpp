//
// Created by lenhuy2106 on 2016-07-27.
//

#include "naive.h"

int Naive::naiveSearch(string text, string pattern, int textLength, int patternLength) const {
    unsigned int i = 0, j = 0;
    // correct while header ?
    while (i <= textLength && j <= patternLength) {
        // compare by == ?
        if (text.at(i) == pattern.at(j)) {
            i++;
            j++;
        }
        else {
            i = i - j + 2;
            j = 1;
        }
    }

    return j > patternLength
        ? i - patternLength
        : i;
}
