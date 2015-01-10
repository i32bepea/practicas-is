#ifndef MENU_H_
#define MENU_H_
#include "Agenda.h"
class Menu {

private:

	Agenda a_;

public:


	void insertarContacto(); //Se tiene que realizar un cin para rellenar los datos y pasarlo a la función insertarContacto.
	void buscarContacto(); //Pedirle que introduzca los apellidos del contacto y llamar a la función buscarContacto de agenda.
	void borrarContacto(); //Pide por pantalla los apellidos, se muestran los contactos encontrados con buscarContacto, y se llama a la función borrarContacto de agenda habiendole pedido antes que introduzca el DNI.
	void modificarContacto(); //Llama a la función de modificarContacto de agenda.
	void listar(); //Tiene que listar todos los contactos y dar la posibilidad de ir hacia atrás.
	void seguridad(); //Tiene que mostrar el menú de seguridad y llamar a las respectivas funciones.
	void mostrarMenu(); //Esta función muestra el menú.
	void salir(); //Esta función se encargará de gestionar la salida de la aplicación, creando el fichero agenda.juda que guardará todos los cambios hechos durante la ejecución. En este caso los cambios están en una lista de contactos y es esta la que hay que añadir y ordenar.

	Menu(); //Tiene que cargar todos los contactos del fichero en la lista de agenda.
	virtual ~Menu();

	const Agenda& getA() const {
		return a_;
	}

	void setA(const Agenda& a) {
		this->a_ = a;
	}
};

#endif /* MENU_H_ */
