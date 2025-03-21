#ifndef BANCO_HH
#define BANCO_HH

#include <fstream>
#include <cstring>
#include <iostream>
#include <sstream>

#include "Titular.hh"

using namespace std;

//Punto 1
struct Banco {
    char nombre[40];         // Bank name, 40 bytes
    char direccion[45];      // Bank address, 45 bytes
    Titular* titulares;      // Dynamic array of account holders
    int cantidadTitulares;   // Number of registered account holders
};

// Función para agregar un titular al banco
void agregarTitularBanco(Banco &banco, Titular &titular) {
    // Crear un nuevo arreglo con espacio para un titular adicional
    Titular *nuevosTitulares = new Titular[banco.cantidadTitulares + 1];
    
    // Copiar los titulares existentes al nuevo arreglo
    for (int i = 0; i < banco.cantidadTitulares; i++) {
        nuevosTitulares[i] = banco.titulares[i];
    }
    
    // Agregar el nuevo titular al final del arreglo
    nuevosTitulares[banco.cantidadTitulares] = titular;
    
    // Liberar memoria del arreglo anterior si existe
    if (banco.cantidadTitulares > 0 && banco.titulares != nullptr) {
        delete[] banco.titulares;
    }
    
    // Actualizar el puntero al nuevo arreglo
    banco.titulares = nuevosTitulares;
    
    // Incrementar el contador de titulares
    banco.cantidadTitulares++;
}

// Punto 4: Cargar archivo de texto
Banco cargarArchivo(const char* nombreArchivo) {
    fstream archivo(nombreArchivo, ios::in);
    Banco banco;
    banco.cantidadTitulares = 0;
    banco.titulares = nullptr;
    
    if (archivo.fail()) {
        cout << "Error al abrir el archivo " << nombreArchivo << endl;
        return banco;
    }
    
    string linea;
    
    Titular* titularActual = nullptr;
    // Procesar el resto del archivo
    while (getline(archivo, linea)) {
        
        if (titularActual != nullptr 
            && (linea.substr(0,2) == "CC" || linea=="#")) {
            agregarTitularBanco(banco, *titularActual);
            titularActual = nullptr;
        }

        // Si la línea comienza con CC, es un nuevo titular
        if (linea.substr(0, 2) == "CC" && titularActual == nullptr) {
           
            // Crear nuevo titular
            titularActual = new Titular;
            titularActual->cantidadTelefonos = 0;
            titularActual->telefonos = nullptr;
            titularActual->cantidadTarjetas = 0;
            titularActual->tarjetasCredito = nullptr;
            
            stringstream ss(linea);
            string token;
            
            // Leer cédula
            getline(ss, token, ',');
            strcpy(titularActual->cedula, token.c_str());
            
            // Leer nombre y apellido
            getline(ss, token, ',');
            strcpy(titularActual->nombreApellido, token.c_str());
            
            // Leer teléfonos
            while (getline(ss, token, ',')) {
                if (!token.empty()) {
                    char* telefono = new char[token.length() + 1];
                    strcpy(telefono, token.c_str());
                    agregarTelefonoTitular(*titularActual, telefono);
                }
            }
        } 
        // Si no comienza con CC, es información de una tarjeta para el titular actual
        else if (titularActual != nullptr) {
            stringstream ss(linea);
            string token;
            TarjetaCredito nuevaTarjeta;
            
            // Leer número de tarjeta
            getline(ss, token, ',');
            strcpy(nuevaTarjeta.numeroTarjeta, token.c_str());
            
            // Leer fecha de vencimiento
            getline(ss, token, ',');
            strcpy(nuevaTarjeta.fechaVencimiento, token.c_str());
            
            // Leer código de seguridad
            getline(ss, token, ',');
            nuevaTarjeta.codigoSeguridad = stoi(token);
            
            // Leer saldo disponible
            getline(ss, token);
            nuevaTarjeta.saldoDisponible = stod(token);
            
            // Agregar tarjeta al titular
            agregarTarjetaCreditoTitular(*titularActual, nuevaTarjeta);
        }
    }
    
    archivo.close();
    return banco;
}

// Punto 5: Generar reporte Martes Visa
void generarReporteMartesVisa(Banco &banco) {
    fstream archivo("MartesVisa.txt", ios::out);
    
    if (archivo.fail()) {
        cout << "Error al crear el archivo MartesVisa.txt" << endl;
        return;
    }
    
    for (int i = 0; i < banco.cantidadTitulares; i++) {
        Titular &titular = banco.titulares[i];
        
        // Escribir nombre del titular
        archivo << "Nombre: " << titular.nombreApellido << endl;
            
            // Escribir teléfonos celulares
        archivo << "Celular: ";

        for (int j = 0; j < titular.cantidadTelefonos; j++) {
            if (strlen(titular.telefonos[j].numeroTelefono) == 13) {
                archivo << titular.telefonos[j].numeroTelefono << ", ";               
            }
        }

        
        archivo << endl;
        
        
        // Escribir teléfonos fijos
        archivo << "Fijo: ";
        for (int j = 0; j < titular.cantidadTelefonos; j++) {
            if (strlen(titular.telefonos[j].numeroTelefono) == 10) {
                archivo << titular.telefonos[j].numeroTelefono << ",";
            }
        }

        archivo << endl;
        
        // Escribir tarjetas Visa
        for (int j = 0; j < titular.cantidadTarjetas; j++) {
            TarjetaCredito &tarjeta = titular.tarjetasCredito[j];
            if (tarjeta.numeroTarjeta[0] == '4') {
                archivo << tarjeta.numeroTarjeta << ", " 
                        << tarjeta.fechaVencimiento << ", " 
                        << tarjeta.saldoDisponible << endl;
            }
        }
        
        // Separador para el siguiente titular
        archivo << "#" << endl;
    }
    
    archivo.close();
}

// Punto 6: Guardar tarjetas en archivo binario
void guardarTarjetasBinario(Banco &banco) {
    ofstream archivo("tarjetas.dat", ios::binary | ios::out);
    
    if (archivo.fail()) {
        cout << "Error al crear el archivo tarjetas.dat" << endl;
        return;
    }
    
    // Recorrer todos los titulares y sus tarjetas
    for (int i = 0; i < banco.cantidadTitulares; i++) {
        Titular &titular = banco.titulares[i];
        
        // Recorrer todas las tarjetas del titular
        for (int j = 0; j < titular.cantidadTarjetas; j++) {
            // Escribir la tarjeta en el archivo binario
            archivo.write(reinterpret_cast<char*>(&titular.tarjetasCredito[j]), sizeof(TarjetaCredito));
        }
    }
    
    archivo.close();
}

#endif // BANCO_HH
