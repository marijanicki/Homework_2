#pragma once
#include <string>

using namespace std;

class cuenta{
    public: 
        cuenta();
        cuenta(string titular, string tipo_cuenta, double total);//constructor
        string getTipoCuenta();
        virtual double balance()const;
        virtual string titularCuenta();
        virtual void depositar(double deposito);
        virtual void retirar(double retiro)=0; //virtual puro, no implementar en esta clase
        virtual void mostrarInfo()=0; //virtual puro

        //setters
        void setTipoCuenta(string tipo);
        //getters


        virtual ~cuenta(); //lo hago virtual así si alguien elimina su cuenta la elimina desde la base y no solo la derivada
    protected:
        double dinero;
        string tipo_cuenta;
        string titular;
};
