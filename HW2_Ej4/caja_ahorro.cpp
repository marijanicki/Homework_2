#include "cuenta.hpp"
#include "caja_ahorro.hpp"
#include <string>
#include <iostream>

caja_ahorro::caja_ahorro() : cuenta(){
    this->titular ="";
    this->tipo_cuenta = "Caja de Ahorro";
    this->dinero = 0;
}

void caja_ahorro::retirar(double retiro){
    cout<<"\n"<<retiro<<endl;
    if(balance()<retiro){
        throw runtime_error("\nSaldo insuficiente");
    }
}

void caja_ahorro::mostrarInfo(){
    if(cant_muestras>=2){
        depositar(balance()-20);
    }
    cout <<"\n------------------------------\n"<<"Tipo de cuenta:"<< getTipoCuenta() <<"\nTitular de la cuenta:"<< titularCuenta() <<"\nBalance:"<<balance()<<"\n------------------------------";
    cant_muestras = cant_muestras+ 1;
}

