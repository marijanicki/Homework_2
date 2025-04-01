#include "relog.h"
#include <iostream>
#include <string> 
#include <iomanip>
using namespace std;

relog::relog(int hour, int min, int sec, string period){
    //Acomodar los parametros por si alguno sobrepasa los 60 o es incorrecto
    if(sec>=60){
        min = min + (sec/60);
        sec = sec %60;
    }
    if(min>=60){
        hour = hour + (min/60);
        min = min%60;
    }
    if(hour>=24){
        throw runtime_error("Ingreso de horario inválido, excedido en horas\n");
    }

    if(hour == 12){
        period = "p.m.";
    }
    else if(hour>12){
        hour = (hour % 12);
        period = "p.m.";
    }

    this->hour = hour;
    this->min=min;
    this->sec = sec;
    this->period = period;
};

//SETTERS
void relog::sethour(int h){
    hour = h;
}
void relog::setmin(int m){
    min = m;
}
void relog::setsec(int s){
    sec = s;
}
void relog::setper(string per){
    period = per;
}

//GETTERS
int relog::gethour(){
    return hour;
}
int relog::getmin(){
    return min;
}
int relog::getsec(){
    return sec;
}
string relog::getper(){
    return period;
}

void relog::print_time(){
    if(hour == 0 && min == 0 && sec == 0 && period == "a.m"){
        cout << hour <<"h,"<< min <<"m,"<< sec <<"s "<<period<< endl;
    }
    else{
    cout <<setfill('0')<<setw(2) << hour <<"h,"<<setfill('0')<<setw(2) << min <<"m,"<< setfill('0')<<setw(2) << sec <<"s "<<period<< endl;
    }
}

void relog::without_per(){
    if(period == "p.m." && hour != 12){
        hour = hour +12;
        period = "";
    }
}
