# Práctica 3 Computabilidad y Algoritmia
### Objetivos
Trabajar los conseptos básicos sobre alfabetos, cadenas y lenguajes formales a
través del diseño de una caluladora para lenjuajes formales.

### Se evaluara
El programa ha de seguir el paradigma de orientación a objetos
El codigo ha de ser modular
El comportamiento del programa ha ajustars a lo solicitado en el enunciado
El código ha de estar escrito de acuerdo a Google C++ Style Guide
Capacidades del programador de introducir cambios en el programa

### Enunciado

El programa recojera de la linea de comandos los fichero de entrada y salida,
junto con el codigo de operacion quedando algo como:

```bash
./Calculadora filein.txt fileout.txt codigo
```

Donde el codigo será un número entero que se identifica con las operaciones
siguiendo la siguientes tabla:
1. Concatenación
2. Unión
3. Intersección
4. Diferencia
5. Sublenguajes
6. Igualdad de lenguajes
7. Inversa
8. Potencia
9. Cierre positivo
10. Cierre de Kleene

Concatenación, unión, intersección y diferencia, se necesitarán dos 
lenguajes de entrada y se obtendrá un lenguaje de salida.

Sublenguajes y igualdad de lenguajes, tambien necesitarán dos lenguajes de
entrada, aunque como salida obtendremos un valor de tipo booleano.

Inversa, potencia, cierre positivo y cierre de Kleene, bastará con tener un
único lenguaje de entrada, como salida obtendremos un lenguaje que además,
en el caso del cierre positivo y el cierre de Kleene podrá ser infinito.

Ejemplo de fichero de entrada:
```bash
{abc, bbcc, a, cab}
{a, aa, aaa}
{&}
[0, 1, 00, 01, 10, 11}
```

Cada líne del fichero de entrada contiene, entre llaves las cadenas que
conforman un lenguje.
Las llaves, los espacios y las comas no deben usarse como símbolos de los 
alfabetos.
Para espesificar la cadena vacía utilizaremos &, por lo que tampoco se podra
usar como simbolo de los alfabetos
Para definir el lenguaje vacío
```bash
{}
```

Supondremos que en este ejercicio todos los lenguajes de entrada tendrán un
número finito de cadenas.

Modificacion permitir añadir para la concateanacion el numero de operandos.
