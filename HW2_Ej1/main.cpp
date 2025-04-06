#include "reloj.hpp"
#include <iostream>
#include <string> 
#include <typeinfo>
#include <limits>

using namespace std;
enum class OPCIONES: uint8_t{a,b,c,d,e,f,g,h,invalid};
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
        else if(op == "f" || op == "F"){
            return OPCIONES::f;
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

int valid_input(string leyend){
    int value;
    cout<<leyend<<" ";
    cin>>value;                           
    if(cin.fail()){
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        throw runtime_error("Ingresó un tipo de dato inválido.\n");
    }
    else{
        return value;
    }
}

bool intento(string leyend){
    char salir;
    while(true){
        cout << leyend <<endl;
        cin >>salir;
        if(salir == 'N' || salir == 'n'){
            cout << "Cerrando...";
            return false;
        }
        else if(salir == 'Y' || salir == 'y'){
            return true;
            
        }
        else{
            cout <<" Ingreso una opción incorrecta. Vuelva a intentarlo"<<endl;
            
        }
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
    
    reloj horario1;
    reloj horario2(1);
    reloj horario3(1,1);
    reloj horario4(1,1,1);
    reloj horario5(1,1,1,"p.m.");
//Los defino afuera con un valor cualquiera porque sino el switch me dice error por jump to case label ya que estoy definiendo variables dentro del switch
    while(valid){
        cout<< "Eliga el inciso que desea ejecutar:\nA. Inicializar un relog sin parámetros.\nB.Inicializar un relog sólo pasandole la hora.\nC.Inicializar un relog sólo pasandole la hora y los minutos.\nD.Inicializar un relog sólo pasandole horas, minutos y segundos.\nE.Inicializar un relog pasandole horas, minutos, segundos y periodo del día.\nF.Imprimir horario. \nG.Hacer un relog donde pueda definir y leer parámetros en ejecución\nH.Leer el relog en formato 24hs"<<endl;
        cin>>op;
        num_op = make_enum_element_op(op);
        //esto es para chequear de que ingreso una opción válida
        if(num_op != OPCIONES::invalid){
            valid = false;
        }
    
    //se crea el objeto de los horarios afuera debido a que dentro de un switch no se pueden crear variables
        switch(num_op){
            case OPCIONES::a: 
                horario1.print_time();
                break;

            case OPCIONES::b: 
                horario2.print_time();
                break;

            case OPCIONES::c: 
                horario3.print_time();
                break;

            case OPCIONES::d:
                horario4.print_time();
                break;

            case OPCIONES::e:
                horario5.print_time();
                break;
            case OPCIONES::f:
                horario1.print_time();
                break;
            case OPCIONES::g: 
                int op_sets;
                valid = true;
                while(valid){ 
                    try{
                        cout <<"Elija los parametro que desea ingresar o imprimir del reloj"<<endl;
                        cout <<"1.Ingresar hora\n2.Ingresar minutos\n3.Ingresar segundos\n4.Ingresar periodo.\n5.Leer hora\n6.Leer minutos\n7.Leer segundos\n8.Leer periodo\n9.SALIR"<<endl;
                        cin>>op_sets;
                        switch(op_sets){
                            case 1:
                                valid= true;
                                while(valid){
                                    try{
                                        horas = valid_input("Ingrese la cantidad de horas:");
                                        try{
                                            horario1.sethour(horas);
                                            valid = false;
                                        }
                                        catch(const runtime_error& e){
                                            cout << "Runtime error: " <<e.what() <<endl;
                                        }
                                        
                                    }
                                    catch(const runtime_error& e){
                                        cout << "Runtime error: " <<e.what() <<endl;
                                        try{
                                            valid = intento("Desea volver a intentarlo? Y/N");
                                        }
                                        catch(const runtime_error& f){
                                            cout << f.what()<<endl;
                                        }
                                    }
                                    cin.clear();
                                }
                                break;
                            case 2:
                                valid= true;
                                cout <<"c"<<endl;
                                while(valid){
                                    cout <<"b"<<endl;
                                    try{
                                        cout <<"a"<<endl;
                                        min = valid_input("Ingrese la cantidad de minutos:");
                                        horario1.setmin(min);
                                        cout <<"a"<<endl;
                                        valid = false;
                                    }
                                    catch(const runtime_error& e){
                                        cout << "Runtime error: " <<e.what() <<endl;
                                        try{
                                            valid = intento("Desea volver a intentarlo? Y/N");
                                           }
                                        catch(const runtime_error& f){
                                            cout << f.what()<<endl;
                                        }
                                    }
                                    cin.clear();
                                    }
                                break;    
                            case 3:
                                valid= true;
                                while(valid){
                                    try{
                                        sec = valid_input("Ingrese la cantidad de segundos:");
                                        horario1.setsec(sec);
                                        valid = false;
                                    }
                                    catch(const runtime_error& e){
                                        cout << "Runtime error: " <<e.what() <<endl;
                                        try{
                                            valid = intento("Desea volver a intentarlo? Y/N");
                                        }
                                        catch(const runtime_error& f){
                                            cout << f.what()<<endl;
                                        }
                                    }
                                    cin.clear();
                                    }
                                break;
                            case 4:
                                valid= true;
                                while(valid){
                                    try{
                                        cout<<"Ingrese el periodo del día:"<<" ";
                                        cin>>period;
                                        PERIODO num_per = make_enum_period(period);
                                        if(num_per == PERIODO::invalid){
                                            cout<<"Periodo inválido. Intentelo nuevamente"<<endl;
                                            continue;
                                        }
                                        horario1.setper(enum_to_str(num_per));
                                        valid = false;
                                    }
                                    catch(const runtime_error& e){
                                        cout << "Runtime error: " <<e.what() <<endl;
                                        try{
                                            valid = intento("Desea volver a intentarlo? Y/N");
                                        }
                                        catch(const runtime_error& f){
                                            cout << f.what()<<endl;
                                        }
                                    }
                                    cin.clear();
                                }
                                break;
                            case 5:
                                cout <<horario1.gethour()<<endl;
                                break;
                            case 6:
                                cout<<horario1.getmin()<<endl;
                                break;
                            case 7:
                                cout<<horario1.getsec()<<endl;
                                break;
                            case 8:
                                cout<<horario1.getper()<<endl;
                                break;
                            case 9:
                                break;
                        }   
                        valid = false;    
                    }
                    catch(const runtime_error& e){
                        cout << "Runtime error:" << e.what() <<endl;   
                    }  
                }
                break;
            case OPCIONES::h: 
                horario1.without_per();
                horario1.print_time();
                break;

            case OPCIONES::invalid:
                cout <<"Ingreso una opción inválida. Intentelo de nuevo"<<endl;
                break;
            default:
                cout <<"Ingreso una opción inválida. Intentelo de nuevo"<<endl;
        }
        try{
            valid = intento("¿Desea realizar otra operación? Y/N");
        }
        catch(const runtime_error& f){
            cout << f.what()<<endl;
        }
    }
}