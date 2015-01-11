/*
 * GestorCSFichero.h
 *
 *  Created on: 09/01/2015
 *      Author: alvaro
 */

#ifndef GESTORCSFICHERO_H_
#define GESTORCSFICHERO_H_

#include "GestorCS.h"
#include <string>
#include <vector>
#include <iostream>

class GestorCSFichero: public GestorCS {

private:

	std::vector <std::string> copiasSeguridad_;

public:

	bool realizarCopia();								//Realiza copia de seguridad,copiamos agenda.juda en directorio CS, su nombre pasará a ser la hora local
	bool restaurarCopia (std::string nombre);		//Restaura copia de seguridad elegida del directorio CS.
	bool borrarCopia (std::string nombre);			//Borra la copia de seguridad elegida del directorio CS.
	bool listarCopia ();									//Recorre el vector de copiasSegurida_ y muestra por pantalla.
	void volcar();											//Vuelca el contenido de copiasSeguridad_ en un fichero llamado CopiasSeguridad.juda situado en el directorio principal.
	void lectura();										//Vuelca la información del fichero CopiasSeguridad.juda en el vector copiasSeguridad_.

	GestorCSFichero(){};
	virtual ~GestorCSFichero() {};

	const std::vector<std::string>& getCopiasSeguridad() const {
		return copiasSeguridad_;
	}

	void setCopiasSeguridad(const std::vector<std::string>& copiasSeguridad) {
		copiasSeguridad_ = copiasSeguridad;
	}
};

#endif /* GESTORCSFICHERO_H_ */
