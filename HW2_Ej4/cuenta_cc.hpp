#pragma once
#include "caja_ahorro.hpp"
#include "cuenta.hpp"
#include <string>

class caja_ahorro;

class cuenta_cc : public cuenta{
    public:
        cuenta_cc(string titular);
        void retirar(double retiro) override;
        void mostrarInfo() override;
        void setcaja_asociada(caja_ahorro caja_asociada);
    private:
        string titular;
        double dinero; 
        caja_ahorro caja_asociada;  
};