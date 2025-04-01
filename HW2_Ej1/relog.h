#include <iostream>
#include <string> 
#include <iomanip>
using namespace std;

class relog{
    private:
        int hour;
        int min;
        int sec;
        string period;

    public:
        relog(int hour = 0, int min = 0, int sec = 0, string per = "a.m."); //constructor default
        
        void sethour(int h);
        void setmin(int m);
        void setsec(int s);
        void setper(string med);
        int gethour();
        int getmin();
        int getsec();
        string getper();

        void print_time();
        void without_per();
};