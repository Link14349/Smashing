#ifndef SVM_SVM_H
#define SVM_SVM_H
#include <string>
#include "value.h"
#include "register.h"
using std::string;

namespace SVM {
    class SVM {
    public:
        SVM() { }
        SVM(string bc) : bytecode(bc) { }
        void open(string filename);
        string& content() { return bytecode; }
        void run();
    private:
        string bytecode;
    };
}

#endif //SVM_SVM_H
