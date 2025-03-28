#include "relog.h"
#include <iostream>



using namespace std;

int main(){
    relog relog;
    relog.settime(1,0,3,"p.m");
   /*
    relog.min = 9;
    relog.sec=10;*/
    relog.print_time();
}
