/*
 * GestorCS.h
 *
 *  Created on: 9/1/2015
 *      Author: cosmic0
 */

#ifndef GESTORCSFICHERO_H_
#define GESTORCSFICHERO_H_

#include <string>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include "Agenda.h"
#include "Contacto.h"

class GestorCSFichero: public GestorCS {
public:

	bool realizarCopia();
	bool restaurarCopia (std::string nombre);
	bool borrarCopia (std::string nombre);
	bool listarCopia ();

	GestorCSFichero();
	virtual ~GestorCSFichero();
};

#endif /* GESTORCSFICHERO_H_ */
