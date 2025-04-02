#include "relog.hpp"
#include <iostream>
#include <string> 

using namespace std;

int main(){

    /*
    int op;
    int horas;
    int min;
    int sec;
    string period;
    bool invalid = true;
    cout<< "Inicio relog: "<<" ";
    relog horario;
    horario.print_time(); 
    while(invalid){
        try{
            cout<< "Elija las variables de tiempo que desea ingresar:\n1.Hora\n2.Minutos\n3.Segundos\n4.Período del día (a.m./p.m.)"<<endl;
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
            /*
            relog horario(horas,15,124,"a.m");
            invalid = false;
            horario.print_time();*/
            /*
            int a;
            cin >> a;
            horario.setmin(a);
            cout << horario.getmin()<<endl;*/
            /*
            horario.without_per();
            horario.print_time();*/
    /*
    }
    catch(const runtime_error& e){
        cout<<e.what();

    }
    }
    

    */
}
