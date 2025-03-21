#ifndef TITULAR_HH
#define TITULAR_HH

#include <cstring>

#include "Telefono.hh"
#include "TarjetaCredito.hh"

//Punto 1
struct Titular {
    char cedula[20];           // ID number starting with CC, 20 bytes
    char nombreApellido[40];     // Full name, 40 bytes
    Telefono* telefonos;         // Dynamic array of phone numbers
    int cantidadTelefonos;       // Number of registered phones
    TarjetaCredito* tarjetasCredito; // Dynamic array of credit cards
    int cantidadTarjetas;        // Number of credit cards
};

// Punto 2: Agregar teléfono en titular
void agregarTelefonoTitular(Titular &titular, char *numeroTelefono) {
    
    // Crear nueva instancia de Telefono
    Telefono nuevoTelefono;
    
    // Asignar memoria para el número (14 bytes para celular, 11 bytes para fijo)
    int cantidadDeBytesTelefono = strlen(numeroTelefono) + 1;

    nuevoTelefono.numeroTelefono = new char[cantidadDeBytesTelefono];
    strcpy(nuevoTelefono.numeroTelefono, numeroTelefono);
    
    // Crear un nuevo arreglo con espacio para un teléfono adicional
    Telefono *nuevosTelefonos = new Telefono[titular.cantidadTelefonos + 1];
    
    // Copiar los teléfonos existentes al nuevo arreglo
    for (int i = 0; i < titular.cantidadTelefonos; i++) {
        nuevosTelefonos[i] = titular.telefonos[i];
    }
    
    // Agregar el nuevo teléfono al final del arreglo
    nuevosTelefonos[titular.cantidadTelefonos] = nuevoTelefono;
    
    // Liberar memoria del arreglo anterior si existe
    if (titular.cantidadTelefonos > 0 && titular.telefonos != nullptr) {
        delete[] titular.telefonos;
    }
    
    // Actualizar el puntero al nuevo arreglo
    titular.telefonos = nuevosTelefonos;
    
    // Incrementar el contador de teléfonos
    titular.cantidadTelefonos++;
}

// Punto 3: Agregar tarjeta de crédito a titular
void agregarTarjetaCreditoTitular(Titular &titular, TarjetaCredito &tarjeta) {
    // Crear un nuevo arreglo con espacio para una tarjeta adicional
    TarjetaCredito *nuevasTarjetas = new TarjetaCredito[titular.cantidadTarjetas + 1];
    
    // Copiar las tarjetas existentes al nuevo arreglo
    for (int i = 0; i < titular.cantidadTarjetas; i++) {
        nuevasTarjetas[i] = titular.tarjetasCredito[i];
    }
    
    // Agregar la nueva tarjeta al final del arreglo
    nuevasTarjetas[titular.cantidadTarjetas] = tarjeta;
    
    // Liberar memoria del arreglo anterior si existe
    if (titular.cantidadTarjetas > 0 && titular.tarjetasCredito != nullptr) {
        delete[] titular.tarjetasCredito;
    }
    
    // Actualizar el puntero al nuevo arreglo
    titular.tarjetasCredito = nuevasTarjetas;
    
    // Incrementar el contador de tarjetas
    titular.cantidadTarjetas++;
}

#endif // TITULAR_HH
