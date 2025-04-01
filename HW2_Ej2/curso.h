#include "estudiante.h"
#include <vector>

using namespace std;

class curso{
    private:
        vector<estudiante*> estudiantes; 
        int capacity;

    public:
        curso();

        void inscribir(estudiante* data_student);
        void desinscribir(estudiante* data_student);
        bool is_inscripto(int id);
        bool full_capacity();
        void print_students();
};