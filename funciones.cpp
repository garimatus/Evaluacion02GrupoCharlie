#include <iostream>
#include <sstream>
#include <fstream>
#include <cstring>
#include <math.h>

#include "funciones.h"


using namespace std;

void participantes() {
    std::cout << std::endl << "=== Analisis de Algoritmos: Evaluacion 02 ===" << std::endl;
    std::cout << std::endl << "Profesor : Sebastian Salazar M.\n";
	std::cout << std::endl << "Integrantes : ";
	std::cout << std::endl << "Edgar Matus";
    std::cout << std::endl << "Oscar Penaloza";
    std::cout << std::endl << "Daniela Galleguillos" << std::endl;
}

int contar(std::istream& archivo){
	int l = 0;
	for(std::string linea; getline(archivo, linea); l++){}
	return l;
}

int* obtenerPuntajes(std::string fila){
    int* arreglo = new int[7], i = 0;
    std::stringstream ss(fila);
    std::string item;

	while (getline(ss, item, ';')) {
		int valor = atoi(item.c_str());
		arreglo[i] = valor;
		i++;
	}
	
	return arreglo;
}

double ponderar(int* puntajes, carrera opcion){
	
	return (double)(puntajes[1]*opcion.ponderaciones[0])+
			(double)(puntajes[2]*opcion.ponderaciones[1])+
			(double)(puntajes[3]*opcion.ponderaciones[3])+
			(double)(puntajes[4]*opcion.ponderaciones[2])+
			(double)(puntajes[5]*opcion.ponderaciones[4]);
}

