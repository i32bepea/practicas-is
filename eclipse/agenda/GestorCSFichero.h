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

	bool realizarCopia();
	bool restaurarCopia (std::string nombre);
	bool borrarCopia (std::string nombre);
	bool listarCopia ();
	void volcar();
	void lectura();
	void borrarElemento(const int &pos);

	GestorCSFichero(){};
	virtual ~GestorCSFichero() {
	}

	const std::vector<std::string>& getCopiasSeguridad() const {
		return copiasSeguridad_;
	}

	void setCopiasSeguridad(const std::vector<std::string>& copiasSeguridad) {
		copiasSeguridad_ = copiasSeguridad;
	}
};

#endif /* GESTORCSFICHERO_H_ */
