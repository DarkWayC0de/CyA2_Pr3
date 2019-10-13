//
//Archivo: Calculadora.cpp
//Fecha: 05/10/2019
//Autor: Diego Cruz Rodríguez
//Titulo: Práctica 3 de Computabilidad y Algoritmia
//Uso del archivo: Implentacion de la funicon main y analisis de los argumentos
//
#include <iostream>
#include <fstream>
#include <string>
#include <iterator>
#include <algorithm>
#include "Lenguaje.h"


int main (int argc, char *argv[]){
  switch (argc) {
    case 4 : {
      std::string namedoc;
      namedoc = argv[1];
      std::ifstream readfile (namedoc);
      namedoc = argv[2];
      std::ofstream writefile (namedoc);
      std::string linea;
      std::string opciones = argv[3];
      int opcion = std::stoi (opciones);
      if(readfile.is_open() && writefile.is_open()){
        switch(opcion){
          case 1 :{     
            while(!readfile.eof()) {
              std::getline(readfile,linea);
              Lenguaje Primerlenguaje;
              Primerlenguaje.read(linea);
              if(!readfile.eof()){
                std::getline(readfile,linea);
                Lenguaje Segundolenguaje;
                Segundolenguaje.read(linea);
                Lenguaje lenguajeResultante;
                lenguajeResultante.getset() = Primerlenguaje.Concatenacion(Segundolenguaje);
                lenguajeResultante.write(writefile);
                writefile<<"\n";
              }
            }
            }
            break;
          case 2 : { //Union
            while (!readfile.eof()) {
              std::getline(readfile,linea);
              Lenguaje Primerlenguaje;
              Primerlenguaje.read(linea);
              if(!readfile.eof()){
                std::getline(readfile,linea);
                Lenguaje Segundolenguaje;
                Segundolenguaje.read(linea);
                writefile<<"{";
                std::ostream_iterator<std::string> iterator(writefile,", ");
                std::set_union(Primerlenguaje.getset().begin(),
                               Primerlenguaje.getset().end(),
                               Segundolenguaje.getset().begin(),
                               Segundolenguaje.getset().end(),
                               iterator);
                writefile<<"}\n";
              }
            }
            }
            break;
          case 3 : { //Intercepcion
            while (!readfile.eof()) {
              std::getline(readfile,linea);
              Lenguaje Primerlenguaje;
              Primerlenguaje.read(linea);
              if(!readfile.eof()){
                std::getline(readfile,linea);
                Lenguaje Segundolenguaje;
                Segundolenguaje.read(linea);
                writefile<<"{";
                std::ostream_iterator<std::string> iterator(writefile,", ");
                std::set_intersection(Primerlenguaje.getset().begin(),
                                      Primerlenguaje.getset().end(),
                                      Segundolenguaje.getset().begin(),
                                      Segundolenguaje.getset().end(),
                                      iterator);
                writefile<<"}\n";
              }
            }
            }
            break;
          case 4 : { //Diferencia
            while(!readfile.eof()) {
              std::getline(readfile,linea);
              Lenguaje Primerlenguaje;
              Primerlenguaje.read(linea);
              if(!readfile.eof()){
                std::getline(readfile,linea);
                Lenguaje Segundolenguaje;
                Segundolenguaje.read(linea);
                writefile<<"{";
                std::ostream_iterator<std::string> iterator(writefile,", ");
                std::set_difference(Primerlenguaje.getset().begin(),
                                    Primerlenguaje.getset().end(),
                                    Segundolenguaje.getset().begin(),
                                    Segundolenguaje.getset().end(),
                                    iterator);
                writefile<<"}\n";
              } 
            }
            }  
            break;
          case 5 : //  Sublenguajes
            while (!readfile.eof()) {
              std::getline(readfile,linea);
              Lenguaje Primerlenguaje;
              Primerlenguaje.read(linea);
              if(!readfile.eof()){
                std::getline(readfile,linea);
                Lenguaje Segundolenguaje;
                Segundolenguaje.read(linea);
                if (Primerlenguaje.SubLenguaje(Segundolenguaje)){
                 writefile<<"True\n";
                } else {
                 writefile<<"False\n";
                }
               }
               }
            break;
          case 6 : // Igualdad de lenguajes
            while(!readfile.eof()) {
              std::getline(readfile,linea);
              Lenguaje Primerlenguaje;
              Primerlenguaje.read(linea);
              if(!readfile.eof()){
                std::getline(readfile,linea);
                Lenguaje Segundolenguaje;
                Segundolenguaje.read(linea);
		if (Primerlenguaje.SubLenguaje(Segundolenguaje) &&
                    Segundolenguaje.SubLenguaje(Primerlenguaje)){
                 writefile<<"True\n";
                } else {
                 writefile<<"False\n";
                }
               }
               }
            break;
          case 7 : { //Inversa
            while(!readfile.eof()) {
              std::getline(readfile,linea);
              Lenguaje Primerlenguaje;
              Primerlenguaje.read(linea);
              Primerlenguaje.Inversa();
              Primerlenguaje.write(writefile);
              writefile<<"\n";
            }
            }
            break;
          case 9 : { //Cierre positivo
            while(!readfile.eof()) {
              std::getline(readfile,linea);
              Lenguaje Primerlenguaje;
              Primerlenguaje.read(linea);
              Primerlenguaje.Cierre_positivo(writefile);
              writefile<<"\n";
            }
            }
            break;
          case 10 : {  // Cierre de Kleene
            while(!readfile.eof()) {
              std::getline(readfile,linea);
              Lenguaje Primerlenguaje;
              Primerlenguaje.read(linea);
              Primerlenguaje.Cierre_kleene(writefile);
              writefile<<"\n";
            }
            }
            break;

        }
      writefile.close();
      readfile.close();
      } else {
        std::cout<<"\nERROR, apertura de archivo.\n";
      }
      break;
      }
    case 5 : {
        std::string namedoc;
        namedoc = argv[1];
        std::ifstream readfile (namedoc);
        namedoc = argv[2];
        std::ofstream writefile (namedoc);
        std::string linea;
      if ( *argv[3] == 49  ) {
        int cantidad_operacion = std::stoi(argv[4]);
        while (!readfile.eof()){
          Lenguaje Primer_lenguaje;
          std::getline(readfile,linea);
          Primer_lenguaje.read(linea);
          for(int i =0; i < cantidad_operacion && !readfile.eof(); i++){
            Lenguaje Segundo_lenguaje;
            std::getline(readfile,linea);
            Segundo_lenguaje.read(linea);
            Primer_lenguaje.getset() = Primer_lenguaje.Concatenacion(Segundo_lenguaje);           
          }
          if (!readfile.eof()){
                Primer_lenguaje.write(writefile);
                writefile<<"\n"; 
          }
        }
        break;
      }  
      if ( *argv[3] == 56  ) { //Potencia
        while (!readfile.eof()) {
          std::getline(readfile,linea);
          Lenguaje Primerlenguaje;
          Primerlenguaje.read(linea);
          Lenguaje Resultado;
          std::string numero = argv[4]; 
          unsigned repeticiones = std::stoi(numero);
          Resultado.getset() = Primerlenguaje.Potencia( repeticiones);
          Resultado.write(writefile);
          writefile<<"\n";
        }
      break;
      }
      writefile.close();
      readfile.close();
      }
    default:
      std::cout << "Comando desconocido.\n\n"<<
                   "-------------------------------------------------------\n"<<
                   "Para el correcto funcionamiento del programa se tiene \n"
                   "que usar el siguiente comando \"./Calculadora\" seguido\n"<<
                   "de el archivo de entrada de datos, el fichero de salida\n"<<
                   "y el codigo de operacion.\n\n"<<
                   "Codigos.\n"<<
                   "1. Concatenacion\n"<<
                   "2. Union\n"<<
                   "3. Innterseccion\n"<<
                   "4. Diferencia\n"<<
                   "5. Sublenguaje\n"<<
                   "6. Igualdad de lenguajes\n"<<
                   "7. Inversa\n"<<
                   "8. Potencia\n"<<
                   "9. Cierre positivo\n"<<
                   "10. Cierre de Kleene\n\n"<<
                   "Tras el codigo de potencia se añadira el numero de ella\n"<<
                   "-------------------------------------------------------\n"<<
                   "Ejemplos de uso.\n"<<
                   "./Calculadora doc_entrada doc_salida codigo \n"
                   "-------------------------------------------------------\n";
  }
}
