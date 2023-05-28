// Copyright 2021 NNTU-CS
#include  <iostream>
#include  <fstream>
#include  <locale>
#include  <cstdlib>
#include  "bst.h"

BST<std::string> makeTree(const char* filename) {
      BST<std::string> Mytree;
    std::ifstream file(filename);
    std::string v;
    std::string v1 = "";
    std::string v2 = "";
    while (!file.eof()) {
        file >> v;
        v1 = v2 = "";
        if (v.find(",") != -1) {
                int l = v.length();
                int f = v.find(",");
                if ((f != l - 1) && ((v[f + 1] >= 'A' && v[f + 1] <= 'Z') ||
                    (v[f + 1] >= 'A' && v[f + 1] <= 'z'))) {
                for (int i = 0; i < f; i++) {
                    v1 += v[i];
                }
                for (int i = f+1; i < l; i++) {
                    v2 += v[i];
                }
            }
        }
        if (v1 != "" && v2 != "") {
            v1 = corr_word(v1);
            v2 = corr_word(v2);
            Mytree.add(v1);
            Mytree.add(v2);
        } else {
            v = corr_word(v);
            Mytree.add(v);
        }
    }
    return Mytree;
}

std::string corr_word(std::string r) {
    if (r[0] < '0' || r[0] > '9') {
        while ((r[0] >= 32 && r[0] <= 64) || (r[0] >= 91 && r[0] <= 96))
        r.erase(0, 1);
        if (r != "") {
            char ch = r[r.length() - 1];
            while ((ch >= 32 && ch <= 64) || (ch >= 91 && ch <= 96)) {
                r.pop_back();
                ch = r[r.length() - 1];
            }
        }
        int it = 0;
        if (r != "") {
            for (int i = 0; i < r.length(); i++) {
                if (r[i] == '\'') {
                    it = i;
                }
            }
            if (it != 0)
                r.erase(it);
        }
        if (r != "") {
            for (int i = 0; i < r.length(); i++) {
                r[i] = tolower(r[i]);
            }
        }
    } else {
        r.clear();
    }
    return r;
}
