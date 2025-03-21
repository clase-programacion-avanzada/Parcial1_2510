#include <iostream>
#include <string>
#include <sstream>

#include "libs/Banco.hh"
#include "libs/Titular.hh"
#include "libs/Telefono.hh"
#include "libs/TarjetaCredito.hh"

using namespace std;

// Function declaration for adding titular to bank (supposed to be implemented already)
void agregarTitularBanco(Banco &banco, Titular &titular);

int main() {
    // Cargar datos del archivo
    Banco miBanco = cargarArchivo("cuentas.txt");
    
    // Generar reporte Martes Visa
    generarReporteMartesVisa(miBanco);
    
    // Guardar tarjetas en archivo binario
    guardarTarjetasBinario(miBanco);
    
    cout << "Procesamiento completado exitosamente." << endl;
    
    return 0;
}