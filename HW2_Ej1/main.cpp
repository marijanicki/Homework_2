#include "relog.hpp"
#include <iostream>
#include <string> 
#include <typeinfo>

using namespace std;
enum class OPCIONES: uint8_t{a,b,c,d,e,g,h,invalid};
enum class PERIODO : uint8_t {am, pm, invalid};

OPCIONES make_enum_element_op(string op){
    //Verificamos que la opción este dentro de nuestro enum, en caso de que no, salta error
    try{
        if(op == "a" || op == "A"){
            return OPCIONES::a;
        }
        else if(op == "b" || op == "B"){
            return OPCIONES::b;
        }
        else if(op == "c" || op == "C"){
            return OPCIONES::c;
        }
        else if(op == "d" || op == "D"){
            return OPCIONES::d;
        }
        else if(op == "e" || op == "E"){
            return OPCIONES::e;
        }
        else if(op == "g" || op == "G"){
            return OPCIONES::g;
        }
        else if(op == "h" || op == "H"){
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

PERIODO make_enum_period(string period){
    try{
        if(period == "am" ||period == "a.m." || period == "a.m"){
            return PERIODO::am;
        }
        else if(period == "pm" ||period == "p.m." || period == "p.m"){
            return PERIODO::pm;
        }
        else{
            throw runtime_error("Periodo invalido! Opción no existente");
        }
    }
    catch(const runtime_error& e){
        cout << "Runtime error:" << e.what() <<endl;
        return PERIODO::invalid;
    }
    
}
string enum_to_str(PERIODO period){
    switch (period)
    {
    case PERIODO::am:
        return "a.m";
    case PERIODO::pm:
        return "p.m.";
    default:
        return "Invalid";
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
        num_op = make_enum_element_op(op);
        //esto es para chequear de que ingreso una opción válida
        if(num_op != OPCIONES::invalid){
            valid = false;
        }
    }
    //Los defino afuera con un valor cualquiera porque sino el switch me dice error por jump to case label ya que estoy definiendo variables dentro del switch
    relog horario1;
    relog horario2(1);
    relog horario3(1,1);
    relog horario4(1,1,1);
    relog horario5();
    switch(num_op){
        case OPCIONES::a: 
            horario1.print_time();
            break;

        case OPCIONES::b: 
            cin>>horas;
            horario2.sethour(horas);
            horario2.print_time();
            break;

        case OPCIONES::c: 
            cin >>horas >>min;
            horario3.sethour(horas);
            horario3.setmin(min);
            horario3.print_time();
            break;

        case OPCIONES::d:
            cin>>horas>>min>>sec; 
            horario4.sethour(horas);
            horario4.setmin(min);
            horario4.setsec(sec);
            horario4.print_time();
            break;

        case OPCIONES::e:
            cin >> horas>>min>>sec>>period; 
            horario4.sethour(horas);
            horario4.setmin(min);
            horario4.setsec(sec);
            horario5.print_time();
            break;

        case OPCIONES::g: 
            relog horario6; 
            int op_sets;
            valid = true;
            while(valid){ 
                try{
                    cout <<"Elija los parametro que desea ingresar o imprimir del relog"<<endl;
                    cout <<"1.Ingresar hora\n2.Ingresar minutos\n3.Ingresar segundos\n4.Ingresar periodo.\n5.Leer hora\n6.Leer minutos\n7.Leer segundos\n8.Leer periodo"<<endl;
                    cin>>op_sets;
                    if( typeid(op_sets) != typeid(int)){
                        throw runtime_error("Opción inválida");
                    }
                    switch(op_sets){
                        case 1:
                            valid= true;
                            while(valid){
                                try{
                                    cout<<"Ingrese la cantidad de horas:"<<" ";
                                    cin>>horas;
                                    if(typeid(horas) != typeid(int)){
                                        throw runtime_error("Ingreso un tipo de dato inválido. Intente nuevamente.");
                                    }
                                    horario6.sethour(horas);
                                    valid = false;
                                    break;
                                }
                                catch(const runtime_error& e){
                                    cout << "Runtime error: " <<e.what() <<endl;
                                }
                            }
                        case 2:
                            valid= true;
                            while(valid){
                                try{
                                    cout<<"Ingrese la cantidad de minutos:"<<" ";
                                    cin>>min;
                                    if(typeid(min) != typeid(int)){
                                        throw runtime_error("Ingreso un tipo de dato inválido. Intente nuevamente.");
                                    }
                                    horario6.setmin(min);
                                    valid = false;
                                    break;
                                }
                                catch(const runtime_error& e){
                                    cout << "Runtime error: " <<e.what() <<endl;
                                }
                            }
                                
                        case 3:
                            valid= true;
                            while(valid){
                                try{
                                    cout<<"Ingrese la cantidad de segundos:"<<" ";
                                    cin>>horas;
                                    if(typeid(horas) != typeid(int)){
                                        throw runtime_error("Ingreso un tipo de dato inválido. Intente nuevamente.");
                                    }
                                    horario6.setsec(sec);
                                    valid = false;
                                    break;
                                }
                                catch(const runtime_error& e){
                                    cout << "Runtime error: " <<e.what() <<endl;
                                }
                            }
                        case 4:
                            valid= true;
                            while(valid)
                                try{
                                    cout<<"Ingrese el periodo del día:"<<" ";
                                    cin>>period;
                                    if(typeid(period) != typeid(string)){
                                        throw runtime_error("Ingreso un tipo de dato inválido. Intente nuevamente.");
                                    }
                                    PERIODO num_per = make_enum_period(period);
                                    if(num_per != PERIODO::invalid){
                                        cout<<"Periodo inválido. Intentelo nuevamente"<<endl;
                                        continue;
                                    }
                                    
                                    horario6.setper(enum_to_str(num_per));
                                    valid = false;
                                    break;
                                }
                                catch(const runtime_error& e){
                                    cout << "Runtime error: " <<e.what() <<endl;
                                }
                        case 5:
                                horario6.gethour();
                                break;
                        case 6:
                                horario6.getmin();
                                break;
                        case 7:
                                horario6.getsec();
                                break;
                        case 8:
                                horario6.getper();
                                break;
                    }   
                    valid = false;     
                    break;
                    }
                catch(const runtime_error& e){
                    cout << "Runtime error:" << e.what() <<endl;
                    
                }  
            }
            

        case OPCIONES::h: 
            relog horario7;
            horario7.without_per();
            horario7.print_time();
            break;
    }
}