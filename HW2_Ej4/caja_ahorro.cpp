#include "cuenta.hpp"
#include "caja_ahorro.hpp"
#include <string>
#include <iostream>

caja_ahorro::caja_ahorro(string titular, double total) : cuenta(titular, "Caja de ahorro", total){}

void caja_ahorro::retirar(double retiro){
    cout<<"\n"<<retiro<<endl;
    if(balance()<retiro){
        throw runtime_error("\nSaldo insuficiente");
    }
    else if(retiro == balance()){
        setTotal(0.0);
        cout<<"Balance"<<balance()<<endl;
    }
    else{
        setTotal((balance()-retiro));
        cout<<"queda:"<<(balance())<<endl;
    }
}

void caja_ahorro::mostrarInfo(){
    if(cant_muestras>=2){
        setTotal(balance()-20);
    }
    cout <<"\n------------------------------\n"<<"Tipo de cuenta:"<< getTipoCuenta() <<"\nTitular de la cuenta:"<< titularCuenta() <<"\nBalance:"<<balance()<<"\n------------------------------";
    cant_muestras = cant_muestras+ 1;
}

