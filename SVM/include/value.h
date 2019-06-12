#ifndef SVM_VALUE_H
#define SVM_VALUE_H
#include <iostream>
#include <string>
#include <map>
using std::string;
using std::map;

namespace SVM {
    class Object;
    class Value {
    public:
        Value() : linked(0) { }
        virtual ~Value() { }
        bool has(Value* v, Value* root);
    protected:
        unsigned int linked;
        Object* parent;
        friend class Object;
        virtual void print(std::ostream&, string tab = "") = 0;
        friend std::ostream& operator<<(std::ostream& o, Value& v) {
            v.print(o);
            return o;
        }
    };
    class Object : public Value {
    public:
        Object() : Value() { parent = nullptr; }
        void insert(string key, Value* value);
        Value* get(const string& key);
        void set(const string& key, Value* value);
        void del(const string& key);
        ~Object();
    private:
        std::map<string, Value*> proto;
        void print(std::ostream& o, string tab = "");
    };
    class Int : public Value {
    public:
        Int() : Value() { parent = nullptr;  }
        Int(int t) : Value(), v(t) { parent = nullptr; }
        void value(int t) { v = t; }
        int& value() { return v; }
        ~Int() { }
    private:
        void print(std::ostream& o, string tab = "") { o << v; }
        int v;
    };
    class Float : public Value {
    public:
        Float() : Value() { parent = nullptr; }
        Float(float t) : Value(), v(t) { parent = nullptr; }
        void value(float t) { v = t; }
        float& value() { return v; }
        ~Float() { }
    private:
        void print(std::ostream& o, string tab = "") { o << v; }
        float v;
    };
    class Double : public Value {
    public:
        Double() : Value() { parent = nullptr; }
        Double(double t) : Value(), v(t) { parent = nullptr; }
        void value(double t) { v = t; }
        double& value() { return v; }
        ~Double() { }
    private:
        void print(std::ostream& o, string tab = "") { o << v; }
        double v;
    };
    class String : public Value {
    public:
        String() : Value() { parent = nullptr; }
        String(string t) : Value(), v(t) { parent = nullptr; }
        void value(string t) { v = t; }
        string& value() { return v; }
        ~String() { }
    private:
        void print(std::ostream& o, string tab = "") { o << "\"" << v << "\""; }
        string v;
    };
}


#endif //SVM_VALUE_H
