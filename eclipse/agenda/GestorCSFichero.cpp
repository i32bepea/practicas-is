/*
 * GestorCSFichero.cpp
 *
 *  Created on: 09/01/2015
 *      Author: alvaro
 */

#include "GestorCSFichero.h"
#include <string>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include "Agenda.h"
#include "Contacto.h"


bool GestorCSFichero::realizarCopia (){ //Realiza una copia de agenda.juda a /CS/fechaYhora.juda Para ello tiene que volcar los datos existentes de Agenda a agenda.juda

	//Volcamos los datos de la agenda a el fichero agenda.juda para poder realizar la copia de seguridad.
	//PROCESO DE COPIA de seguridad de agenda.juda

	system("mkdir CS");

	time_t tiempo = time(0);
    struct tm *tlocal = localtime(&tiempo);
    char salida[128];
    strftime(salida,128,"%d.%m.%y-%H:%M:%S",tlocal);

    std::string output(salida);
    std::string cadena="cp agenda.juda ./CS/" + output + ".juda";

	if(system(cadena.c_str())==-1){//Error al ejecutar la orden
		return false;
	}
	else{
		return true;
	}
}

bool GestorCSFichero::restaurarCopia (std::string nombre){ // Restaura la copia de seguridad indicada en string nombre, tiene que venir con la extensión, y las comprobaciones de que exista las hace la función.

	std::string cadena="./CS/" + nombre;
	std:: ifstream f (cadena.c_str());
	if (f.is_open()){

		f.close();

		if(system("rm agenda.juda")==-1)
				return false;

		cadena= "cp " + cadena + "agenda.juda";
		if(system(cadena.c_str())==-1){
			return false;
		}
		else
			return true;
	}

	else{
		f.close();
		return false; //No existe el archivo del que restaurar la copia.
	}
}

bool GestorCSFichero::borrarCopia (std::string nombre){ // Borra la copia de seguridad indicada en string nombre, tiene que venir con la extensión, y las comprobaciones de que exista las hace la función.
	std::string cadena;//="./CS/" + nombre;
	std:: ifstream f (cadena.c_str());
	//if (f.is_open()){

	//	f.close();

		cadena= "rm  " + nombre;

		if(system(cadena.c_str())==-1)
			return false;

		else
			return true;
	//   }
	//  else{
	//	  f.close();
	//	  return false; //No existe la copia de seguridad que hay que borrar.
	 // }
}
bool GestorCSFichero::listarCopia (){ // Borra la copia de seguridad indicada en string nombre, tiene que venir con la extensión, y las comprobaciones de que exista las hace la función.
	if(system("ls CP")==-1)
		return false;
	else
		return true;
}
