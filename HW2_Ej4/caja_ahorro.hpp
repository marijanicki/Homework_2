#pragma once
#include "cuenta.hpp"
#include <string>

class caja_ahorro : public cuenta{
    public:
        friend class cuenta_cc;
        caja_ahorro();
        caja_ahorro(string titular);
        void retirar(double retiro) override;
        void mostrarInfo() override;
    private:
        int cant_muestras = 0; 
        string titular;
         
};