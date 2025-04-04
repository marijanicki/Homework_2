#include "relog.hpp"
#include <iostream>
#include <string> 
#include <typeinfo>

using namespace std;
enum class OPCIONES: uint8_t{a,b,c,d,e,g,h,invalid};


OPCIONES make_enum_element(string op){
    //Verificamos que la opción este dentro de nuestro enum, en caso de que no, salta error
    try{
        if(op == "a" || op == "A"){
            return OPCIONES::a;
        }
        if(op == "b" || op == "B"){
            return OPCIONES::b;
        }
        if(op == "c" || op == "C"){
            return OPCIONES::c;
        }
        if(op == "d" || op == "D"){
            return OPCIONES::d;
        }
        if(op == "e" || op == "E"){
            return OPCIONES::e;
        }
        if(op == "g" || op == "G"){
            return OPCIONES::g;
        }
        if(op == "h" || op == "H"){
            return OPCIONES::h;
        }
        else{
            throw runtime_error("Caso invalido! Opción no existente");
        }
    }
    catch(const runtime_error& e){
        cout << "Runtime error:" << e.what() <<endl;
        return OPCIONES::invalid;
    }
    
}

int main(){
    int horas;
    int min;
    int sec;
    string period;
    string op;
    OPCIONES num_op;
    bool valid = true;
    while(valid){
        cout<< "Eliga el inciso que desea ejecutar:\n A. Inicializar un relog sin parámetros.\nB.Inicializar un relog sólo pasandole la hora.\nC.Inicializar un relog sólo pasandole la hora y los minutos.\nD.Inicializar un relog sólo pasandole horas, minutos y segundos.\nE.Inicializar un relog pasandole horas, minutos, segundos y periodo del día.\nG.Hacer un relog donde pueda definir y leer parámetros en ejecución\nH.Leer el relog en formato 24hs";
        cin>>op;
        num_op = make_enum_element(op);
        //esto es para chequear de que ingreso una opción válida
        if(num_op != OPCIONES::invalid){
            valid = false;
        }
    }
    switch(num_op){
        case OPCIONES::a: 
            relog horario1;
            horario1.print_time();
            break;

        case OPCIONES::b: 
            cin>>horas;
            relog horario2(horas);
            horario2.print_time();

        case OPCIONES::c: 
            cin >>horas >>min;
            relog horario3(horas, min);
            horario3.print_time();

        case OPCIONES::d:
            cin>>horas>>min>>sec; 
            relog horario4(horas, min, sec);
            horario4.print_time();

        case OPCIONES::e:
            cin >> horas>>min>>sec>>period; 
            relog horario5;
            horario5.print_time();

        case OPCIONES::g: 
        relog horario6; 
        int op_sets;
        valid = true;
        while(valid){
            try{
                cout <<"Elija los parametro que desea setear o imprimir del relog"<<endl;
                cout <<"1.Ingresar hora\n2.Ingresar minutos\n3.Ingresar segundos\n4.Ingresar periodo.\n5.Leer hora\n6.Leer minutos\n7.Leer segundos\n8.Leer periodo"<<endl;
                cin>>op_sets;
                if( typeid(op_sets) != typeid(int)){
                    throw runtime_error("Opción inválida");
                }
                valid = false;
            }
            catch(const runtime_error& e){
                cout << "Runtime error:" << e.what() <<endl;
                
            }
            
        }
        

        horario1.print_time();
        case OPCIONES::h: 
        relog horario1;
        horario1.print_time();
        
    }
}