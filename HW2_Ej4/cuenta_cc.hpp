#pragma once
#include "cuenta.hpp"
#include <string>

class caja_ahorro;

class cuenta_cc : public cuenta{
    public:
        cuenta_cc(string titular, double total, caja_ahorro caja_asociada);
        void retirar(double retiro) override;
        void mostrarInfo() override;

    protected:
        string titular;
        double total; 
        caja_ahorro caja_asociada;  
};