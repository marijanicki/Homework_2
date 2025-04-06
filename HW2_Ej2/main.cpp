#include "estudiante.hpp"
#include "curso.hpp"
#include <iostream>
#include <memory>

using namespace std;

/*
La relación que existe entre los objetos es de asociación. Esto es debido a que 
se encuentran relacionados pero no existe un ownership. Es decir, si eliminaramos 
a un estudiante el curso no dejaría de existir. Y viceversa, si eliminamos un curso 
el estudiante no deja de existir, si así fuera se lo eliminaría de todos los otros
cursos al que esta inscripto.
*/

/*
Hice una copia deep copy. Esto es debido a que estamos alocando memoria y si nosotros 
copiamos los estudiantes de un curso a otro simplemente apuntando a ellos mediante
punteros pasaría que si yo elimino un estudiante se eliminaría de los dos. Y nosotros
lo que buscamos es simplemente copiar como se encuentra el curso en ese momento que se
copia y luego simplemente que sean dos cursos independientes que puedan inscribir y 
desinscribir a los estudiantes que quieran. Si se hiciera por referencia sucederia lo que
mencione anteriormente que estarían ligadas en cuanto a sus alumnos y siempre serían iguales
en cuanto a desinscribir.

Para realizarlo lo que hice fue hacer un constructor especifico para la copia.
A diferencia del constructor que uso para todas los objetos curso, a este le pido 
a su vez el objeto curso que quiero copiar. En la implementación del constructor
lo que hice fue 
*/

void show_curso(vector <curso> lista_cursos){
    cout << "Elija a que curso desea inscribirlo"<<endl;
    for(size_t i = 0; i<lista_cursos.size();i++){
        cout <<i<<"."<< lista_cursos[i].getname()<<endl; 
    } 
}

