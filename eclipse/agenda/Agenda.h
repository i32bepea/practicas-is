/*
 * Agenda.h
 *
 *  Created on: 14/12/2014
 *      Author: cosmic0
 */

#ifndef AGENDA_H_
#define AGENDA_H_
#include "Contacto.h"
#include <list>

class Agenda {
private:
	std::list <Contacto> listaContactos_;

public:
	Agenda();
	virtual ~Agenda();


	bool insertarContacto (const Contacto &c);
	int buscarContacto (const std::string &apellidos);
	int Agenda::borrarContacto (const std::string &DNI);
	Contacto * Agenda::buscarContactoAux (const std::string &apellidos,int * devuelto);//La misma función que buscarContacto con la diferencia de que busca por DNI, devuelve un puntero hacia el contacto y no lo imprime.
	int modificarContacto (const std::string &DNI);
	bool listarContactos();
	bool listarFavoritos();
	bool listarMasUsados();
	void imprimirContacto (const Contacto &c);

	const std::list<Contacto>& getListaContactos() const {
		return listaContactos_;
	}

	void setListaContactos(const std::list<Contacto>& listaContactos) {
		listaContactos_ = listaContactos;
	}
	bool realizarCopia();
	bool restaurarCopia (std::string nombre);
};


#endif /* AGENDA_H_ */
