#include "cuenta.hpp"
#include "caja_ahorro.hpp"
#include "cuenta_cc.hpp"
#include <string>
#include <iostream>


cuenta_cc::cuenta_cc(string titular): cuenta(titular, "Cuenta Corriente", 0.0){}

void cuenta_cc::setcaja_asociada(caja_ahorro caja_asociada){
    this->caja_asociada = caja_asociada;
}

void cuenta_cc::retirar(double retiro){
    if(balance()<retiro){
        try{
            caja_asociada.retirar(retiro);
        }
        catch(const runtime_error& e){
            cout<<e.what()<<endl;
        }
    }
}

void cuenta_cc::mostrarInfo(){
    cout <<"\n------------------------------\n"<<"Datos cuenta:\n\nTipo de cuenta:"<< getTipoCuenta() <<"\nTitular de la cuenta:"<< titularCuenta() <<"\nBalance:"<<balance()<<"\n\n------------------------------";
}
