#include "cuenta.hpp"
#include "cuenta_cc.hpp"
#include "caja_ahorro.hpp"

#include <iostream>
#include <string>

/*
En mi clase base elegi para los atributos utilizar protected esto es debido
a que de esta manera mis clases derivadas podrían acceder a ellos pero manteniendo
el encapsulamiento. Si yo los ponía en private las mismas no iban a poder utilizarlo
ya que en estos solo se puede acceder desde la misma clase o con getters. Por este 
motivo, es que puse los atributos de las clases derivadas como private. El usuario 
no debe saber que es lo que pasa ahí y en caso de requerir algún dato se le realizó
su correspondiente getter.

De la forma que lo estructure hice que sólo desde la clase derivada en sí se puedan
acceder a los atributos que no necesito de la clase base. Desde mi main jamás podría 
acceder a un atributo. Además, como la clase base es una clase abstracta estoy 
su constructor para crear las clases derivadas. Ya que, si fuera una interfaz estas 
no tienen constructor, pero en el caso de una clase abstracta que si; debo acceder al 
mismo para crear mi clase (motivo fundamental por el que necesito tener acceso a la clase
base desde la derivada). Desde el main no puedo definir una cuenta nombre cuenta();
si o si primero debo llamar a la clase derivada y esta llama a la base.
*/

int main(){
    caja_ahorro cuentaA("Juan");
    cuenta_cc cuentaC("Alberto");

    cout<<"\n\n*************************************************\n************ PRUEBA CAJA DE AHORRO **************"<<endl;
    //Prueba caja de ahorro
    cuentaA.mostrarInfo();
    cuentaA.depositar(1000);
    cuentaA.mostrarInfo();
    try{
        cuentaA.retirar(2000);
    }
    catch(const runtime_error& e){
            cout<<e.what()<<endl;
    
    }
    
    //prueba del descuento despues de mostrar 2 veces
    cuentaA.mostrarInfo();
    cuentaA.mostrarInfo();

    cout<<"\n\n*************************************************\n*********** PRUEBA CUENTA CORRIENTE *************"<<endl;

    cuentaC.mostrarInfo();
    cuentaC.depositar(100);
    cuentaC.mostrarInfo();
    cuentaC.retirar(1000);
    cuentaC.mostrarInfo();

    //preguntar si deberia hacer un try en mostrar info en caso de que el saldo sea insuficiente
}