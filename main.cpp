#include <iostream>
#include <cstdlib>
#include <fstream>
#include <algorithm>
#include <chrono>
#include "funciones.h"


using namespace std;

int main(int argc, char** argv){
	
	int **ponderados, lineas;
	
	if (argc > 1)
	{
		std::string archivo(argv[2]);
        std::ifstream lectura(archivo);
		std::ofstream escritura(argv[3]);

        if (lectura && (std::string) argv[1] == "1")
		{
			std::cout << "\nArchivo encontrado." << std::endl;
			system("PAUSE");
			
			lectura.close();
			
			lineas = contar(archivo);
			
			if(lineas)
			{
				std::string ruta(argv[3]);
				
				ponderados = new int*[lineas];
				//auto inicio = chrono::steady_clock::now();
				universidad utem = ponderar(ponderados, archivo);
				//auto fin = chrono::steady_clock::now();
				//auto tiempo = chrono::duration_cast<chrono::nanoseconds>(fin - inicio).count();
				//std::cout << "Se demoro "<< tiempo <<"ns ponderar los "<< lineas <<" estudiantes." << std::endl;
				
				heapSort(ponderados, lineas);	
				
				postular(utem, ponderados, lineas);
				
				for(int j = 0; j < utem.carreras; j++)
				{
					delete[] ponderados[j];/*
					std::cout << std::endl;
					std::cout << utem.oferta[j].codigo << " | " << utem.oferta[j].nombre <<" | "<<utem.oferta[j].disponibilidad << std::endl;
					std::cout << std::endl;
					for(int i = 0; i < utem.oferta[j].vacantes; i++)
						std::cout << utem.oferta[j].mechones[i][0] << ";" << utem.oferta[j].mechones[i][1] << std::endl;*/
				}
				delete[] ponderados;
				
				escribir(utem, ruta);
				std::cout << "\nArchivos de textos creados en : " << ruta <<std::endl;
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

