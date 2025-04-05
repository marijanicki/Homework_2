#include "estudiante.hpp"
#include "curso.hpp"
#include <iostream>
#include <memory>

using namespace std;

int main(){
    shared_ptr estudiante1 = make_shared<estudiante>("Maximo Perez", 36355, "Análisis 2", 2);
    shared_ptr estudiante2 = make_shared<estudiante>("Luca Lopez", 69420, "Análisis 2", 4);
    shared_ptr estudiante3 = make_shared<estudiante>("Agustín Pacheco", 36355, "Análisis 2", 2);
    shared_ptr estudiante4 = make_shared<estudiante>("Agustín Palavecino", 36355, "Análisis 2", 2);
    shared_ptr estudiante5 = make_shared<estudiante>("Axel Patruno", 36355, "Análisis 2", 2);
    shared_ptr estudiante6 = make_shared<estudiante>("Zoe Cabrera", 36355, "Análisis 2", 2);
    shared_ptr estudiante7 = make_shared<estudiante>("Ana Carrizo", 36355, "Análisis 2", 2);
    shared_ptr estudiante8 = make_shared<estudiante>("Camila Flores", 36355, "Análisis 2", 2);
    shared_ptr estudiante9 = make_shared<estudiante>("Carla Pereyra", 36355, "Análisis 2", 2);
    shared_ptr estudiante10 = make_shared<estudiante>("Maylen Villegas", 36355, "Análisis 2", 2);
    shared_ptr estudiante11 = make_shared<estudiante>("Lucia Lopez", 36355, "Análisis 2", 2);
    shared_ptr estudiante12 = make_shared<estudiante>("Sofia Cariac", 36355, "Análisis 2", 2);
    shared_ptr estudiante13 = make_shared<estudiante>("Abigail Toledo", 36355, "Análisis 2", 2);
    shared_ptr estudiante14 = make_shared<estudiante>("Rodrigo Rugger", 36355, "Análisis 2", 2);
    shared_ptr estudiante15 = make_shared<estudiante>("Tomas Vocina", 36355, "Análisis 2", 2);
    shared_ptr estudiante16 = make_shared<estudiante>("Andy Warhol", 36355, "Análisis 2", 2);
    shared_ptr estudiante17 = make_shared<estudiante>("Martina Ferreyra", 36355, "Análisis 2", 2);
    shared_ptr estudiante18 = make_shared<estudiante>("Irupé Zacaraíz", 36355, "Análisis 2", 2);
    shared_ptr estudiante19 = make_shared<estudiante>("Lautaro Caminos", 36355, "Análisis 2", 2);
    shared_ptr estudiante20 = make_shared<estudiante>("Santiago Porcel", 36355, "Análisis 2", 2);
    shared_ptr estudiante21 = make_shared<estudiante>("Benjamín Mccabe", 36355, "Análisis 2", 2);
    
    vector <shared_ptr<estudiante>> lista_estudiantes = {estudiante1, estudiante2, estudiante3, estudiante4, estudiante5, estudiante6, estudiante7, estudiante8, estudiante9, estudiante10, estudiante11, estudiante12, estudiante13, estudiante14, estudiante15, estudiante16, estudiante17, estudiante18, estudiante19, estudiante20, estudiante21};
    curso Algebra("Algebra");
    curso Literatura("Literatura");
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
    bool valid = true;
    while(menu){
        try{
            cout<<"Elija la operación que desea realizar:\n"
                <<"1. Inscribir alumno\n"
                <<"2. Desincribir alumno\n"
                <<"3. Chequear si alumno esta inscripto\n"
                <<"4. Revisar si curso sin cupo\n"
                <<"5. Imprimir lista estudiantes en un curso\n"
                <<"6. Copiar alumnos de un curso a otro\n";
            cin>>op;
            if(typeid(op) != typeid(int)){
                throw runtime_error("Ingreso tipo de dato inválido. Pruebe nuevamente");
            }
            if(op>6){
                cout << "Ingreso una opción incorrecta"<<endl;
                continue;
            }
            switch (op){
                case 1:
                    while(valid){
                        try{
                            cout<<"Elija que estudiante desea inscribir(0-20): ";
                            cin>>num_est;
                            if(typeid(num_est) != typeid(int)){
                                throw runtime_error("ERROR: Ingreso un tipo de dato inválido.");
                            }
                            if(num_est <0 || num_est >20){
                                cout<<"Ingreso un numero fuera de rango. Intente nuevamente."<<endl;
                                continue;
                            }
                            Algebra.inscribir(lista_estudiantes.at(num_est));
                            Algebra.print_students();
                            valid = false;
                            
                        }
                        catch(const runtime_error& e){
                            cout << e.what()<<endl;
                        }
                    }
                    break;
                case 2:
                    try{
                        cout<<"Elija que estudiante desea desinscribir(0-20): ";
                        cin>>num_est;
                        if(typeid(num_est) != typeid(int)){
                            throw runtime_error("ERROR: Ingreso un tipo de dato inválido.");
                        }
                        if(num_est <0 || num_est >20){
                            cout<<"Ingreso un numero fuera de rango. Intente nuevamente."<<endl;
                            continue;
                        }
                        try{
                            Algebra.desinscribir(lista_estudiantes.at(num_est));
                            
                        }
                        catch(const runtime_error& e){
                            cout<< e.what()<<endl;
                        }
                        break;
                    }
                    catch(const runtime_error& e){
                        cout << e.what()<<endl;
                    }
                
                case 3:
                    Algebra.is_inscripto()
                default:
                    cout <<"Ingreso una operación inválida";

                    
            }
        }
        catch(const runtime_error& e){
            cout << e.what();
        }

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