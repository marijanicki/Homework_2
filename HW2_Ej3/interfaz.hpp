#pragma once
#include <string>
#include <memory>

using namespace std;

class numero{
    public:
    //si devuelvo el puntero estoy devolviendo isntancias de clases derivadas
        virtual shared_ptr<numero> suma(shared_ptr<numero> a, shared_ptr<numero> b) = 0;
        virtual shared_ptr<numero> resta(shared_ptr<numero> a, shared_ptr<numero> b) =0;
        virtual shared_ptr<numero> mult(shared_ptr<numero> a, shared_ptr<numero> b) = 0;
        virtual string toString(shared_ptr<numero> a) = 0;
        virtual  ~numero(){};
};
