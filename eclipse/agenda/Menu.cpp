/*
 * Menu.cpp
 *
 *  Created on: 9/1/2015
 *      Author: cosmic0
 */

#include "Menu.h"

void Menu::mostrarMenu(){

	std::cout<<"1. Insertar contacto.\n2. Buscar contacto.\n3. Borrar contacto.\n4. Modificar contacto.\n5. Mostrar todos los contactos de la agenda.\n6. Seguridad.\n7. Salir.\n";

}
void Menu::salir(){

	agenda_.volcado(); //Vuelca el contenido de la agenda a agenda.juda

}

void Menu::seguridad(){
	agenda_.volcado();


}

Menu::Menu() {
	// TODO Auto-generated constructor stub

}

Menu::~Menu() {
	// TODO Auto-generated destructor stub
}

