#include "estudiante.hpp"
#include "curso.hpp"
#include <iostream>
#include <vector>
#include<string>

using namespace std;

curso::curso(string name){
    this->name = name;
}

//constructor deep copy
curso::curso(const curso& other){
    //this->name = other.name;
    for(size_t i = 0; i<other.estudiantes_anotados.size(); i++){
        //copio los estudiantes del original (other) en esta copia
        estudiantes_anotados.push_back(new estudiante(*other.estudiantes_anotados[i]));
    }
}

/*
//sobrecarga operador =
curso& curso::operator =(const curso& other){
    //reviso q no este asignando a si mismo, sino puedo liberar memoria sin querer
    if(this != &other){
        //en caso de que este ya tenga estudiantes asignados los borro asi no tengo leaks
        for(size_t i=0; i < estudiantes_anotados.size(); i++){
            delete estudiantes_anotados[i];
        }
        estudiantes_anotados.clear();
        //name = other.name;
        for(size_t i = 0;  i<other.estudiantes_anotados.size();i++){
            estudiantes_anotados.push_back(new estudiante(*other.estudiantes_anotados[i]));
        }
    }
    return *this;
}
*/
curso::~curso(){
    for(size_t i=0; i < estudiantes_anotados.size(); i++){
        delete estudiantes_anotados[i];
    }
}
void curso::inscribir(estudiante* data_student){
    if(!is_full_capacity()){
        estudiantes_anotados.push_back(data_student);
        return;
    }
    //throw runtime_error("Capacidad de alumnos llena");
}
void curso::desinscribir(estudiante* data_student){
    if(estudiantes_anotados.size() == 0){
        //throw runtime_error("No hay alumnos en el curso. No se puede desinscribir");
    }
    //find the pos of the student
    for(size_t i = 0; i<estudiantes_anotados.size(); i++){
        if(data_student->getname() == estudiantes_anotados[i]->getname()){
            estudiantes_anotados.erase(estudiantes_anotados.begin()+i);//uso begin ya que erase necesita un iterador, le sumo i así accedo a la pos q quiero
            return;
        }
    }
}
bool curso::is_inscripto(int id){
    for(size_t i = 0; i<estudiantes_anotados.size(); i++){
        if(id == estudiantes_anotados[i]->getid()){
            return true;
        }
    }
    return false;
}
bool curso::is_full_capacity(){
    if(estudiantes_anotados.size() <20){
        return false;
    }
    return true;
}

void curso::print_students(){
    sort(estudiantes_anotados.begin(), estudiantes_anotados.end(), [](estudiante* a, estudiante* b)->bool {return *a < *b;});//sort no retorna
    cout<<name<<endl;

    for(size_t i = 0; i<estudiantes_anotados.size();i++){
        cout<< *estudiantes_anotados[i]<<endl;
    }
    cout <<"---------------------------------"<<endl; 
}

/*
    for (const auto& estudiante : estudiantes_anotados) {
        cout << *estudiante << endl; // Usar el operador << sobrecargado
    }*/