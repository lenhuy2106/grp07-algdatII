//
// Created by lenhuy2106 on 2016-07-27.
//

#include "naive.h"

int Naive::naiveSearch(string text, string pattern) const {
        int i=0;
        int j=0;
        int k=0;
        while(i < text.length() && j < pattern.length()){
            if(text[i] == pattern[j]){
                i++;
                j++;
            }else{
                j=0;
                k++;
                i = k;
            }
        }
        if(j == pattern.length()){
            return k+j;
        }
        return -1;
}
