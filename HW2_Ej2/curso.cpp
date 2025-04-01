#include "estudiante.h"
#include "curso.h"
#include <vector>

using namespace std;

curso::curso(){
    capacity = 0;
}

void curso::inscribir(estudiante* data_student){
    estudiantes.push_back(data_student);
}