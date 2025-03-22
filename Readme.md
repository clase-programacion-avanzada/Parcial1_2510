# Solución parcial 1 - 2510

## I. (20 PUNTOS) CONCEPTOS  

1. Dado el siguiente código, ¿qué imprimirá?  
   ```cpp
   int arr[] = {10, 20, 30, 40};  
   int* ptr = &arr[1];  
   cout << *ptr;
   ```
	- [ ] a. 10
	- [ ] b. 20
	- [ ] c. Dirección de memoria de arr[1]
	- [ ] d. Error de compilación

   <details>
       <summary>Respuesta</summary>
       Opción (b). `ptr` apunta a `arr[1]`, que tiene el valor `20`.
   </details>  


2.	En C++, cuando declaramos un apuntador y reservamos memoria con el operador new, la memoria se libera automáticamente cuando el programa termina.
	- [ ] a. Verdadero
	- [ ] b. Falso

    <details>
        <summary>Respuesta</summary>
        Opción (b). La memoria reservada con `new` debe liberarse manualmente con `delete`.
    </details>  



3.	¿Qué resultado produce el siguiente código?
    ```cpp
    char str[] = "Hola";  
    std::cout << (str + 2);
    ```
	- [ ] a. H
	- [ ] b. o
	- [ ] c. l
	- [ ] d. a

    <details>
        <summary>Respuesta</summary>
        Opción (c). `str + 2` apunta al tercer carácter, que es `"l"`.
    </details>  



4.	Para leer datos de un archivo binario en C++, se utiliza:
    - [ ] a. read()
    - [ ] b. get()
    - [ ] c. getline()
    - [ ] d. scanf()

    <details>
        <summary>Respuesta</summary>
        Opción (a). `read()` es la función adecuada para leer archivos binarios.
    </details>  



5.	¿Cuál es la diferencia entre delete y delete[] en C++?
    - [ ] a. delete se usa para liberar memoria de variables individuales, delete[] para arreglos dinámicos.
    - [ ] b. delete solo se usa con punteros a objetos, delete[] con punteros a estructuras.
    - [ ] c. delete[] libera más memoria que delete.
    - [ ] d. No hay diferencia, ambos se pueden usar indistintamente.

    <details>
        <summary>Respuesta</summary>
        Opción (a). `delete` se usa para una sola variable, `delete[]` para arreglos dinámicos.
    </details>  



6.	¿Qué utilizamos preferentemente para almacenar información de estudiantes con nombres, apellidos y calificaciones?
    - [ ] a. Un arreglo
    - [ ] b. Una matriz
    - [ ] c. Un struct
    - [ ] d. Un apuntador

    <details>
        <summary>Respuesta</summary>
        Opción (c). `struct` permite agrupar distintos tipos de datos en una sola estructura.
    </details>  



7.	¿Qué hace el siguiente código?
    ```cpp
    int a = 10;  
    int* p1 = &a;  
    int** p2 = &p1;  
    cout << *p2;
    ```

	- [ ] a. Imprime la dirección de a.
	- [ ] b. Utiliza p2 de forma incorrecta.
	- [ ] c. Lanza un error de compilación.
	- [ ] d. Imprime la dirección de p1.

    <details>
        <summary>Respuesta</summary>
        Opción (a). Imprime la dirección de a
        
        `p2` apunta a `p1`, que a su vez apunta a `a`.

        | variable | valor almacenado |
        |----------|------------------|
        | p2       | dirección de p1  |
        | p1       | dirección de a   |
        | a        | 10               |

        Si imprimimos '*p2', se imprime el valor almacenado por p1, que es la dirección de 'a'.
    </details>  



8.	En una función que recibe un parámetro por referencia:
    - [ ] a. La función recibe una copia del valor como parámetro.
    - [ ] b. La función recibe la dirección de la variable que se envió como parámetro.
    - [ ] c. La función puede modificar la dirección del apuntador.
    - [ ] d. La función no puede acceder al dato del parámetro.

    <details>
        <summary>Respuesta</summary>
        Opción (b). En paso por referencia, la función recibe la dirección de la variable original.
    </details>  



9.	¿Qué operación se realiza en la siguiente línea de código?
    ```cpp
    ifstream archivo("datos.txt", ios::in);
    ```
	- [ ] a. Crear un nuevo archivo de texto para escritura.
	- [ ] b. Abrir un archivo de texto existente para lectura.
	- [ ] c. Abrir un archivo binario para lectura.
	- [ ] d. Crear un nuevo archivo binario para escritura y lectura.

    <details>
        <summary>Respuesta</summary>
        Opción (b). `ifstream` con `ios::in` abre un archivo de texto para lectura.
    </details>  

10.	¿Qué hace la función write en un archivo binario?

	- [ ] a. Escribe un apuntador en el archivo.
	- [ ] b. Escribe una cadena de texto en el archivo.
	- [ ] c. Escribe un número entero en el archivo.
	- [ ] d. Escribe un bloque de memoria en el archivo.
    <details>
       <summary>Respuesta</summary>
       Opción (d). `write()` escribe un bloque de memoria en un archivo binario.
   </details>  

