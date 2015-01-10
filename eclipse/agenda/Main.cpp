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

	return 0;
}
