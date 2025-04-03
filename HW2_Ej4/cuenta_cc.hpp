#pragma once
#include "cuenta.hpp"
#include <string>

class caja_ahorro;

class cuenta_cc : public cuenta{
    public:
        cuenta_cc(string titular, double total);
        void retirar(double retiro) override;
        void mostrarInfo() override;
        void no_money(caja_ahorro other_caja);


    protected:
        string titular;
        double total;   
};