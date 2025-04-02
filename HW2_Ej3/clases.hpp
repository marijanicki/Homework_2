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

class real: public numero{
    private:
        float value;
    public:
        real();
        real(float value);
        shared_ptr<numero> suma(shared_ptr<numero> a, shared_ptr<numero> b) override;
        shared_ptr<numero> resta(shared_ptr<numero> a, shared_ptr<numero> b) override;
        shared_ptr<numero> mult(shared_ptr<numero> a, shared_ptr<numero> b)override;
        string toString(shared_ptr<numero> a)override;
        virtual  ~real(){}; //preg xq es q hay que agregar el destructor
        
};


class complejo: public numero{
    private:
        float real_value;
        float imaginary_value;
    public:
        complejo();
        complejo(float real_value, float imaginary_value);
        shared_ptr<numero> suma(shared_ptr<numero> a, shared_ptr<numero> b) override;
        shared_ptr<numero> resta(shared_ptr<numero> a, shared_ptr<numero> b) override;
        shared_ptr<numero> mult(shared_ptr<numero> a, shared_ptr<numero> b)override;
        string toString(shared_ptr<numero> a)override;
        virtual  ~complejo(){}; //preg xq es q hay que agregar el destructor
        
};