#include "interfaz.hpp"
#include "clases.hpp"
#include <iostream>
#include <string>

using namespace std;

int main(){
    //prueba de enteros

    shared_ptr<numero> a = make_shared<entero>(-10);
    shared_ptr<numero> b = make_shared<entero>(5);
    entero prueba;
    shared_ptr<numero> res = prueba.suma(a,b);
    cout << dynamic_cast<entero*>(res.get())->toString(res)<<endl;
    shared_ptr<numero> res2 = prueba.resta(a,b);
    cout << dynamic_cast<entero*>(res2.get())->toString(res2)<<endl;
    shared_ptr<numero> res3 = prueba.mult(a,b);
    cout << dynamic_cast<entero*>(res3.get())->toString(res3)<<endl;

    cout<<"REALES"<<endl;
    shared_ptr<numero> num1 = make_shared<real>(-10.5);
    shared_ptr<numero> num2 = make_shared<real>(5);
    real realestry;
    shared_ptr<numero> res_real = realestry.suma(num1,num2);
    cout << dynamic_cast<real*>(res_real.get())->toString(res_real)<<endl;

    shared_ptr<numero> res_real2 = realestry.resta(num1,num2);
    cout << dynamic_cast<real*>(res_real2.get())->toString(res_real2)<<endl;

    shared_ptr<numero> res_3 = realestry.mult(num1,num2);
    cout << dynamic_cast<real*>(res_3.get())->toString(res_3)<<endl;

    cout<<"complejos"<<endl;
    shared_ptr<numero> complex1 = make_shared<complejo>(10.5,2);
    shared_ptr<numero> complex2 = make_shared<complejo>(2,3.7);
    complejo complex;
    shared_ptr<numero> res_complex = complex.suma(complex1,complex2);
    cout << dynamic_cast<complejo*>(res_complex.get())->toString(res_complex)<<endl;

    shared_ptr<numero> res_complex2 = complex.resta(complex1,complex2);
    cout << dynamic_cast<complejo*>(res_complex2.get())->toString(res_complex2)<<endl;

    shared_ptr<numero> res_complex3 = complex.mult(complex1,complex2);
    cout << dynamic_cast<complejo*>(res_complex3.get())->toString(res_complex3)<<endl;
    
}