universidad ponderar(int** ponderados, std::istream& archivo){
	
	universidad U = {"Universidad Tecnologica Metropolitana UTEM", new carrera[28], 28, true};
	
	U.oferta[0] = { "Ing. en Biotecnologia", 21073, {0.15, 0.25, 0.20, 0.30, 0.10}, 60, 675.8, 540.9, new int*[60], true };
	U.oferta[1] = { "Ing. Civil en Ciencia de Datos", 21049, {0.10, 0.25, 0.20, 0.35, 0.10}, 60, 673.65, 539.35, new int*[60], true };
	U.oferta[2] = { "Ing. Civil en Computacion", 21041, {0.10, 0.25, 0.20, 0.35, 0.10}, 130, 673.65, 539.35, new int*[130], true };
	U.oferta[3] = { "Arquitectura", 21047, {0.15, 0.25, 0.20, 0.20, 0.20}, 100, 640.2, 527.4, new int*[100], true };
	U.oferta[4] = { "Administracion Publica", 21089, {0.15, 0.20, 0.30, 0.25, 0.10}, 35, 625.8, 513, new int*[35], true };
	U.oferta[5] = { "Trabajo Social", 21043, {0.20, 0.30, 0.20, 0.10, 0.20}, 95, 705.9, 510.5, new int*[95], true };
	U.oferta[6] = { "Ing. Informatica", 21030, {0.10, 0.25, 0.20, 0.35, 0.10}, 105, 705.15, 507.75, new int*[105], true };
	U.oferta[7] = { "Ing. Civil Mecanica", 21096, {0.10, 0.25, 0.20, 0.35, 0.10}, 90, 697.65, 506.8, new int*[90], true };
	U.oferta[8] = { "Ing. Bachillerato", 21046, {0.10, 0.25, 0.20, 0.35, 0.10}, 25, 586.45, 504.25, new int*[25], true };
	U.oferta[9] = { "Ing. Civil Industrial", 21076, {0.10, 0.25, 0.20, 0.35, 0.10}, 200, 671.25, 500.85, new int*[200], true };
	U.oferta[10] = { "Ing. Civil Electronica", 21075, {0.10, 0.25, 0.20, 0.35, 0.10}, 80, 657.35, 500.65, new int*[80], true };
	U.oferta[11] = { "Ing. Comercial", 21048, {0.10, 0.20, 0.30, 0.30, 0.10}, 125, 652.9, 496.9, new int*[125], true };
	U.oferta[12] = { "Dibujante Proyectista", 21071, {0.10, 0.25, 0.20, 0.35, 0.10}, 25, 689.85, 496.45, new int*[25], true };
	U.oferta[13] = { "Ing. Geomensura", 21031, {0.10, 0.25, 0.20, 0.35, 0.10}, 60, 614.3, 487.85, new int*[60], true };
	U.oferta[14] = { "Ing. Construccion", 21032, {0.20, 0.20, 0.15, 0.35, 0.10}, 100, 716.3, 476.95, new int*[100], true };
	U.oferta[15] = { "Ing. Industrial", 21045, {0.10, 0.25, 0.20, 0.35, 0.10}, 60, 584.75, 476.25, new int*[60], true };
	U.oferta[16] = { "Ing. Civil Obras Civiles", 21074, {0.20, 0.20, 0.15, 0.35, 0.10}, 100, 625, 476.1, new int*[100], true };
	U.oferta[17] = { "Quimica Industrial", 21083, {0.10, 0.25, 0.15, 0.30, 0.20}, 40, 596.05, 472, new int*[40], true };
	U.oferta[18] = { "Ing. Industria Alimentaria", 21039, {0.15, 0.25, 0.20, 0.30, 0.10}, 30, 680.2, 464.9, new int*[30], true };
	U.oferta[19] = { "Ing. Civil Prevencion de Riesgos Y Medioambiente", 21087, {0.15, 0.35, 0.20, 0.20, 0.10}, 30, 615.2, 462.85, new int*[30], true };
	U.oferta[20] = { "Ing. Administracion Agroindustrial", 21015, {0.10, 0.20, 0.30, 0.30, 0.10}, 30, 628.8, 461.8, new int*[30], true };
	U.oferta[21] = { "Ing. Comercio Internacional", 21081, {0.10, 0.20, 0.30, 0.30, 0.10}, 90, 637.2, 458.8, new int*[90], true };
	U.oferta[22] = { "Biotecnologia y Documentacion", 21002, {0.20, 0.20, 0.40, 0.10, 0.10}, 35, 675.3, 453.6, new int*[35], true };
	U.oferta[23] = { "Contador Publico Auditor", 21012, {0.20, 0.20, 0.30, 0.15, 0.15}, 80, 635.55, 452.2, new int*[80], true };
	U.oferta[24] = { "Ing. Quimica", 21080, {0.10, 0.25, 0.15, 0.30, 0.20}, 80, 606.55, 451.7, new int*[80], true };
	U.oferta[25] = { "Ing. Gestion Turistica", 21082, {0.10, 0.20, 0.30, 0.30, 0.10}, 25, 659.4, 448.1, new int*[25], true };
	U.oferta[26] = { "Diseno Comunicacion Audiovisual", 21024, {0.10, 0.40, 0.30, 0.10, 0.10}, 100, 706.3, 440.2, new int*[100], true };
	U.oferta[27] = { "Diseno Industrial", 21023, {0.10, 0.40, 0.30, 0.10, 0.10}, 65, 642.2, 439.9, new int*[65], true };
	
	int i = 0, n = U.carreras;
	
	for (std::string linea; std::getline(archivo, linea); i++)
	{
		double mejor = 0.0;
		
		int* puntajes = obtenerPuntajes(linea);
		
		ponderados[i] = new int[8];
		ponderados[i][0] = puntajes[0]; // <- rut
		ponderados[i][1] = puntajes[1]; // <- NEM
		ponderados[i][2] = puntajes[2]; // <- ranking
		ponderados[i][3] = puntajes[3]; // <- matematica
		ponderados[i][4] = puntajes[4]; // <- lenguaje
		ponderados[i][5] = puntajes[5]; // <- ciencias
		ponderados[i][6] = 0; // <- mejor ponderacion
		ponderados[i][7] = 0; // <- codigo carrera

		for (int j = 0; j < n; j++)
		{
			if ((puntajes[3]+puntajes[4]) / (double) 2.0 >= 450.0 )
			{
				double ponderacion = ponderar(puntajes, U.oferta[j]);
		
				if (ponderacion > (double) U.oferta[j].ultimo && ponderacion > mejor)
				{
					mejor = ponderacion;
					ponderados[i][6] = (int)round(ponderacion);
					ponderados[i][7] = U.oferta[j].codigo;
				}
			}
		}	
	}
	
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < U.oferta[i].vacantes; j++)
		{
			U.oferta[i].mechones[j] = new int[2];
			U.oferta[i].mechones[j][0] = 0;
			U.oferta[i].mechones[j][1] = 0;
		}
	}
	
	return U;
}

void heapify(int** arr, int n, int i) { 
    int smallest = i; // Initialize smalles as root 
    int l = 2 * i + 1; // left = 2*i + 1 
    int r = 2 * i + 2; // right = 2*i + 2 
  
    // If left child is smaller than root 
    if (l < n && arr[l][6] < arr[smallest][6])
        smallest = l; 
  
    // If right child is smaller than smallest so far 
    if (r < n && arr[r][6] < arr[smallest][6])
        smallest = r; 
  
    // If smallest is not root 
    if (smallest != i) { 
        swap(arr[i], arr[smallest]);
  
        // Recursively heapify the affected sub-tree 
        heapify(arr, n, smallest);
    } 
} 

void heapSort(int** arr, int n) { 
    // Build heap (rearrange array) 
    for (int i = n / 2 - 1; i >= 0; i--) 
        heapify(arr, n, i); 
  
    // One by one extract an element from heap 
    for (int i = n - 1; i >= 0; i--) { 
        // Move current root to end 
        swap(arr[0], arr[i]);
  
        // call max heapify on the reduced heap 
        heapify(arr, i, 0); 
    } 
}

