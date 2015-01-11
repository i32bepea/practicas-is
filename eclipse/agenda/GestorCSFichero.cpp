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


bool GestorCSFichero::realizarCopia (){ //Realiza una copia de agenda.juda a /CS/fechaYhora.juda Para ello tiene que volcar los datos existentes de Agenda a agenda.juda


	//Volcamos los datos de la agenda a el fichero agenda.juda para poder realizar la copia de seguridad.
		  	  	 //PROCESO DE COPIA de seguridad de agenda.juda
	if(getCopiasSeguridad().size() == 0)
		system("mkdir CS");

	std::ifstream fichero("agenda.juda");

	if( fichero.is_open()){

		fichero.close();
		time_t tiempo = time(0);
		struct tm *tlocal = localtime(&tiempo);
		char salida[128];
		strftime(salida,128,"%d.%m.%y-%H:%M:%S",tlocal);

		std::string output(salida);
		std::string nombre = output +".juda";


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

bool GestorCSFichero::restaurarCopia (std::string nombre){ // Restaura la copia de seguridad indicada en string nombre, tiene que venir con la extensión, y las comprobaciones de que exista las hace la función.

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

bool GestorCSFichero::borrarCopia (std::string nombre){ // Borra la copia de seguridad indicada en string nombre, tiene que venir con la extensión, y las comprobaciones de que exista las hace la función.
	std::string cadena="./CS/" + nombre;
	std:: ifstream f (cadena.c_str());

	if (f.is_open()){

		f.close();

		cadena= "rm CS/" + nombre;

		if(system(cadena.c_str())==-1)
			return false;

		else
			return true;
	}

	  else{
		  f.close();
		  return false; //No existe la copia de seguridad que hay que borrar.
	  	}
}
bool GestorCSFichero::listarCopia (){ // Borra la copia de seguridad indicada en string nombre, tiene que venir con la extensión, y las comprobaciones de que exista las hace la función.

	if(copiasSeguridad_.size() != 0){

		int i=1;
		std::vector <std::string>::const_iterator it;

		std::cout<<"==============  copias de seguridad  =============="<<std::endl;

		for(it = getCopiasSeguridad().begin(); it != getCopiasSeguridad().end(); i++,it++){
			std::string aux = (*it);
			std::cout<<"\t"<<i<<". "<<aux<<std::endl;
		}

		return true;

	}
	else
		return false;

}

void GestorCSFichero::volcar(){

	std:: ifstream f ("CopiasSeguridad.juda", std::ios::binary);

	if (f.is_open()){

		f.close();
		system("rm CopiasSeguridad.juda"); //Eliminamos CopiasSeguridad.juda si esta existe.
	}

	else{

		f.close();//No existe por lo que no hay que eliminarla.
	}


	std::ofstream fichero ("CopiasSeguridad.juda", std::ios::binary);

	int size; //Auxiliar donde se guardarán los enteros del contacto, asi como el tamaño de lista y vectores.
	char cad[200];
	std::string nombreCopia;

	size=100793; //Creamos un código de comprobación, para evitar archivos corruptos de agenda.juda
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

		int size; //Auxiliar donde se guardarán los enteros del contacto, asi como el tamaño de lista y vectores.
		char cad[200];
		std::vector <std::string> aux;

		fichero.read ((char*) &size, sizeof (int));

		if(size == 100793){

			fichero.read ((char*) &size, sizeof (int)); //Numero de Copias de Seguridad;

			std::vector <std::string>::const_iterator it;

			while(size != 0){

				size--;

				fichero.read ((char*) cad, 200*sizeof(char));
				std::string nombreCopia(cad);

				//std::ifstream ficheroAux(nombreCopia.c_str(), std::ios::binary);

				//Comprobamos que el fichero existe;

				//if(ficheroAux.is_open()){
				//	ficheroAux.close();
				aux.push_back(nombreCopia);
				/*}

				else
					ficheroAux.close();*/

			}

			setCopiasSeguridad(aux);

		}
	}

	else
		fichero.close();//No existe por lo que no hay que eliminarla.

}
void GestorCSFichero::borrarElemento(const int &pos){

	std::vector <std::string> v = getCopiasSeguridad();
	std::vector <std::string>::iterator it;
	int i = 0;

	for(it = v.begin(); it != v.end(); it++,i++){

		if(i == (pos-1))
			v.erase(it);

	}

	setCopiasSeguridad(v);
}
