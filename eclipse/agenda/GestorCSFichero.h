/*
 * GestorCSFichero.h
 *
 *  Created on: 09/01/2015
 *      Author: alvaro
 */

#ifndef GESTORCSFICHERO_H_
#define GESTORCSFICHERO_H_

#include "GestorCS.h"

class GestorCSFichero: public GestorCS {
public:

	bool realizarCopia();
	bool restaurarCopia (std::string nombre);
	bool borrarCopia (std::string nombre);
	bool listarCopia ();

	GestorCSFichero(){};
	virtual ~GestorCSFichero(){};
};

#endif /* GESTORCSFICHERO_H_ */
