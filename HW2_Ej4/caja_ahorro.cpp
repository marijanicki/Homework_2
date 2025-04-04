#include "cuenta.hpp"
#include "caja_ahorro.hpp"
#include <string>
#include <iostream>

caja_ahorro::caja_ahorro(){}

caja_ahorro::caja_ahorro(string titular) : cuenta(titular, "Caja de Ahorro", 0){}

void caja_ahorro::retirar(double retiro){
    cout<<"\nRetiro:"<<retiro<<endl;
    if(balance()<retiro){
        throw runtime_error("\nSaldo insuficiente");
    }
    else{
        depositar(-retiro);
    }
}

void caja_ahorro::mostrarInfo(){
    if(cant_muestras>=2){
        depositar(-20);
    }
    cout <<"\n------------------------------\n"<<"Tipo de cuenta:"<< getTipoCuenta() <<"\nTitular de la cuenta:"<< titularCuenta() <<"\nBalance:"<<balance()<<"\n------------------------------";
    cant_muestras = cant_muestras+ 1;
}