int main(){
    shared_ptr estudiante1 = make_shared<estudiante>("Maximo Barrera", 123, "Análisis 2", 2);
    shared_ptr estudiante2 = make_shared<estudiante>("Luca Lopez", 124, "Análisis 2", 4);
    shared_ptr estudiante3 = make_shared<estudiante>("Agustín Pacheco", 125, "Análisis 2", 2);
    shared_ptr estudiante4 = make_shared<estudiante>("Agustín Palavecino", 126, "Análisis 2", 2);
    shared_ptr estudiante5 = make_shared<estudiante>("Axel Patruno", 127, "Análisis 2", 2);
    shared_ptr estudiante6 = make_shared<estudiante>("Zoe Cabrera", 128, "Análisis 2", 2);
    shared_ptr estudiante7 = make_shared<estudiante>("Ana Carrizo", 129, "Análisis 2", 2);
    shared_ptr estudiante8 = make_shared<estudiante>("Camila Flores", 1230, "Análisis 2", 2);
    shared_ptr estudiante9 = make_shared<estudiante>("Carla Pereyra", 1245, "Análisis 2", 2);
    shared_ptr estudiante10 = make_shared<estudiante>("Maylen Villegas", 245, "Análisis 2", 2);
    shared_ptr estudiante11 = make_shared<estudiante>("Lucia Lopez", 7896, "Análisis 2", 2);
    shared_ptr estudiante12 = make_shared<estudiante>("Sofia Cariac", 2156, "Análisis 2", 2);
    shared_ptr estudiante13 = make_shared<estudiante>("Abigail Toledo", 7015, "Análisis 2", 2);
    shared_ptr estudiante14 = make_shared<estudiante>("Rodrigo Rugger", 4568, "Análisis 2", 2);
    shared_ptr estudiante15 = make_shared<estudiante>("Tomas Vocina", 8990, "Análisis 2", 2);
    shared_ptr estudiante16 = make_shared<estudiante>("Andy Warhol", 3475, "Análisis 2", 2);
    shared_ptr estudiante17 = make_shared<estudiante>("Martina Ferreyra", 36355, "Análisis 2", 2);
    shared_ptr estudiante18 = make_shared<estudiante>("Irupé Zacariaz", 3665, "Análisis 2", 2);
    shared_ptr estudiante19 = make_shared<estudiante>("Lautaro Caminos", 3635, "Análisis 2", 2);
    shared_ptr estudiante20 = make_shared<estudiante>("Santiago Porcel", 3482, "Análisis 2", 2);
    shared_ptr estudiante21 = make_shared<estudiante>("Benjamín Mccabe", 21603, "Análisis 2", 2);
    /*
    shared_ptr<curso> Algebra = make_shared<curso>("Algebra");
    shared_ptr<curso> Literatura = make_shared<curso>("Literatura");
    */
    curso Algebra("Algebra");
    curso Literatura("Literatura");
    vector <shared_ptr<estudiante>> lista_estudiantes = {estudiante1, estudiante2, estudiante3, estudiante4, estudiante5, estudiante6, estudiante7, estudiante8, estudiante9, estudiante10, estudiante11, estudiante12, estudiante13, estudiante14, estudiante15, estudiante16, estudiante17, estudiante18, estudiante19, estudiante20, estudiante21};
    vector <curso> lista_cursos = {Algebra, Literatura};
    
    bool menu = true;
    //Prueba inciso a.
    int op;
    int nota;
    string signature;
    char salir;
    while(menu){
        try{
            cout<<"Elija la operación que desea realizar:\n"
                <<"1.Ver nombre completo del estudiante\n"
                <<"2.Ver numero de legajo del estudiante\n"
                <<"3.Ver promedio del estudiante\n"
                <<"4.Ingresar materia cursada por el alumno con su nota final\n"
                <<"5.SALIR"<<endl;
            cin>>op;
            if(typeid(op) != typeid(int)){
                throw runtime_error("Ingreso tipo de dato inválido. Pruebe nuevamente");
            }
            if(op>5){
                cout << "Ingreso una opción incorrecta"<<endl;
                continue;
            }
            switch (op)
            {
            case 1:
                cout << estudiante1->getname()<<endl;
                break;
            case 2:
                cout <<estudiante1->getid()<<endl;
                break;
            case 3: 
                cout<<estudiante1->getmarks()<<endl;
            case 4:
                try{
                    cout << "Nombre de materia y promedio: ";
                    cin>>signature>>nota;
                    if(typeid(signature) != typeid(string) || typeid(nota) != typeid(int)){
                        throw runtime_error("Ingreso un tipo de dato invalido en el nombre de la materia o la nota");
                    }
                    estudiante1->setmarks(signature, nota);
                    break;
                }
                catch(const runtime_error& e){
                    cout <<"Runtime error:"<< e.what()<<endl;
                }
            case 5:
                break;
            default:
                cout << "Ingreso un comando inválido"<<endl;
            }
        }
        catch(const runtime_error& e){
            cout << "Runtime error: "<<e.what()<<endl;
        }

        try{
            cout << "¿Desea realizar otra operación? Y/N\n";
            cin >>salir;
            if(salir == 'N' || salir == 'n'){
                cout << "Pasando a prueba de inciso B";
                menu = false;
            }
            else if(salir == 'Y' || salir == 'y'){
                continue;
            }
            else if(typeid(salir) != typeid(string)){
                throw runtime_error("Ingreso un tipo de dato inválido");
            }
            else{
                cout << "Ingreso una opción incorrecta. Vuelva a intentarlo"<<endl;
            }
        }
        catch(const runtime_error& f){
            cout << f.what()<<endl;
        }
    }



    cout <<"\n\nPrueba inciso b\n";
    menu = true;
    int num_est;
    int num_curso;
    bool valid = true;
    

    while(menu){
            valid = true;
            cout<<"Elija la operación que desea realizar:\n"
                <<"1. Inscribir alumno\n"
                <<"2. Desincribir alumno\n"
                <<"3. Chequear si alumno esta inscripto\n"
                <<"4. Revisar si curso sin cupo\n"
                <<"5. Imprimir lista estudiantes en un curso\n"
                <<"6. Hacer copia de alumnos del curso\n"
                <<"7.SALIR\n";
            cin>>op;
            
            if(op>7){
                cout << "Ingreso una opción incorrecta"<<endl;
                continue;
            }

            if(op == 6){
                lista_cursos[0].print_students();
                curso Paradigmas = curso("Paradigmas", lista_cursos[0]);
                Paradigmas.print_students();
                lista_cursos.push_back(Paradigmas);
                
            }
            switch (op){
                case 1:
                    try{
                        while(valid){
                            cout<<"Elija que estudiante desea inscribir(0-20): ";
                            cin>>num_est;
                            if(num_est <0 || num_est >20){
                                cout<<"Ingreso un numero fuera de rango. Intente nuevamente."<<endl;
                                continue;
                            }
                            
                            show_curso(lista_cursos);
                            cin>>num_curso;
                            if(num_curso <0 || static_cast<size_t>(num_curso) >lista_cursos.size()){
                                cout<<"Ingreso un numero fuera de rango. Intente nuevamente."<<endl;
                                continue;
                            }
                            
                            if(lista_cursos[num_curso].is_inscripto(lista_estudiantes[num_est]->getid())){
                                
                                break;
                            }
                            lista_cursos[num_curso].inscribir(lista_estudiantes.at(num_est));
                            valid = false;
                        }
                    }
                    catch(const runtime_error& e){
                        cout << e.what()<<endl;
                    
                    }
                    
                    break;
                case 2:
                    valid = true;
                    while(valid){
                        cout<<"Elija que estudiante desea desinscribir(0-20): ";
                        cin>>num_est;
                        if(num_est <0 || num_est >20){
                            cout<<"Ingreso un numero fuera de rango. Intente nuevamente."<<endl;
                            continue;
                        }
                        show_curso(lista_cursos);
                        cin>>num_curso;
                        if(num_curso <0 || static_cast<size_t>(num_curso) >lista_cursos.size()){
                            cout<<"Ingreso un numero fuera de rango. Intente nuevamente."<<endl;
                            continue;
                        }
                        try{
                            lista_cursos[num_curso].desinscribir(lista_estudiantes.at(num_est));
                            valid = false;
                        }
                        catch(const runtime_error& e){
                            cout<< e.what()<<endl;
                        }
                        valid = false;
                    }
                    break;
                
                case 3:
                    valid = true;
                    while(valid){
                        cout<<"Elija que estudiante desea ver si esta inscripto(0-20): ";
                            cin>>num_est;
                        if(num_est <0 || num_est >20){
                            cout<<"Ingreso un numero fuera de rango. Intente nuevamente."<<endl;
                            continue;
                        }
                        show_curso(lista_cursos);
                        cin>>num_curso;
                        if(num_curso <0 || static_cast<size_t>(num_curso) >lista_cursos.size()){
                            cout<<"Ingreso un numero fuera de rango. Intente nuevamente."<<endl;
                            continue;
                        }
                        lista_cursos[num_curso].is_inscripto(lista_estudiantes.at(num_est)->getid());
                        valid = false;
                    }
                    break;
                case 4:
                    valid = true;
                    while (valid){
                        show_curso(lista_cursos);
                        cin>>num_curso;
                        if(num_curso <0 || static_cast<size_t>(num_curso) >lista_cursos.size()){
                            cout<<"Ingreso un numero fuera de rango. Intente nuevamente."<<endl;
                            continue;
                        }
                        if(lista_cursos[num_curso].is_full_capacity()){
                        cout << "Se encuentra sin cupo"<<endl;
                        }
                        else{
                            cout << "Hay cupos disponibles"<<endl;
                        }
                        valid = false;
                    }
                    break;
                case 5:
                    while (valid){
                        show_curso(lista_cursos);
                        cin>>num_curso;
                        if(num_curso <0 || static_cast<size_t>(num_curso) >lista_cursos.size()){
                            cout<<"Ingreso un numero fuera de rango. Intente nuevamente."<<endl;
                            continue;
                        }
                        lista_cursos[num_curso].print_students();
                        valid = false;
                    }
                    break;
                case 6:
                    break;
                case 7: 
                    return 0;
                default:
                    cout <<"Ingreso una operación inválida";
                
                    
            }
        //no se puede hacer dentro del switch porque no se pueden crear variables dentro
        
            
        
        
        try{
            cout << "¿Desea realizar otra operación? Y/N\n";
            cin >>salir;
            if(salir == 'N' || salir == 'n'){
                cout << "Cerrando...";
                menu = false;
            }
            else if(salir == 'Y' || salir == 'y'){
                continue;
            }
            else if(typeid(salir) != typeid(string)){
                throw runtime_error("Ingreso un tipo de dato inválido");
            }
            else{
                cout << "Ingreso una opción incorrecta. Vuelva a intentarlo"<<endl;
            }
        }
        catch(const runtime_error& f){
            cout << f.what()<<endl;
        }
    }

}