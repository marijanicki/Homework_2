#include "cuenta.hpp"
#include "caja_ahorro.hpp"
#include "cuenta_cc.hpp"
#include <string>
#include <iostream>

cuenta_cc::cuenta_cc(string titular, double total): cuenta(titular, "cuenta corriente", total){}

void cuenta_cc::retirar(double retiro){
    setTotal(balance()-retiro);
}

void cuenta_cc::mostrarInfo(){
    cout <<"\n------------------------------\n"<<"Tipo de cuenta:"<< getTipoCuenta() <<"\nTitular de la cuenta:"<< titularCuenta() <<"\nBalance:"<<balance()<<"\n------------------------------";
}
void cuenta_cc::no_money(caja_ahorro other){
    cout<<other.balance()<<"           "<<balance()<<endl;
    if(balance()<=0 && other.balance()<=0){
        cout<<"Su cuenta no posee más dinero"<<endl;
    }
    return;
}