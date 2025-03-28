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
        
        void sethour(int h);
        void setmin(int m);
        void setsec(int s);
        void setmed(string med);
        int gethour();
        int getmin();
        int getsec();
        string getmed();

        void print_time();
};