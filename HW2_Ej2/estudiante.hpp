#pragma once
#include <string>
#include <vector>
#include <utility>
using namespace std;

class estudiante{
    private:
        string name;
        int id;
        vector <pair<string, int> > marks;
    public:
        estudiante(string name, int id, string curso, int marks);
        //SETTERS
        void setname(string name);
        void setid(int id);
        void setmarks(string curso, int mark);

        //GETTERS
        string getname();
        int getid();
        float getmarks()const;

        //sobrecarga de operadores

        bool operator<(const estudiante& other)const;
        //quiero que << acceda a los atributos del estudiante por eso lo declaro como friend(es privado sino no podría)
        friend ostream& operator<<(ostream& ostr, const estudiante& other_student);
        //preguntar pq en este caso no va el const al final
        
};