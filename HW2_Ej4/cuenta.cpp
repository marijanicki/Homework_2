#include "cuenta.hpp"
#include <string>

using namespace std;

cuenta::cuenta(){}

cuenta::cuenta(string titular, string tipo, double balance){
    this->titular =titular;
    this->tipo_cuenta = tipo;
    this->dinero = balance;
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


cuenta::~cuenta(){}