#include "estudiante.hpp"
#include "curso.hpp"
#include <iostream>
#include <memory>

using namespace std;

int main(){
    shared_ptr estudiante1 = make_shared<estudiante>("Maxi", 36355, "Análisis 2", 2);


    shared_ptr stud1 = make_shared<estudiante>("Luca", 1025, "Análisis 1", 5);
    curso Algebra("Algebra");
    Algebra.inscribir(stud1);
    stud1->getmarks();
    Algebra.print_students();

    shared_ptr bombi = make_shared<estudiante>("Bombi",2542,"Análisis 2",8);
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
    shared_ptr zoe = make_shared<estudiante>("zoui",1902, "Historia", 9);
    paradigmas.inscribir(zoe);
    paradigmas.print_students();
    Algebra.print_students();
}