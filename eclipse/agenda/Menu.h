/*
 * Menu.h
 *
 *  Created on: 9/1/2015
 *      Author: cosmic0
 */

#ifndef MENU_H_
#define MENU_H_
#include "Agenda.h"

class Menu {
private:
	Agenda agenda_;

public:

	void insertarContacto(); 		//Se tiene que realizar un cin para rellenar los datos y pasarlo a la función insertarContacto.
	void buscarContacto(); 			//Pedirle que introduzca los apellidos del contacto y llamar a la función buscarContacto de agenda.
	void borrarContacto(); 			//Pide por pantalla los apellidos, se muestran los contactos encontrados con buscarContacto, y se llama a la función borrarContacto de 										agenda habiendole pedido antes que introduzca el DNI.
	void modificarContacto(); 		//Llama a la función de modificarContacto de agenda.
	void listar(); 					//Tiene que mostrar el menu de listar y llamar a las respectivas funciones.
	void seguridad(); 				//Tiene que mostrar el menú de seguridad y llamar a las respectivas funciones.
	void mostrarMenu();			 	//Esta función muestra las diferentes opciones del menú.
	void salir(); 						//Esta función se encargará de gestionar la salida de la aplicación, Actualizará el fichero agenda.juda.
	void prepararImpersion();		//Esta función llama a prepararImpresion de Agenda
	void confirmar(); 				//Pulsar Enter para salir;

	Menu(); 								
	virtual ~Menu();

	const Agenda& getAgenda() const {
		return agenda_;
	}

	void setAgenda(const Agenda& agenda) {
		agenda_ = agenda;
	}
};

#endif /* MENU_H_ */
