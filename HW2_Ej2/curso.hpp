#pragma once
#include "estudiante.hpp"
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class curso{
    private:
        string name;
        vector<estudiante*> estudiantes_anotados; 
        
    public:
        curso(string name, vector<estudiante*> estudiantes_anotados);
        //deep copy constructor
    
        //copy constructor
        curso(const curso& copia): copia.estudiantes_anotados;


        //sobrecarga del operador = para copiar los objetos
        //curso& operator =(const curso& other);

        //destructor
        ~curso();

        void inscribir(estudiante* data_student);
        void desinscribir(estudiante* data_student);
        bool is_inscripto(int id);
        bool is_full_capacity();
        void print_students();
};