bool cupo(carrera* opciones){
	if(opciones[0].disponibilidad == false &&
	opciones[1].disponibilidad == false &&
	opciones[2].disponibilidad == false &&
	opciones[3].disponibilidad == false &&
	opciones[4].disponibilidad == false &&
	opciones[5].disponibilidad == false &&
	opciones[6].disponibilidad == false &&
	opciones[7].disponibilidad == false &&
	opciones[8].disponibilidad == false &&
	opciones[9].disponibilidad == false &&
	opciones[10].disponibilidad == false &&
	opciones[11].disponibilidad == false &&
	opciones[12].disponibilidad == false &&
	opciones[13].disponibilidad == false &&
	opciones[14].disponibilidad == false &&
	opciones[15].disponibilidad == false &&
	opciones[16].disponibilidad == false &&
	opciones[17].disponibilidad == false &&
	opciones[18].disponibilidad == false &&
	opciones[19].disponibilidad == false &&
	opciones[20].disponibilidad == false &&
	opciones[21].disponibilidad == false &&
	opciones[22].disponibilidad == false &&
	opciones[23].disponibilidad == false &&
	opciones[24].disponibilidad == false &&
	opciones[25].disponibilidad == false &&
	opciones[26].disponibilidad == false &&
	opciones[27].disponibilidad == false)
	{
		return false;
	}
	else
	{
		return true;
	}
}

void almacenar(int* postulante, carrera* opciones, int index){
	
	for(int i = 0; i < opciones[index].vacantes; i++)
	{
		if(opciones[index].mechones[i][0] == 0)
		{
			opciones[index].mechones[i][0] = postulante[0]; // <- rut
			opciones[index].mechones[i][1] = postulante[6]; // <- ponderacion
			
			if(i == opciones[index].vacantes - 1)
			{
				opciones[index].disponibilidad = false;
			}
			
			break;
		}
	}
}

void postular(universidad U, int** ponderados, int estudiantes){
	
	int n = U.carreras;
	
	for(int i = 0; i < estudiantes; i++)
	{
		U.disponibilidad = cupo(U.oferta);
		
		if(U.disponibilidad == true)
		{
			int* postulante = ponderados[i];
		
			for(int j = 0; j < n; j++)
			{
				if(postulante[7] == U.oferta[j].codigo)
				{
					if(U.oferta[j].disponibilidad == true)
					{
						almacenar(postulante, U.oferta, j);
					}
					else
					{
						double mejor2 = 0;
						int posicion;
						
						for(int k = 0; k < n; k++)
						{
							if(U.oferta[k].disponibilidad == true)
							{
								double ponderacion2 = ponderar(postulante, U.oferta[k]);
							
								if(ponderacion2 >= mejor2)
								{
									posicion = k;
									mejor2 = ponderacion2;
								}
							}
						}
						
						postulante[6] = (int)round(mejor2);
						
						almacenar(postulante, U.oferta, posicion);
					}
				}
			}
		}
		else
		{
			break;
		}
	}
}

void escribir(universidad U, std::string ruta){
	
	std::ofstream escritura;
	
	for(int i = 0; i < U.carreras; i++)
	{
		std::string archivo = std::to_string(U.oferta[i].codigo);
		
		escritura.open(ruta+"/"+archivo+".txt");
		
		if(escritura.is_open())
		{
			for(int j = 0; j < U.oferta[i].vacantes; j++)
			{
				std::string salida = std::to_string(U.oferta[i].mechones[j][0])+";"+std::to_string(U.oferta[i].mechones[j][1]);
				escritura << salida << std::endl;
			}
			
			escritura.close();
		}
	}
}

std::string buscar(std::string ruta, std::string rut){
	
	std::ifstream lectura;
	
	std::string busqueda = "\nNo se ha encontrado el estudiante del rut ingresado.";
	
	bool existen = false;
	
	const char* archivos[28] = {
	"21073.txt","21049.txt","21041.txt","21047.txt","21089.txt","21043.txt","21030.txt",
	"21096.txt","21046.txt","21076.txt","21075.txt","21048.txt","21071.txt","21031.txt",
	"21032.txt","21045.txt","21074.txt","21083.txt","21039.txt","21087.txt","21015.txt",
	"21081.txt","21002.txt","21012.txt","21080.txt","21082.txt","21024.txt","21023.txt"};
	
	int n = sizeof(archivos) / sizeof(archivos[0]);
	
	for(int i = 0; i < n; i++)
	{
		lectura.open("."+ruta+archivos[i]);
		
		if(lectura.is_open())
		{
			
			if(existen == false)
			{
				existen = true;
			}
			
			int j = 0;
		
			for(std::string linea; std::getline(lectura, linea); j++)
			{
				int k = 0;
				std::string aux[2], item;
				std::stringstream ss(linea);
				
				while(getline(ss, item, ';'))
				{
					aux[k] = item.c_str();
					k++;
				}
				
				if(rut == aux[0])
				{
					busqueda = "\nEstudiante encontrado en la linea "+std::to_string(j+1)+" del archivo "+"."+ruta+archivos[i];
					
					lectura.close();
					break;
				}
			}
		}
		
		lectura.close();
	}
	
	if(existen == false)
	{
		busqueda = "\nNo se ha encontrado ningun archivo en la ruta especificada.";
	}
	
	return busqueda;
}