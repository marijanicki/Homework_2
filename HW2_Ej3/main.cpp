#include "interfaz.hpp"
#include "clases.hpp"
#include <iostream>
#include <string>

using namespace std;

int main(){
    shared_ptr<numero> a = make_shared<entero>(5);
    shared_ptr<numero> b = make_shared<entero>(3);
    entero prueba;
    shared_ptr<numero> res = prueba.suma(a,b);
    cout << dynamic_cast<entero*>(res.get())->toString(res);
}