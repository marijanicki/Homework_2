#include "interfaz.hpp"
#include "clases.hpp"
#include <string>

using namespace std;

//ENTERO 

entero::entero(){}

entero::entero(int value){
    this->value = value;
}

shared_ptr<numero> entero::suma(shared_ptr<numero> a, shared_ptr<numero> b){
    //get me devuelve un raw pointer
    shared_ptr<entero> res = make_shared<entero>(dynamic_cast<entero*>(a.get())->value + dynamic_cast<entero*>(b.get())->value);
    return res;
}

shared_ptr<numero> entero::resta(shared_ptr<numero> a, shared_ptr<numero> b){
    shared_ptr<entero> res = make_shared<entero>(dynamic_cast<entero*>(a.get())->value - dynamic_cast<entero*>(b.get())->value);
    return res;
}
shared_ptr<numero> entero::mult(shared_ptr<numero> a, shared_ptr<numero> b){
    shared_ptr<entero> res = make_shared<entero>(dynamic_cast<entero*>(a.get())->value * dynamic_cast<entero*>(b.get())->value);
    return res;
}

string entero::toString(shared_ptr<numero> a){
    string res = to_string(dynamic_cast<entero*>(a.get())->value);
    return res;
}
//-----------------------------------------------------------------------
//REAL
real::real(){}
real::real(float value){
    this->value = value;
}


shared_ptr<numero> real::suma(shared_ptr<numero> a, shared_ptr<numero> b){
    shared_ptr<real> res = make_shared<real>(dynamic_cast<real*>(a.get())->value + dynamic_cast<real*>(b.get())->value);
    return res;
}

shared_ptr<numero> real::resta(shared_ptr<numero> a, shared_ptr<numero> b){
    shared_ptr<real> res = make_shared<real>(dynamic_cast<real*>(a.get())->value - dynamic_cast<real*>(b.get())->value);
    return res;
}

shared_ptr<numero> real::mult(shared_ptr<numero> a, shared_ptr<numero> b){
    shared_ptr<real> res = make_shared<real>(dynamic_cast<real*>(a.get())->value * dynamic_cast<real*>(b.get())->value);
    return res;
}

string real::toString(shared_ptr<numero> a){
    string res = to_string(dynamic_cast<real*>(a.get())->value);
    return res;
}

//---------------------------------------------------------------------------------
//COMPLEJOS

complejo::complejo(){}
complejo::complejo(float real_value, float imaginary_value){
    this->real_value = real_value;
    this->imaginary_value = imaginary_value;
}


shared_ptr<numero> complejo::suma(shared_ptr<numero> a, shared_ptr<numero> b){
    shared_ptr<complejo> res = make_shared<complejo>(dynamic_cast<complejo*>(a.get())->real_value + dynamic_cast<complejo*>(b.get())->real_value,dynamic_cast<complejo*>(a.get())->imaginary_value + dynamic_cast<complejo*>(b.get())->imaginary_value);
    return res;
}

shared_ptr<numero> complejo::resta(shared_ptr<numero> a, shared_ptr<numero> b){
    shared_ptr<complejo> res = make_shared<complejo>(dynamic_cast<complejo*>(a.get())->real_value - dynamic_cast<complejo*>(b.get())->real_value, dynamic_cast<complejo*>(a.get())->imaginary_value - dynamic_cast<complejo*>(b.get())->imaginary_value);
    return res;
}

shared_ptr<numero> complejo::mult(shared_ptr<numero> a, shared_ptr<numero> b){
    float parte_real = (dynamic_cast<complejo*>(a.get())->real_value * dynamic_cast<complejo*>(b.get())->real_value) - (dynamic_cast<complejo*>(a.get())->imaginary_value * dynamic_cast<complejo*>(b.get())->imaginary_value);
    float parte_imaginaria = (dynamic_cast<complejo*>(a.get())->real_value * dynamic_cast<complejo*>(b.get())->imaginary_value) + (dynamic_cast<complejo*>(a.get())->imaginary_value * dynamic_cast<complejo*>(b.get())->real_value);
    shared_ptr<complejo> res = make_shared<complejo>(parte_real, parte_imaginaria);
    return res;
}

string complejo::toString(shared_ptr<numero> a){
    string res;
    if(dynamic_cast<complejo*>(a.get())->imaginary_value > 0){
        res = to_string(dynamic_cast<complejo*>(a.get())->real_value) + "+" +  to_string(dynamic_cast<complejo*>(a.get())->imaginary_value) + "i";
    }
    else{
        res = to_string(dynamic_cast<complejo*>(a.get())->real_value) +  to_string(dynamic_cast<complejo*>(a.get())->imaginary_value) + "i"; 
    }
    return res;
}