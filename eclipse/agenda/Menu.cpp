#include "Menu.h"
#include "Agenda.h"
#include <iostream>

void Menu::insertarContacto() {

	Contacto aux;
	Agenda a_;

	//std::cin >> aux;

	a_.insertarContacto(aux);
}

void Menu::buscarContacto() {

	Contacto aux;
	Agenda a_;





}












void Menu::mostrarMenu(){

	std::cout<<"1. Insertar contacto.\n2. Buscar contacto.\n3. Borrar contacto.\n4. Modificar contacto.\n5. Mostrar todos los contactos de la agenda.\n6. Seguridad.\n7. Salir.\n";

}

Menu::Menu() {
	// TODO Auto-generated constructor stub

}

Menu::~Menu() {
	// TODO Auto-generated destructor stub
}
