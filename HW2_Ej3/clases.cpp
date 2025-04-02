#include "interfaz.hpp"
#include "clases.hpp"
#include <string>

using namespace std;
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
    shared_ptr<entero> res = make_shared<entero>(dynamic_cast<entero*>(a.get())->value + dynamic_cast<entero*>(b.get())->value);
    return res;
}
shared_ptr<numero> entero::mult(shared_ptr<numero> a, shared_ptr<numero> b){
    return nullptr;
}

string entero::toString(shared_ptr<numero> a){
    string res = to_string(dynamic_cast<entero*>(a.get())->value);
    return res;
}