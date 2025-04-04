#include "estudiante.hpp"
#include "curso.hpp"
#include <iostream>


using namespace std;

int main(){
    estudiante* estudiante1 = new estudiante("Maxi", 36355, "Análisis 2", 2);


    estudiante* stud1 = new estudiante("Luca", 1025, "Análisis 1", 5);
    curso Algebra("Algebra");
    Algebra.inscribir(stud1);
    stud1->getmarks();
    Algebra.print_students();

    estudiante* bombi = new estudiante("Bombi",2542,"Análisis 2",8);
    Algebra.inscribir(bombi);
    Algebra.print_students();
    Algebra.inscribir(estudiante1);
    Algebra.print_students();
    Algebra.desinscribir(estudiante1);
    Algebra.print_students();
    //curso paradigmas("Paradigmas");
    //estudiante* car = new estudiante("car",1902, "Historia", 9);
    //paradigmas.inscribir(car);
    //paradigmas.print_students();
    curso paradigmas = curso("Paradigmas", Algebra);
    paradigmas.print_students();
    estudiante* zoe = new estudiante("zoui",1902, "Historia", 9);
    paradigmas.inscribir(zoe);
    paradigmas.print_students();
    Algebra.print_students();
}