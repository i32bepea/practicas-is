/*
 * Main.cpp
 *
 *  Created on: 09/01/2015
 *      Author: alvaro
 */

#include "Menu.h"

int main(){

	int opc;

	Menu menuPrincipal;


	do{

		menuPrincipal.mostrarMenu();
		std::cin>>opc;

		switch(opc){

		case 1:

			menuPrincipal.insertarContacto();
			break;

		case 2:

			menuPrincipal.buscarContacto();
			break;

		case 3:

			menuPrincipal.borrarContacto();
			break;

		case 4:

			menuPrincipal.modificarContacto();
			break;

		case 5:

			menuPrincipal.listar();
			break;

		default:
			break;

		}



	}while(opc != 7);








	/*Contacto c;
	Agenda a;
	int temp;
	std::string DNI;
	std::string apellido;

	a.listarContactos();
	std::cin>>c;
	a.insertarContacto(c);
	std::cout<<"---------------------------\n";
	std::cout<<"---------------------------\n";
	a.volcado();

	a.listarContactos();
	std::cout<<"---------------------------\n";

	std::cout<<"Introduce un apellido para buscar: ";
	std::getline(std::cin,apellido,'\n');

	a.buscarContacto(apellido);

	std::cout<<"Introduce un DNI para elegir Contacto: ";
	std::getline(std::cin,DNI,'\n');

	temp = a.modificarContacto(DNI);

	if(temp == 0){
		std::cout<<"No se encuentra el Contacto";
	}
	else if(temp == -1){
		std::cout<<"Has intentado borrar un campo obligatorio";
	}
	else{
		std::cout<<"OK";
	}

	a.volcado();*/











	return 0;
}
