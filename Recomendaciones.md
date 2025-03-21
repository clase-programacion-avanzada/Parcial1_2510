# Tips para el parcial

Recuerden que cuando quieran crear un nuevo arreglo de caracteres, a partir de un string, pueden hacerlo de la siguiente manera:

```c++

string stringQueQuieroConvertir = "Hola mundo";
char *nuevoArreglo = new char[stringQueQuieroConvertir.length() + 1];
strcpy(nuevoArreglo, stringQueQuieroConvertir.c_str());

```

Si van a validar el tamaño de un arreglo de caracteres, recuerden que el tamaño del arreglo es una unidad más grande que el índice del último elemento. Por ejemplo, si el arreglo tiene tamaño 10, el último índice es 9.

```c++

char * arreglo = "6014327865";

strlen(arreglo); // Devuelve 10, pero el tamaño del arreglo es 11, 
//porque el último elemento del arreglo es el caracter '\0'

```

**En el parcial, una tarjeta es VISA si empieza con 4.**
