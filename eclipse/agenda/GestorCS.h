/*
 * GestorCS.h
 *
 *  Created on: 9/1/2015
 *      Author: cosmic0
 */

#ifndef GESTORCS_H_
#define GESTORCS_H_
#include <string>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include "Agenda.h"
#include "Contacto.h"

class GestorCS {
public:

	bool realizarCopia(Agenda a);
	bool restaurarCopia (std::string nombre);
	bool borrarCopia (std::string nombre);
	bool listarCopia ();

	GestorCS();
	virtual ~GestorCS();
};

#endif /* GESTORCS_H_ */
