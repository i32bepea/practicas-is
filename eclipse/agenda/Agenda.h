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
	Agenda(); //El constructor llama a leerAgendaJuda.
	virtual ~Agenda();

	bool insertarContacto (const Contacto &c);								   //Inserta Contacto de manera ordenada
	int buscarContacto (const std::string &apellidos);						   //Busca Contacto.
	int borrarContacto (const std::string &DNI);								   //Borra Contacto.
	Contacto buscarContactoAux (const std::string &DNI,int * devuelto);  //Metodo auxiliar que utilizará modificarContacto();
	int modificarContacto (const std::string &DNI);								//Modifica Contacto e introduce de nuevo, por tanto la lista se queda ordenada.
	bool listarContactos();																//Lista todos los contactos.
	int listarFavoritos();																//Lista solo los contactos Favoritos.
	void volcado(); 																		//Vuelca la agenda al fichero agenda.juda.
	void leerAgendaJuda(); 																//Vuelca la información del ficero agenda.juda a la lista.
	void prepararImpresion();															//Crea archivo html.

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
