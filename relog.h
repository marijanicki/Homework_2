#include <iostream>
#include <string> 
#include <iomanip>
using namespace std;

class relog{
    private:
        int hour;
        int min;
        int sec;
        string meridian;
        
        /*
        relog(int hour, int min, int sec){//constructor
            print_time();
        } */
        
        //metodo
    public:
        relog();
        /*
        relog(int h, int m, int s, string med){
            hour = h;
            min = m;
            sec = s;
            meridian = med;
        }*/
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
};