## II. (80 PUNTOS) SISTEMA BANCARIO PARA GESTIÓN DE TARJETAS DE CRÉDITO  

Un banco de Colombia desea desarrollar un programa en c++ para gestionar a los clientes y sus tarjetas de crédito.  El dueño del banco le ha proporcionado la siguiente información sobre las estructuras a utilizar:  

### **Teléfono**  

1) `numeroTelefono`: cadena de caracteres de tamaño dinámico (14 bytes para celular, 11 bytes para teléfono fijo).

### **TarjetaCredito**

1) `numeroTarjeta`: cadena de caracteres de 17 bytes  
2) `fechaVencimiento`: cadena de caracteres de 6 bytes en formato (MM/AA)  
3) `codigoSeguridad`: código de seguridad de la tarjeta (int)  
4) `saldoDisponible`: saldo disponible en la tarjeta (double)  

### **Titular**

1) `cedula`: cadena de caracteres que empieza por 'CC' (20 bytes)  
2) `nombreApellido`: cadena de caracteres de 40 bytes  
3) `telefonos`: arreglo dinámico de números de teléfono  
4) `cantidadTelefonos`: número de teléfonos registrados 
5) `tarjetasCredito`: arreglo dinámico de la estructura `TarjetaCredito`  
6) `cantidadTarjetas`: número de tarjetas de crédito con las que cuenta el titular (int)

### **Banco**

1) `nombre`: cadena de caracteres de 40 bytes  
2) `direccion`: cadena de caracteres de 45 bytes  
3) `titulares`: arreglo dinámico de la estructura `Titular`  
4) `cantidadTitulares`: cantidad de titulares registrados en el banco (int)

El banco cuenta con el siguiente archivo de texto **cuentas.txt**, en el que se encuentra la información existente del banco, de los titulares y de las tarjetas:  

``` txt
Banco de Bogotá, Calle 36 #7-47
CC1234, Juan Fernandez, +573015026783, 6014327865
4539876543211234, 05/28, 723, 1500.75
5130298756349825, 06/25, 456, 5000.50
CC32135, Maria Gómez, 6014327865
5012345678910234, 11/27, 789, 4200.50
#
```

1) La primera línea contiene la información del banco (nombre y dirección).  
2) La segunda línea contiene la descripción del titular (cédula, nombre, teléfono) y varios teléfonos separados por comas.  
3) Las líneas siguientes contienen las tarjetas de crédito que pertenecen al titular.  
4) Cuando aparece una nueva cédula, indica que un nuevo titular ha comenzado.
5) El caracter # significa que ha terminado el archivo.

---

A partir de la información proporcionada, se le solicita implementar los siguientes servicios:

1. **(5 puntos) Definir las estructuras `Banco`, `Titular` y `Teléfono`**  
   Escribir la definición de las estructuras **Banco**, **Titular** y **Teléfono**.  

2. **(20 puntos) Agregar teléfono en titular**  
   Dado un titular por referencia y un arreglo de caracteres con un número de teléfono, adicionar el número al arreglo dinámico de teléfonos del titular.  
   - [ ] **Nota:** se debe validar que, si el número tiene prefijo, el arreglo de caracteres debe ser de 14 bytes (celular) y 11 bytes en caso contrario (fijo).

3. **(15 puntos) Agregar tarjeta de crédito a titular**  
   Dado el titular y la tarjeta de crédito por referencia, agregar la tarjeta al titular.  

4. **(25 puntos) Cargar archivo de texto**  
   A partir del archivo **cuentas.txt**, cargar los datos en la estructura del banco, los titulares y las tarjetas de crédito, almacenando teléfonos en memoria.  

5. **(10 puntos) Generar reporte Martes Visa**  
   Generar un archivo de texto **MartesVisa.txt** con los titulares que cuentan con el descuento **Martes Visa** y con las tarjetas con las que puede aplicar.La función recibe como parámetro el Banco por referencia. En este archivo la información que debe mostrar tiene el siguiente formato en el que el carácter # es para separar al siguiente titular:

    ``` txt
    Nombre: Juan Fernandez
    Celular: +573001526783, +573017895645,
    Fijo:
    6014327865,
    4539876543211234, 05/28, 1500.75
    #
    Nombre: Maria Gomez
    Celular:
    Fijo:
    #
    6014327865,
    #
    ```

6. **(5 puntos) Guardar tarjetas en archivo binario**  
generar un archivo binario tarjetas.dat en el que se almacene solamente la información de las tarjetas de crédito de los titulares del banco. Esta función recibe como parámetro el banco por referencia.

- **Restricciones:**
  - Los arreglos deben ser dinámicos.
  - **Nota:** Se supone que ya está implementado el método `agregarTitularBanco(Banco *banco, Titular *titular)` para agregar titulares al banco.  
