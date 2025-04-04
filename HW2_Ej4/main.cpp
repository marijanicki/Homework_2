#include "cuenta.hpp"
#include "cuenta_cc.hpp"
#include "caja_ahorro.hpp"

#include <iostream>
#include <string>

//sugerencia, agregar leyenda a las operaciones que hago
int main(){
    caja_ahorro cuentaA;
    cuenta_cc cuentaC;
    
    //cuentaC.setcaja_asociada(cuentaA);
    //cuentaC.mostrarInfo();
    cuentaA.mostrarInfo();
    //Prueba caja de ahorro
    cuentaA.setTitular("Juan");
    cuentaA.depositar(1000);
    cuentaA.mostrarInfo();
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

    //preguntar si deberia hacer un try en mostrar info en caso de que el saldo sea insuficiente
}