#include "relog.h"
#include <iostream>
#include <string> 

using namespace std;

int main(){
    try{
        relog horario(22,15,124,"a.m");
        horario.print_time();
        int a;
        cin >> a;
        horario.setmin(a);
        cout << horario.getmin()<<endl;
        horario.print_time();
    }
    catch(const runtime_error& e){
        cout<<e.what();
    }

    
}
