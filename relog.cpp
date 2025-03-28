#include "relog.h"
#include <iostream>
#include <string> 
#include <iomanip>
using namespace std;

relog::relog(int hour, int min, int sec, string meridian){
    //Acomodar los parametros por si alguno sobrepasa los 60 o es incorrecto
    if(sec>=60){
        min = min + (sec/60);
        sec = sec %60;
    }
    if(min>=60){
        hour = hour + (min/60);
        min = min%60;
    }

    try{
        if(hour>=24){
            throw runtime_error("Ingreso de horario inválido, excedido en horas");
        }
    }catch(const runtime_error& e){
        cout<<e.what();
        // preguntar como cortar el loop para q no se guarde lo q esta mal
    }

    this->hour = hour;
    this->min=min;
    this->sec = sec;
    this->meridian = "a.m.";
    //cout<<hour <<min <<sec <<endl;
};
/*
void relog::settime(int h, int m, int s, string med){
    
    hour = h;
    min = m;
    sec = s;
    meridian = med;
}*/
int relog::gethour(){
    return hour;
}
void relog::print_time(){
    cout <<setfill('0')<<setw(2) << hour <<"h,"<<setfill('0')<<setw(2) << min <<"m,"<< setfill('0')<<setw(2) << sec <<"s "<<meridian<< endl;
}




/*


class relog{
    private:
        int hour;
        int min;
        int sec;
        string meridian;
        
    public:
        relog::relog(){
            this->hour = 0;
            this->min=0;
            this->sec = 0;
            this->meridian = "a.m.";
        };
     
        void settime(int h, int m, int s, string med){
            hour = h;
            min = m;
            sec = s;
            meridian = med;
        }
        int gethour(){
            return hour;
        }
        void print_time(){
            cout <<setfill('0')<<setw(2) << hour <<"h,"<<setfill('0')<<setw(2) << min <<"m,"<< setfill('0')<<setw(2) << sec <<"s "<<meridian<< endl;
        }
};*/