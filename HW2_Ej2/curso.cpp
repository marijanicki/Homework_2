#include "estudiante.hpp"
#include "curso.hpp"
#include <iostream>
#include <vector>
#include<string>
#include <memory>

using namespace std;

curso::curso(string name){
    this->name = name;
}

curso::curso(string name, const curso& other){
    this->name = name;
    this->estudiantes_anotados = other.estudiantes_anotados;
    
};

string curso::getname(){
    return name;
}

/*
//constructor deep copy
curso::curso(const curso& other){
    //this->name = other.name;
    for(size_t i = 0; i<other.estudiantes_anotados.size(); i++){
        //copio los estudiantes del original (other) en esta copia
        estudiantes_anotados.push_back(new estudiante(*other.estudiantes_anotados[i]));
    }
}
*/


void curso::inscribir(shared_ptr<estudiante> data_student){
    if(!is_full_capacity()){
        estudiantes_anotados.push_back(data_student);
        return;
    }
    throw runtime_error("Capacidad de alumnos llena");
}

void curso::desinscribir(shared_ptr<estudiante> data_student){
    if(estudiantes_anotados.size() == 0){
        throw runtime_error("No hay alumnos en el curso. No se puede desinscribir");
    }

    //find the pos of the student
    for(size_t i = 0; i<estudiantes_anotados.size(); i++){
        if(data_student->getname() == estudiantes_anotados[i]->getname()){
            estudiantes_anotados.erase(estudiantes_anotados.begin()+i);//uso begin ya que erase necesita un iterador, le sumo i así accedo a la pos q quiero
            return;
        }
    }
    //no hace nada porque no esta inscripto
}
bool curso::is_inscripto(int id){
    for(size_t i = 0; i<estudiantes_anotados.size(); i++){
        if(id == estudiantes_anotados[i]->getid()){
            cout << "Se encuentra inscripto"<<endl;
            return true;
        }
    }
    cout<<"El estudiante no se encuentra inscripto en el curso\n";
    return false;
}
bool curso::is_full_capacity(){
    if(estudiantes_anotados.size() <20){
        return false;
    }
    return true;
}

void curso::print_students(){
    sort(estudiantes_anotados.begin(), estudiantes_anotados.end(), [](shared_ptr<estudiante> a, shared_ptr<estudiante> b)->bool {return *a < *b;});//sort no retorna
    cout<<"\n"<<name<<endl;

    for(size_t i = 0; i<estudiantes_anotados.size();i++){
        cout<< *estudiantes_anotados[i]<<endl;
    }
    cout <<"---------------------------------"<<endl; 
}

/*
    for (const auto& estudiante : estudiantes_anotados) {
        cout << *estudiante << endl; // Usar el operador << sobrecargado
    }*/