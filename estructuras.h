#ifndef ESTRUCTURAS_H
#define ESTRUCTURAS_H

#include <iostream>
#include <string>


typedef struct carrera{
	const char* nombre;
	int codigo;
	float ponderaciones[5];
	int vacantes;
	double primero;
	double ultimo;
	int** mechones;
	bool disponibilidad;
};

typedef struct universidad{
	const char* nombre;
	carrera* oferta;
	int carreras;
	bool disponibilidad;
};


#endif /* ESTRUCTURAS_H */

