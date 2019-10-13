//
//Archivo: Lenguaje.h
//Fecha: 05/10/2019
//Autor: Diego Cruz Rodríguez
//Titulo: Práctica 3 de Computabilidad y Algoritmia
//Uso del archivo: Declaracion de clase Lenguaje
//

#ifndef LENGUAJE_H
#define LENGUAJE_H

#include  <set>
#include <string>

class Lenguaje {
 private:
   std::set<std::string> Lenguaje_;
 public:
   Lenguaje();
   ~Lenguaje();
   std::set<std::string>& getset();
   void read(std::string &linea);
   std::ostream& write(std::ostream& os);
   void Inversa();
   std::set<std::string> Concatenacion(Lenguaje SegundoLenguaje);
   std::set<std::string> Potencia(unsigned repeticiones);
   void Cierre_positivo(std::ostream& os);
   void Cierre_kleene(std::ostream& os);
   bool SubLenguaje(Lenguaje SegundoLenguaje);
   
};


#endif //LENGUAJE_H
