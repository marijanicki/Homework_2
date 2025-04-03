#pragma once
#include "cuenta.hpp"
#include <string>

class caja_ahorro : public cuenta{
    public:
        caja_ahorro(string titular, double total);
        void retirar(double retiro) override;
        void mostrarInfo() override;

        friend class cuenta_cc;
    private:
        int cant_muestras =0;  
};