#include <iostream>
#include "include/SVM.h"

int main() {
//    SVM::SVM svm;
//    svm.open("tests/bytecode.sbc");
//    std::cout << svm.content() << std::endl;
    auto object = new SVM::Object();
    auto a = new SVM::Object();
    auto n = new SVM::Int(1);
    auto m = new SVM::Int(2);
    auto x = new SVM::Double(2.57);
    auto y = new SVM::Double(5.431);
    auto s = new SVM::String("Smashing");
    object->set("a", a);
    object->set("n", n);
    object->set("y", y);
    object->set("s", s);
    a->set("m", m);
    a->set("x", x);
    std::cout << (*object) << std::endl;
    return 0;
}