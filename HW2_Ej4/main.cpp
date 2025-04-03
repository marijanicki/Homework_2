#include "cuenta.hpp"
#include "cuenta_cc.hpp"
#include "caja_ahorro.hpp"

#include <iostream>
#include <string>

//sugerencia, agregar leyenda a las operaciones que hago
int main(){
    cuenta_cc cuentaC("Juan",152.4);
    caja_ahorro cuentaA("Ana",172);
    //cuentaC.mostrarInfo();
    cuentaA.mostrarInfo();
    //Prueba caja de ahorro
    try{
        cuentaA.retirar(200);
    }
    catch(const runtime_error& e){
            cout<<e.what()<<endl;
    
    }
    //prueba del descuento despues de mostrar 2 veces
    cuentaA.mostrarInfo();
    cuentaA.mostrarInfo();
    cuentaA.depositar(105.6);
    cuentaA.mostrarInfo(); //tener en cuenta que se van a ver como que se sumaron 80 ya que me descuentan 20 de la impresion
    cuentaA.retirar(120.7);
    cuentaA.mostrarInfo();
    cuentaA.retirar(96.9);
    //Prueba cuenta corriente
    cout<<"CUENTA CORRIENTE *********************"<<endl;
    cuentaC.mostrarInfo();
    cuentaC.retirar(200);
    cuentaC.mostrarInfo();
    cuentaC.no_money(cuentaA);

    //preguntar si deberia hacer un try en mostrar info en caso de que el saldo sea insuficiente
}