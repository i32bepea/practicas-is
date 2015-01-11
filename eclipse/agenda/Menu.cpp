/*
 * Menu.cpp
 *
 *  Created on: 9/1/2015
 *      Author: cosmic0
 */


#include "Menu.h"
#include "Agenda.h"
#include <cstdio>
#include <iostream>
#include <string>
#include <cstdlib>

void Menu::mostrarMenu(){

	system("clear");

	std::cout<<"=========================================================="<<std::endl;
	std::cout<<"                         AGENDA                           "<<std::endl;
	std::cout<<"=========================================================="<<std::endl;

	std::cout<<"\n+1. Insertar contacto.\n+2. Buscar contacto.\n+3. Borrar contacto.\n+4. Modificar contacto.\n+5. Mostrar contactos de la agenda.\n+6. Seguridad.\n+7. Preparar para impresión\n+8. Salir.\n";
	std::cout<<"\n\t-Elija una opción:";
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

		std::cout<<"\t+1. Realizar copia de seguridad.\n\t+2. Restaurar copia de seguridad.\n\t+3. Borrar copia de seguridad.\n\t+4. Listar copias de seguridad\n\t+5. Salir."<<std::endl;
		std::cout<<"\t-Elija una opción:";

		int opt;
		std::cin>>opt;

		switch(opt){

		case 1:{

				if((*gestor).realizarCopia()==true)
					std::cout<<"¡Copia realizada con éxito!"<<std::endl;
				else
					std::cout<<"\n¡Error al realizar la copia de seguridad!"<<std::endl;

		break;}
		case 2:{
				if((*gestor).listarCopia()==false)
					std::cout<<"\n¡Error al listar las copias de seguridad!";
				else{

					std::cout<<"\nIntroduzca el nombre incluida la extensión, de la copia de seguridad que desea restaurar.";
					std::string cadena;

					std::getline(std::cin,cadena,'a');
					cadena ="./CS/"+ cadena +"a";

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

void Menu::insertarContacto() {

	bool comprobante;
	Contacto aux;

	system("clear");

	std::cin>>aux;
	comprobante = agenda_.insertarContacto(aux);

	if(comprobante == false) std::cout<<"\n##ERROR,Ha dejado uno de los campos obligatorios vacíos";

	agenda_.volcado();
}

void Menu::buscarContacto() {

	std::string apellidos;
	int comprobante;

	system("clear");

	std::cout << "\t-Introduzca los apellidos de la persona que desea buscar: " << std::endl;
	getchar();
	std::getline(std::cin,apellidos,'\n');

	comprobante = agenda_.buscarContacto(apellidos);

	if(comprobante == 0){

		std::cout<<"\t-La agenda está vacía"<<std::endl;
		std::cout<<"\t-Pulse ENTER para salir"<<std::endl;
		getchar();
	}

	else if(comprobante == -1){

		std::cout<<"\t-No existe ningún contacto con ese apellido"<<std::endl;
		std::cout<<"\t-Pulse ENTER para salir"<<std::endl;
		getchar();

	}

	else{

		std::cout<<"\t-Pulse ENTER para salir"<<std::endl;
		getchar();

	}
}

void Menu::borrarContacto() {

	std::string apellidos;
	std::string dni;
	std::string opc;
	int comprobante;

	system("clear");

	std::cout << "\t-Introduzca los apellidos de la persona que desea borrar: " << std::endl;
	getchar();
	std::getline(std::cin,apellidos,'\n');

	comprobante = agenda_.buscarContacto(apellidos);

	if(comprobante == 0){

		std::cout<<"\t-La agenda está vacía"<<std::endl;
		std::cout<<"\t-Pulse ENTER para salir"<<std::endl;
		getchar();
	}

	else if(comprobante == -1){

		std::cout<<"\t-No existe ningún contacto con ese apellido"<<std::endl;
		std::cout<<"\t-Pulse ENTER para salir"<<std::endl;
		getchar();

	}

	else{

		std::cout << "\t-Introduzca el DNI de la persona que desea borrar: " << std::endl;
		std::getline(std::cin,dni,'\n');

		do{

			std::cout<<"\n\t+¿Seguro que desea eliminar el contacto?, no podrá recuperar los datos de este a no ser que los restaure de una Copia de Seguridad";
			std::getline(std::cin,opc,'\n');
		}while(opc != "s" && opc!= "S" && opc!= "n" && opc!= "N");


		if(opc == "s" || opc == "S") {

			comprobante = agenda_.borrarContacto(dni);

			if(comprobante == 0){

				std::cout<<"\t-La agenda está vacía"<<std::endl;
				std::cout<<"\t-Pulse ENTER para salir"<<std::endl;
				getchar();
			}
			else if(comprobante == -1){

				std::cout<<"\t-No existe ningún contacto con ese dni"<<std::endl;
				std::cout<<"\t-Pulse ENTER para salir"<<std::endl;
				getchar();

			}

			else{

				std::cout<<"\t-Contacto borrado con éxito"<<std::endl;
				std::cout<<"\t-Pulse ENTER para salir"<<std::endl;
				getchar();

			}
		}

	}

	agenda_.volcado();

}

void Menu::modificarContacto() {

	std::string apellidos;
	std::string dni;
	std::string opc;
	int comprobante;

	system("clear");

	std::cout << "\t-Introduzca los apellidos de la persona que desea modificar: " << std::endl;
	getchar();
	std::getline(std::cin,apellidos,'\n');

	comprobante = agenda_.buscarContacto(apellidos);

	if(comprobante == 0){

		std::cout<<"\t-La agenda está vacía"<<std::endl;
		std::cout<<"\t-Pulse ENTER para salir"<<std::endl;
		getchar();
	}

	else if(comprobante == -1){

		std::cout<<"\t-No existe ningún contacto con ese apellido"<<std::endl;
		std::cout<<"\t-Pulse ENTER para salir"<<std::endl;
		getchar();

	}

	else{

		std::cout << "\t-Introduzca el DNI de la persona que desea modificar: " << std::endl;
		std::getline(std::cin,dni,'\n');

		comprobante = agenda_.modificarContacto(dni);

		if(comprobante == 0){

			std::cout<<"\t-El contacto que desea borrar no existe"<<std::endl;
			std::cout<<"\t-Pulse ENTER para salir"<<std::endl;
			getchar();
		}
		else if(comprobante == -1){

			std::cout<<"##ERROR, ha intentado eliminar un campo obligatorio"<<std::endl<<std::endl;
			std::cout<<"\t-Pulse ENTER para salir"<<std::endl;
			getchar();

		}

		else{

			std::cout<<"\t-Contacto modificado con éxito"<<std::endl;
			std::cout<<"\t-Pulse ENTER para salir"<<std::endl;
			getchar();

		}
	}

	agenda_.volcado();

}

void Menu::listar(){

	int opc;
	bool comprobanteTodos;
	int comprobanteFav;

	do{

		std::cout<<"================================================"<<std::endl;
		std::cout<<"               MENU DE LISTADO"<<std::endl;
		std::cout<<"================================================"<<std::endl;

		std::cout<<"\t+1.Listar todos los Contactos\n\t+2.Listar Contactos Favoritos\n\t3+Atrás.\n";
		std::cout<<"\t-Elija una opción:";
		std::cin>>opc;
		std::cin.ignore(); //Se limpia buffer de entrada
		system("clear");

		switch(opc){

		case 1:

			comprobanteTodos = agenda_.listarContactos();

			if(comprobanteTodos == false){

				std::cout<<"La agenda está vacía"<<std::endl;
				std::cout<<"Pulse ENTER para salir"<<std::endl;
				getchar();

			}
			else if(comprobanteTodos == true){

				std::cout<<"\nPulse ENTER para salir"<<std::endl;
				getchar();

			}



			break;
		case 2:

			comprobanteFav = agenda_.listarFavoritos();


			if(comprobanteFav == 0){

				std::cout<<"La agenda está vacía"<<std::endl;
				std::cout<<"Pulse ENTER para salir"<<std::endl;
				getchar();

			}
			else if(comprobanteFav == -1){

				std::cout<<"No hay ningún contacto favorito en la Agenda"<<std::endl;
				std::cout<<"\nPulse ENTER para salir"<<std::endl;
				getchar();

			}
			if(comprobanteFav == 1){

				std::cout<<"\nPulse ENTER para salir"<<std::endl;
				getchar();
			}

			break;

		default:

			break;

		}


	}while(opc != 3);



}

void Menu::prepararImpersion(){

	agenda_.prepararImpresion();

	std::cout<<"\t-¡Documento creado!"<<std::endl;
	std::cout<<"\t-¡Pulse ENTER para salir."<<std::endl;
	getchar();

}


Menu::Menu() {
	// TODO Auto-generated constructor stub

}

Menu::~Menu() {
	// TODO Auto-generated destructor stub
}
