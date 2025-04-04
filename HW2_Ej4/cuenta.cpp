#include "cuenta.hpp"
#include <string>

using namespace std;

cuenta::cuenta(){
    this->titular ="";
    this->dinero = 0;
}

double cuenta::balance()const{
    return dinero;
}

string cuenta::titularCuenta(){
    return titular;
}

void cuenta::depositar(double deposito){
    this->dinero += deposito;
    return;
}

string cuenta::getTipoCuenta(){
    return tipo_cuenta;
}

void cuenta::setTitular(string titularCuenta){
    this->titular = titular;
}

cuenta::~cuenta(){}