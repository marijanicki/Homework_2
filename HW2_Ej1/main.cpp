#include "relog.hpp"
#include <iostream>
#include <string> 

using namespace std;

int main(){
    int op;
    int horas;
    int min;
    int sec;
    string period;
    bool menu = true;
    bool invalid = true;
    cout<< "Inicio relog: "<<" ";
    relog horario;
    horario.print_time(); 

    while(menu){
        cout << "Elija la operación que desea realizar:\n1. Ingresar horario\n2.Leer horario\n3.Salir "<<" ";
        cin >> op;
        switch(op){
            case 1: //ingresar datos
                while(invalid){
                    //uso try en caso de que se ingrese un valor invalido (hour>=24)
                    try{
                        cout<< "Elija las variables de tiempo que desea ingresar:\n1.Hora\n2.Minutos\n3.Segundos\n4.Período del día (a.m./p.m.)\n5. SALIR"<<endl;
                        cin >> op;
                    
                        switch(op){
                            case 1:
                                cout <<"Ingrese las horas:"<< " ";
                                cin >> horas;
                                horario.sethour(horas);
                                cout<< horario.gethour();
                                break;
                            case 2:
                                cout <<"Ingrese los minutos:"<< " ";
                                cin >> min;
                                horario.setmin(min);
                                cout<< horario.getmin();
                                break;
                            case 3:
                                cout <<"Ingrese los segundos:"<< " ";
                                cin >> sec;
                                horario.setsec(sec);
                                cout<< horario.getsec();
                                break;
                            case 4: 
                                cout <<"Ingrese el período del día:"<< " ";
                                cin >> period;
                                horario.setper(period);
                                cout<< horario.getper();
                                break;
                        }
        
                }
                catch(const runtime_error& e){
                    cout<<e.what();
            
                }
                }



            }
        }

}