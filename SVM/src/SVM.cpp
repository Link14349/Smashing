#include <fstream>
#include "../include/SVM.h"
#define ULL unsigned long long

void SVM::SVM::open(string filename) {
    std::ifstream infile(filename);
    assert(infile.is_open());
    bytecode = "";
    string l;
    while (getline(infile, l)) {
        bytecode += l + "\n";
    }
}

void SVM::SVM::run() {
    ULL i(0);
    const ULL len(bytecode.length());
    while (i < len) {
    }
}