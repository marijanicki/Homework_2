#pragma once
#include "interfaz.hpp"
#include <string>
#include <memory>

using namespace std;

class entero: public numero{
    public:
        entero();
        entero(int value);
        shared_ptr<numero> suma(shared_ptr<numero> a, shared_ptr<numero> b) override;
        shared_ptr<numero> resta(shared_ptr<numero> a, shared_ptr<numero> b) override;
        shared_ptr<numero> mult(shared_ptr<numero> a, shared_ptr<numero> b)override;
        string toString(shared_ptr<numero> a)override;
        virtual  ~entero(){};
    private:
        int value;
};