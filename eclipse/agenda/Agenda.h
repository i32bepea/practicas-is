/*
 * Agenda.h
 *
 *  Created on: 14/12/2014
 *      Author: cosmic0
 */

#ifndef AGENDA_H_
#define AGENDA_H_
#include "Contacto.h"
#include "GestorCS.h"
#include "GestorCSFichero.h"
#include <list>

class Agenda {
private:
	std::list <Contacto> listaContactos_;
	GestorCS * gestor_;

public:
	Agenda(); //El constructor, vuelca la lista de contactos de agenda.juda si existe.
	virtual ~Agenda();

	bool insertarContacto (const Contacto &c);
	int buscarContacto (const std::string &apellidos);
	int borrarContacto (const std::string &DNI);
	Contacto buscarContactoAux (const std::string &DNI,int * devuelto);
	int modificarContacto (const std::string &DNI);
	bool listarContactos();
	int listarFavoritos();
	void volcado(); //Vuelca la agenda al fichero agenda.juda

	const std::list<Contacto>& getListaContactos() const {
		return listaContactos_;
	}

	void setListaContactos(const std::list<Contacto>& listaContactos) {
		listaContactos_ = listaContactos;
	}

	GestorCS* getGestor(){
		return gestor_;
	}

	void setGestor(GestorCS* gestor) {
		gestor_ = gestor;
	}
};


#endif /* AGENDA_H_ */
