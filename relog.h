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

    public:
        relog(int hour = 0, int min = 0, int sec = 0, string meridian = "a.m."); //constructor default
        

        void settime(int h, int m, int s, string med);
        int gethour();
        void print_time();
};