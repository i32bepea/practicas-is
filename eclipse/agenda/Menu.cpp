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

	int salir=0;
	GestorCS * gestor= agenda_.getGestor();
	GestorCSFichero gestorF;
	gestor=&gestorF;

	while(salir==0){
		std::cout<<"1. Realizar copia de seguridad.\n2. Restaurar copia de seguridad.\n3. Borrar copia de seguridad.\n4. Listar copias de seguridad\n5. Salir.";
		int opt;
		std::cin>>opt;

		switch(opt){

		case 1:{

				if((*gestor).realizarCopia()==true)
					std::cout<<"¡Copia realizada con éxito!";
				else
					std::cout<<"\n¡Error al realizar la copia de seguridad!";

		break;}
		case 2:{
				if((*gestor).listarCopia()==false)
					std::cout<<"\n¡Error al listar las copias de seguridad!";
				else{
					std::cout<<"\nIntroduzca el nombre incluida la extensión, de la copia de seguridad que desea restaurar.";
					std::string cadena;
					std::getline(std::cin,cadena,'\n');

						if((*gestor).restaurarCopia(cadena)==false)
							std::cout<<"¡Error al intentar restaurar la copia de seguridad!";
						else
							std::cout<<"\n¡Copia de seguridad restaurada satisfactoriamente!";
				}


		break;}
		case 3:{
			if((*gestor).listarCopia()==false)
				std::cout<<"\n¡Error al listar las copias de seguridad!";
			else{
				std::cout<<"\nIntroduzca el nombre incluida la extensión, de la copia de seguridad que desea borrar.";
				std::string cadena;
				std::getline(std::cin,cadena,'\n');

					if((*gestor).borrarCopia(cadena)==false)
						std::cout<<"¡Error al intentar borrar la copia de seguridad!";
					else
						std::cout<<"\n¡Copia de seguridad borrada satisfactoriamente!";
			}


		break;}
		case 4:{

			if((*gestor).listarCopia()==false)
				std::cout<<"\n¡Error al listar las copias de seguridad!";

		break;}
		case 5:{
				salir=1;

		break;}

		default:
			std::cout<<"Opción incorrecta!";
		}

	}

}


Menu::Menu() {
	// TODO Auto-generated constructor stub

}

Menu::~Menu() {
	// TODO Auto-generated destructor stub
}

