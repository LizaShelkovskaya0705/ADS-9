// Copyright 2021 NNTU-CS
#include  <iostream>
#include  <fstream>
#include  <locale>
#include  <cstdlib>
#include  "bst.h"

BST<std::string> makeTree(const char* filename) {
    BST<std::string> Mytree;
    std::ifstream file(filename);
    std::string w;
    std::string w1 = "";
    std::string w2 = "";
    while (!file.eof()) {
        file >> w;
        w1 = w2 = "";
        if (w.find(",") != -1) {
                int l = w.length();
                int f = w.find(",");
                if ((f != l - 1) && ((w[f + 1] >= 'A' && w[f + 1] <= 'Z') ||
                    (w[f + 1] >= 'A' && w[f + 1] <= 'z'))) {
                for (int i = 0; i < f; i++) {
                    w1 += w[i];
                }
                for (int i = f+1; i < l; i++) {
                    w2 += w[i];
                }
            }
        }
        if (w1 != "" && w2 != "") {
            w1 = get_corr_word(w1);
            w2 = get_corr_word(w2);
            Mytree.add(w1);
            Mytree.add(w2);
        } else {
            w = get_corr_word(w);
            Mytree.add(w);
        }
    }
    return Mytree;
}

std::string get_corr_word(std::string s) {
    if (s[0] < '0' || s[0] > '9') {
        while ((s[0] >= 32 && s[0] <= 64) || (s[0] >= 91 && s[0] <= 96))
        s.erase(0, 1);
        if (s != "") {
            char ch = s[s.length() - 1];
            while ((ch >= 32 && ch <= 64) || (ch >= 91 && ch <= 96)) {
                s.pop_back();
                ch = s[s.length() - 1];
            }
        }
        int it = 0;
        if (s != "") {
            for (int i = 0; i < s.length(); i++) {
                if (s[i] == '\'') {
                    it = i;
                }
            }
            if (it != 0)
                s.erase(it);
        }
        if (s != "") {
            for (int i = 0; i < s.length(); i++) {
                s[i] = tolower(s[i]);
            }
        }
    } else {
        s.clear();
    }
    return s;
}
