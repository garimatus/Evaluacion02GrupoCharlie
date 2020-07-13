#ifndef FUNCIONES_H
#define FUNCIONES_H

#include "estructuras.h"

void participantes();
int contar(std::istream&);
int* obtenerPuntajes(std::string);
universidad ponderar(int**,std::istream&);
void heapSort(int**,int);
void postular(universidad,int**,int);
void escribir(universidad,std::string);
std::string buscar(std::string,std::string);

#endif /* FUNCIONES_H */

