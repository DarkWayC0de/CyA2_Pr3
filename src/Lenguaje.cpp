//
//Archivo: Lenguaje.cpp
//Fecha: 05/10/2019
//Autor: Diego Cruz Rodríguez
//Titulo: Práctica 3 de Computabilidad y Algoritmia
//Uso del archivo: Implentacion de la clase Lenguaje
//
#include <iostream>
#include <algorithm>
#include "Lenguaje.h"

Lenguaje::Lenguaje(){

}

Lenguaje::~Lenguaje(){

}

std::set<std::string>& Lenguaje::getset(){
  return Lenguaje_;
}
void Lenguaje::read(std::string  &linea) {
  if (linea[0]=='{') {
    while (!linea.empty()) {
      char caracterfinal = linea.back();
      linea.pop_back();
      if ( caracterfinal != '{' && caracterfinal != ' ' && 
           caracterfinal != '}' && caracterfinal != ',') {
        std::string reconstrucion_cadena_inversa;
        while ((caracterfinal != '{' && 
                caracterfinal != ' ' && 
                caracterfinal != '}' && 
                caracterfinal != ',') &&
               (!linea.empty())) {
          reconstrucion_cadena_inversa += caracterfinal;
          caracterfinal = linea.back();
          linea.pop_back();
        }
        std::string cadena;
        while(!reconstrucion_cadena_inversa.empty()){
          cadena += reconstrucion_cadena_inversa.back();
          reconstrucion_cadena_inversa.pop_back();
        }
        Lenguaje_.insert(cadena);
      }
    }
  }
}

std::ostream& Lenguaje::write(std::ostream& os){
  os  << "{ ";
  for (auto i = this -> Lenguaje_.begin();
       i != this -> Lenguaje_.end(); 
       i++ ) {
    std::string linea;
    linea = (*i);
    os << linea << ", ";
  }
  os<< " }";
  return os;
}

void Lenguaje::Inversa() {
  std::set<std::string> Inverso;
  for (auto i = this -> Lenguaje_.begin();
       i != this -> Lenguaje_.end(); 
       i++ ) {
    std::string cadenainvertida = "";
    std::string cadena = (*i);
    while (!cadena.empty()) {
      cadenainvertida += cadena.back();
      cadena.pop_back();
    }
    Inverso.insert(cadenainvertida);
  }
  Lenguaje_= Inverso;
}

std::set<std::string> Lenguaje::Concatenacion(Lenguaje SegundoLenguaje) {
  std::set<std::string> Concatenacion;
  for (auto i = this -> Lenguaje_.begin();
       i != this -> Lenguaje_.end(); 
       i++ ) {
    for (auto j = SegundoLenguaje.getset().begin();
         j != SegundoLenguaje.getset().end(); 
         j++ ) {
      std::string cadenaL1 =(*i);
      std::string cadenaL2 =(*j);
      if (cadenaL1 == "&") {
        Concatenacion.insert(cadenaL2);
      } else {   
        if(cadenaL2 == "&") {
        Concatenacion.insert(cadenaL1);
        } else { 
          std::string cadenaconcatenada = cadenaL1 + cadenaL2;
           Concatenacion.insert(cadenaconcatenada);
        }
      }
    }
  }
  return Concatenacion;
}

std::set<std::string> Lenguaje::Potencia( unsigned Repeticiones){
  std::set<std::string> Potencia;
  if (Repeticiones == 0) {
    std::string cadenavacia;
    cadenavacia = "&";
    Potencia.insert(cadenavacia);    
  }else if (Repeticiones == 1) {
      return this->Lenguaje_;
    } else {
      Lenguaje  Resultadorecursivo;
      Resultadorecursivo.getset() = this->Potencia(Repeticiones - 1);
      Potencia = this -> Concatenacion(Resultadorecursivo);
    }
  return Potencia;
}


void Lenguaje::Cierre_positivo(std::ostream &os){
  std::set<std::string> cierre;
  std::set<std::string> concatenacion;
  cierre = Lenguaje_;
  unsigned repeticion = 1;
  unsigned misize = 1;
  while( misize < 3 ){
    concatenacion = this ->Potencia(repeticion); 
   
    cierre.insert(concatenacion.begin(),concatenacion.end());
    misize++;
    repeticion++;
  }
  os<<"{";
  for ( auto  j = cierre.begin();
        j != cierre.end();
        j++){
    os<<(*j)<<", ";
  }
  os << "...}";
}


void Lenguaje::Cierre_kleene(std::ostream &os){
  std::set<std::string> cierre;
  Lenguaje concatenacion;
  unsigned repeticion = 0;
  while( repeticion < 3 ){
    concatenacion.getset()  = this->Potencia(repeticion); 
    for ( auto i = concatenacion.getset().begin();
          i != concatenacion.getset().end();
          i ++){
      cierre.insert(*i);
    }
    repeticion++;
    
  }
  os<<"{";
  for ( auto  j = cierre.begin();
        j != cierre.end();
        j++){
    os<<(*j)<<", ";
  }
  os << "...}";
} 

bool Lenguaje::SubLenguaje(Lenguaje SegundoLenguaje){
   bool sublenguaje =true;
   bool estadentro = false;
   for ( auto i = SegundoLenguaje.getset().begin();
         i != SegundoLenguaje.getset().end() && sublenguaje;
         i++){
     estadentro=false;
     for(auto j = this -> Lenguaje_.begin();
         j != this -> Lenguaje_.end();
         j++){
        std::string cadena_l1= (*i);
        std::string cadena_l2= (*j);
       if (cadena_l1==cadena_l2){
         estadentro= true;
       }
     }           
     if (!estadentro){
       sublenguaje=false;
     } 
   }
   return sublenguaje;  
}






