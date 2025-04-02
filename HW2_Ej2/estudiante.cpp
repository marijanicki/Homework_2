#include "estudiante.hpp"
#include <iostream>
#include <vector>
#include <utility>

estudiante::estudiante(string name, int id, string curso, int mark){
    this->name = name;
    this->id = id;
    this->marks.push_back(make_pair(curso, mark));  
}
//SETTERS 
void estudiante::setname(string name){
    this->name = name;
}
void estudiante::setid(int id){
    this->id = id;
}
void estudiante::setmarks(string curso, int mark){
    this->marks.push_back(make_pair(curso,mark));
}

//GETTERS 
string estudiante::getname(){
    return name;
}
int estudiante::getid(){
    return id;
}
float estudiante::getmarks() const{
   float prom = 0;
    for(size_t i = 0; i<marks.size();i++){
        prom += marks[i].second;
    }
    prom = static_cast<float>(prom) / static_cast<float>(marks.size());
    return prom;
}

bool estudiante::operator<(const estudiante& other)const {
    return name < other.name;
}

ostream& operator<<(ostream& ostr, const estudiante& other_student){
    ostr << "Nombre: "<<other_student.name <<"\nId: "<<other_student.id <<"\nPromedio: " << other_student.getmarks()<<endl;
    return ostr;
}
