#ifndef TARJETACREDITO_HH
#define TARJETACREDITO_HH


struct TarjetaCredito {
    char numeroTarjeta[17];      // 17 bytes for card number
    char fechaVencimiento[6];    // 6 bytes in MM/YY format
    int codigoSeguridad;         // Security code
    double saldoDisponible;      // Available balance
};

#endif // TARJETACREDITO_HH
