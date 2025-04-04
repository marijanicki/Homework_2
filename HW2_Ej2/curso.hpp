#pragma once
#include "estudiante.hpp"
#include <vector>
#include <string>
#include <algorithm>
#include <memory>

using namespace std;

class curso{
    private:
        string name;
        vector<shared_ptr<estudiante>> estudiantes_anotados; 
        
    public:
        curso(string name);
        //deep copy constructor
    
        //copy constructor
        curso(string name, const curso& copia);


        //sobrecarga del operador = para copiar los objetos
        //curso& operator =(const curso& other);

        //destructor
        //~curso();

        void inscribir(shared_ptr<estudiante> data_student);
        void desinscribir(shared_ptr<estudiante> data_student);
        bool is_inscripto(int id);
        bool is_full_capacity();
        void print_students();
};
