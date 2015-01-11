/*
 * GestorCSFichero.cpp
 *
 *  Created on: 09/01/2015
 *      Author: alvaro
 */

#include "GestorCSFichero.h"
#include <string>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <iostream>
#include "Agenda.h"
#include "Contacto.h"


bool GestorCSFichero::realizarCopia (){ 


	if(getCopiasSeguridad().size() == 0) 			//Si ya hay elementos en el vector quiere decir que la carpeta ya está creada. no es necesario hacer mkdir.
		system("mkdir CS");

	std::ifstream fichero("agenda.juda");

	if( fichero.is_open()){

		fichero.close();
		time_t tiempo = time(0);
		struct tm *tlocal = localtime(&tiempo);
		char salida[128];
		strftime(salida,128,"%d.%m.%y-%H:%M:%S",tlocal);				//Nuevo nombre del fichero.

		std::string output(salida);
		std::string nombre = output +".juda";								//Nombre que se guardará en el vector


		//Prevenimos que haya dos strings con mismo nombre en el vector, ya que al ser el nombre la hora local
		//se pueden crear dos copias en el mismo segundo

		if(copiasSeguridad_.size() == 0)
			copiasSeguridad_.push_back(nombre);

		else if(copiasSeguridad_.size() >=1 && copiasSeguridad_[copiasSeguridad_.size()-1] != nombre)
			copiasSeguridad_.push_back(nombre);

		std::string cadena="cp agenda.juda ./CS/" + output + ".juda";

		if(system(cadena.c_str())==-1)//Error al ejecutar la orden
			return false;

		else{
			return true;
		}

	}
	else{
		fichero.close();
		return false;
	}
}

bool GestorCSFichero::restaurarCopia (std::string nombre){ 

	std::string cadena="./CS/" + nombre;
	std:: ifstream f (cadena.c_str());
	if (f.is_open()){

		f.close();

		cadena= "cp " + cadena + " agenda.juda";

		if(system(cadena.c_str())==-1){
			return false;
		}
		else{

			return true;
		}
	}

	else{
		f.close();
		return false; //No existe el archivo del que restaurar la copia.
	}
}

bool GestorCSFichero::borrarCopia (std::string nombre){ 

	std::string cadena="./CS/" + nombre;             		//Le concatenamos al nombre el directorio.
	std:: ifstream f (cadena.c_str());

	if (f.is_open()){

		f.close();

		cadena= "rm CS/" + nombre;									//Le concatenamos al nombre la orden borrar archivo y el directorio.

		if(system(cadena.c_str())==-1)							//Fallo el borrar.
			return false;

		else
			return true;												//Todo OK.
	}

	  else{
		  f.close();
		  return false; 												//No existe la copia de seguridad que hay que borrar.
	  	}
}
bool GestorCSFichero::listarCopia (){ 

	if(copiasSeguridad_.size() != 0){

		int i=1;
		std::vector <std::string>::const_iterator it;

		std::cout<<"==============  copias de seguridad  =============="<<std::endl;

		for(it = getCopiasSeguridad().begin(); it != getCopiasSeguridad().end(); i++,it++){
			std::string aux = (*it);
			std::cout<<"\t"<<i<<". "<<aux<<std::endl;
		}

		return true;												//Existe minimo una Copia de Seguridad.

	}
	else
		return false;												//Ninguna Copia de Seguridad.

}

void GestorCSFichero::volcar(){

	std:: ifstream f ("CopiasSeguridad.juda", std::ios::binary);

	if (f.is_open()){

		f.close();
		system("rm CopiasSeguridad.juda"); 												//Eliminamos CopiasSeguridad.juda si esta existe.
	}

	else{

		f.close();																				//No existe por lo que no hay que eliminarla.
	}


	std::ofstream fichero ("CopiasSeguridad.juda", std::ios::binary);

	int size; 																					//Auxiliar donde se guardarán los enteros del contacto, asi como el tamaño de lista y vectores.
	char cad[200];
	std::string nombreCopia;

	size=100793; 																				//Creamos un código de comprobación, para evitar archivos 'corruptos' de agenda.juda.
	fichero.write ((char*) &size, sizeof (int));

	size = getCopiasSeguridad().size();
	fichero.write ((char*) &size, sizeof (int));

	std::vector <std::string>::iterator it;

	for(it = copiasSeguridad_.begin(); it != copiasSeguridad_.end(); it++){

		nombreCopia = (*it);
		strcpy(cad,nombreCopia.c_str());
		fichero.write ((char*) cad, 200*sizeof (char));

	}

}

void GestorCSFichero::lectura(){

	std:: ifstream fichero ("CopiasSeguridad.juda", std::ios::binary);

	if (fichero.is_open()){

		int size; 																//Auxiliar donde se guardarán los enteros del contacto, asi como el tamaño de lista y vectores.
		char cad[200];
		std::vector <std::string> aux;

		fichero.read ((char*) &size, sizeof (int));

		if(size == 100793){													//Comprobamos código.

			fichero.read ((char*) &size, sizeof (int)); 				//Numero de Copias de Seguridad.

			std::vector <std::string>::const_iterator it;

			while(size != 0){

				size--;

				fichero.read ((char*) cad, 200*sizeof(char));
				std::string nombreCopia(cad);

				aux.push_back(nombreCopia);

			}

			setCopiasSeguridad(aux);

		}
	}

	else
		fichero.close();												

}

