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
	int borrarContacto (const std::string &DNI);
	Contacto buscarContactoAux (const std::string &DNI,int * devuelto);
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

};


#endif /* AGENDA_H_ */
