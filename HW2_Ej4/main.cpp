#include "cuenta.hpp"
#include "cuenta_cc.hpp"
#include "caja_ahorro.hpp"

#include <iostream>
#include <string>

//sugerencia, agregar leyenda a las operaciones que hago
int main(){
    caja_ahorro cuentaA("Juan");
    cuenta_cc cuentaC("Alberto");

    //Prueba caja de ahorro
    cuentaA.mostrarInfo();
    cuentaA.depositar(1000);
    cuentaA.mostrarInfo();
    try{
        cuentaA.retirar(200);
    }
    catch(const runtime_error& e){
            cout<<e.what()<<endl;
    
    }
    cout<<"\n***************************\n*********** PRUEBA CUENTA CORRIENTE *************"<<endl;
    //prueba del descuento despues de mostrar 2 veces
    cuentaA.mostrarInfo();
    cuentaA.mostrarInfo();


    //Prueba cuenta corriente
    cout<<"CUENTA CORRIENTE *********************"<<endl;
    cuentaC.mostrarInfo();
    cuentaC.retirar(200);
    cuentaC.mostrarInfo();

    //preguntar si deberia hacer un try en mostrar info en caso de que el saldo sea insuficiente
}