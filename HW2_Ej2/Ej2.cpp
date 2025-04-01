#include "estudiante.h"
#include <iostream>


using namespace std;

int main(){
    estudiante estudiante1("Maxi", 36355, "Análisis 2", 2);
    cout << estudiante1.getmarks()<<endl;
    estudiante1.setmarks("Algoritmos", 2);
    cout << estudiante1.getmarks()<<endl;
    estudiante1.setmarks("Analogica", 1);
    cout << estudiante1.getmarks()<<endl;
    
}