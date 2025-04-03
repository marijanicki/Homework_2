#include "cuenta.hpp"
#include <string>

using namespace std;

cuenta::cuenta(string titular, string tipo, double balance){
    this->titular =titular;
    this->tipo_cuenta = tipo;
    this->total = balance;
}
double cuenta::balance()const{
    return total;
}

string cuenta::titularCuenta(){
    return titular;
}

void cuenta::depositar(double deposito){
    this->total += deposito;
    return;
}
void cuenta::setTotal(float new_total){
    this->total = new_total;
}
string cuenta::getTipoCuenta(){
    return tipo_cuenta;
}

cuenta::~cuenta(){}