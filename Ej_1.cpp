#include "relog.h"
#include <iostream>
#include <string> 

using namespace std;

int main(){
    bool invalid = true;
    while(invalid){
        try{
            int horas;
            cin >> horas;
            relog horario(horas,15,124,"a.m");
            invalid = false;
            horario.print_time();
            /*
            int a;
            cin >> a;
            horario.setmin(a);
            cout << horario.getmin()<<endl;*/

            horario.without_med();
            horario.print_time();
    }
    catch(const runtime_error& e){
        cout<<e.what();

    }
    }
    

    
}
