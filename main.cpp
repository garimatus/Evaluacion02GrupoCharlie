#include <iostream>
#include <cstdlib>
#include <fstream>
#include <chrono>
#include "funciones.h"


using namespace std;

int main(int argc, char** argv){
	
	int** ponderados, lineas;
	
	if (argc > 3)
	{
		std::string archivo(argv[2]);
		
		std::ifstream lectura("."+archivo);
		std::string ruta(argv[3]);
		
        if (lectura && (std::string) argv[1] == "1")
		{
			auto inicio = chrono::steady_clock::now();
			
			std::cout << "\nArchivo encontrado." << std::endl;
			
			lectura.close();
			
			lineas = contar(archivo);
			
			if(lineas)
			{
				ponderados = new int*[lineas];
				
				universidad utem = ponderar(ponderados, archivo);
				
				heapSort(ponderados, lineas);
				
				postular(utem, ponderados, lineas);
				
				escribir(utem, ruta);
				
				std::cout << "\nArchivos de texto creados en " << ruta << std::endl;
				
				auto fin = chrono::steady_clock::now();
				auto tiempo = chrono::duration_cast<chrono::nanoseconds>(fin - inicio).count();
				
				std::cout << "Se demoro "<< tiempo*(0.000000001) <<"segs ordenar los "<< lineas <<" estudiantes." << std::endl;
			}
			else
			{
				std::cout << "\nEl archivo esta vacio." << std::endl;
				return EXIT_FAILURE;
			}
		}
		else
        {
            std::cout << "\nEl archivo o la ruta especificada no existe." << std::endl;
			return EXIT_FAILURE;
        }
    }
    else
    {
        std::cout << "\nNo hay argumentos suficientes para la lectura." << std::endl;
        participantes();
		return EXIT_FAILURE;
    }
	
	return EXIT_SUCCESS;
}

