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

	std::cout<<"\n+1. Insertar contacto.\n+2. Buscar contacto.\n+3. Borrar contacto.\n+4. Modificar contacto.\n+5. Mostrar contactos de la agenda.\n+6. Seguridad.\n+7. Preparar para impresión\n+8. Guardar cambios y Salir.\n";
	std::cout<<"\n\t-Elija una opción: ";
}
void Menu::salir(){

	agenda_.volcado(); //Vuelca el contenido de la agenda a agenda.juda

}


void Menu::insertarContacto() {

	bool comprobante;
	Contacto aux;

	system("clear");

	std::cout<<"================================================"<<std::endl;
	std::cout<<"               MENÚ DE INSERTAR"<<std::endl;
	std::cout<<"================================================"<<std::endl;

	std::cin.ignore();
	std::cin>>aux;
	comprobante = agenda_.insertarContacto(aux);

	if(comprobante == false){
		std::cout<<"\n##ERROR,Ha dejado uno de los campos obligatorios vacíos";
		confirmar();
	}

}

void Menu::buscarContacto() {

	std::string apellidos;
	std::string dni;
	Contacto c;

	int comprobante;

	system("clear");

	std::cout<<"================================================"<<std::endl;
	std::cout<<"               MENÚ DE BUSCAR"<<std::endl;
	std::cout<<"================================================"<<std::endl;

	std::cin.ignore();

	std::cout << "\t-Introduzca los apellidos de la persona que desea buscar: ";
	std::getline(std::cin,apellidos,'\n');

	comprobante = agenda_.buscarContacto(apellidos);

	if(comprobante == 0){

		std::cout<<"\t-La agenda está vacía"<<std::endl;
		confirmar();
	}

	else if(comprobante == -1){

		std::cout<<"\t-No existe ningún contacto con ese apellido"<<std::endl;
		confirmar();

	}

	else{

		std::cout<<"\t-Introduzca el DNI del contacto que quiera utilizar (sino quiere utilizar ninguno pulse ENTER): ";
		std::getline(std::cin,dni,'\n');

		if(dni != ""){

			c=agenda_.buscarContactoAux(dni,&comprobante);

			if(comprobante == -1)
				std::cout<<"\t-No existe ningun contacto con ese DNI";

			else{

				c.setVecesUsado(c.getVecesUsado()+1);
				agenda_.borrarContacto(dni);

				if (agenda_.insertarContacto(c) == true)
					std::cout<<"\t-Contacto usado correctamente"<<std::endl;

			}

		}

		confirmar();
	}
}

void Menu::borrarContacto() {

	std::string apellidos;
	std::string dni;
	std::string opc;
	int comprobante;

	system("clear");

	std::cout<<"================================================"<<std::endl;
	std::cout<<"               MENÚ DE BORRADO"<<std::endl;
	std::cout<<"================================================"<<std::endl;

	std::cin.ignore();

	std::cout << "\t-Introduzca los apellidos de la persona que desea borrar: ";
	std::getline(std::cin,apellidos,'\n');

	comprobante = agenda_.buscarContacto(apellidos);

	if(comprobante == 0){

		std::cout<<"\t-La agenda está vacía"<<std::endl;
		confirmar();
	}

	else if(comprobante == -1){

		std::cout<<"\t-No existe ningún contacto con ese apellido"<<std::endl;
		confirmar();

	}

	else{

		std::cout << "\t-Introduzca el DNI de la persona que desea borrar: " << std::endl;
		std::getline(std::cin,dni,'\n');

		do{

			std::cout<<"\n\t+¿Seguro que desea eliminar el contacto?, no podrá recuperar los datos de este a no ser que los restaure de una Copia de Seguridad.Introduzca s(si)/n(no): ";
			std::getline(std::cin,opc,'\n');
		}while(opc != "s" && opc!= "S" && opc!= "n" && opc!= "N");


		if(opc == "s" || opc == "S") {

			comprobante = agenda_.borrarContacto(dni);

			if(comprobante == 0){

				std::cout<<"\t-La agenda está vacía"<<std::endl;
				confirmar();
			}
			else if(comprobante == -1){

				std::cout<<"\t-No existe ningún contacto con ese dni"<<std::endl;
				confirmar();

			}

			else{

				std::cout<<"\t-Contacto borrado con éxito"<<std::endl;
				confirmar();

			}
		}

	}

}

void Menu::modificarContacto() {

	std::string apellidos;
	std::string dni;
	std::string opc;
	int comprobante;

	system("clear");

	std::cout<<"================================================"<<std::endl;
	std::cout<<"               MENÚ DE MODIFICADO"<<std::endl;
	std::cout<<"================================================"<<std::endl;

	std::cin.ignore();

	std::cout << "\t-Introduzca los apellidos de la persona que desea modificar: ";
	std::getline(std::cin,apellidos,'\n');

	comprobante = agenda_.buscarContacto(apellidos);

	if(comprobante == 0){

		std::cout<<"\t-La agenda está vacía"<<std::endl;
		confirmar();
	}

	else if(comprobante == -1){

		std::cout<<"\t-No existe ningún contacto con ese apellido"<<std::endl;
		confirmar();

	}

	else{

		std::cout << "\t-Introduzca el DNI de la persona que desea modificar: ";
		std::getline(std::cin,dni,'\n');

		comprobante = agenda_.modificarContacto(dni);

		if(comprobante == 0){

			std::cin.ignore();
			std::cout<<"\t-El contacto que desea borrar no existe"<<std::endl;
			confirmar();
		}
		else if(comprobante == -1){

			std::cin.ignore();
			std::cout<<"\n##ERROR , ha intentado eliminar un campo obligatorio"<<std::endl<<std::endl;
			confirmar();

		}

		if(comprobante == 1){

			std::cin.ignore();
			std::cout<<"\t-Contacto modificado con éxito"<<std::endl;
			confirmar();

		}

		else if(comprobante == -2){

			std::cin.ignore();
			std::cout<<"\t-Operación abortada"<<std::endl;
			confirmar();
		}
	}


}

void Menu::listar(){

	int opc;
	bool comprobanteTodos;
	int comprobanteFav;

	do{

		system("clear");

		std::cout<<"================================================"<<std::endl;
		std::cout<<"               MENÚ DE LISTADO"<<std::endl;
		std::cout<<"================================================"<<std::endl;

		std::cout<<"\t+1. Listar todos los Contactos\n\t+2. Listar Contactos Favoritos\n\t+3. Atrás\n";
		std::cout<<"\n\t- Elija una opción:";
		std::cin>>opc;
		std::cin.ignore(); //Se limpia buffer de entrada
		system("clear");

		switch(opc){

		case 1:

			comprobanteTodos = agenda_.listarContactos();

			if(comprobanteTodos == false){

				std::cout<<"\n\t-La agenda está vacía"<<std::endl;
				confirmar();

			}
			else if(comprobanteTodos == true)

				confirmar();

			break;
		case 2:

			comprobanteFav = agenda_.listarFavoritos();


			if(comprobanteFav == 0){

				std::cout<<"\n\t-La agenda está vacía"<<std::endl;
				confirmar();

			}
			else if(comprobanteFav == -1){

				std::cout<<"\t-No hay ningún contacto favorito en la Agenda"<<std::endl;
				confirmar();

			}
			if(comprobanteFav == 1)
				confirmar();

			break;

		case 3:

			break;

		default:

			std::cout<<"\n\t-¡Opción incorrecta!"<<std::endl;
			confirmar();

			break;

		}


	}while(opc != 3);



}

void Menu::seguridad(){

	agenda_.volcado();
	int salir=0;
	GestorCS * gestor= agenda_.getGestor();
	GestorCSFichero gestorF;
	gestor=&gestorF;

	while(salir==0){

		int opt;

		system("clear");

		std::cout<<"================================================"<<std::endl;
		std::cout<<"               MENÚ DE SEGURIDAD"<<std::endl;
		std::cout<<"================================================"<<std::endl;

		std::cin.clear();
		std::cout<<"\n\t+1. Realizar copia de seguridad.\n\t+2. Restaurar copia de seguridad.\n\t+3. Borrar copia de seguridad.\n\t+4. Listar copias de seguridad\n\t+5. Atrás.\n\n\t-Elija una opción: ";
		std::cin>>opt;

		switch(opt){

		case 1:{

			std::cin.ignore();

			if((*gestor).realizarCopia()==true){
				std::cout<<"\n\t-¡Copia realizada con éxito!"<<std::endl;;
				confirmar();
			}

			else{
				std::cout<<"\n##ERROR  al realizar la copia de seguridad!"<<std::endl;
				confirmar();
			}
		break;}

		case 2:{

			if((*gestor).listarCopia()==false){
				std::cout<<"\n##ERROR  al listar las copias de seguridad!"<<std::endl;
				confirmar();

			}

			else{
				std::cout<<"\n\t-Introduzca el nombre incluida la extensión, de la copia de seguridad que desea restaurar: ";
				std::string cadena;
				std::cin.ignore();
				std::getline(std::cin,cadena,'\n');

				if((*gestor).restaurarCopia(cadena)==false){
					std::cout<<"\n##ERROR  al intentar restaurar la copia de seguridad!"<<std::endl;
					confirmar();
				}

				else{
					std::list<Contacto> lista;
					agenda_.setListaContactos(lista); //Limpiamos la lista de contactos de la agenda, para introducir los nuevos.
					agenda_.leerAgendaJuda(); //Tenemos que volcar la nueva agenda a memoria.
					std::cout<<"\n\t-¡Copia de seguridad restaurada satisfactoriamente!"<<std::endl;
					confirmar();
				}
			}
			system("clear");
		break;}

		case 3:{

			if((*gestor).listarCopia()==false){
				std::cout<<"\n##ERROR al listar las copias de seguridad!"<<std::endl;
				confirmar();
			}

			else{
				std::cout<<"\n\t-Introduzca el nombre incluida la extensión, de la copia de seguridad que desea borrar: ";
				std::string cadena;
				std::cin>>cadena;

				if((*gestor).borrarCopia(cadena)==false){
					std::cin.ignore();
					std::cout<<"\n##ERROR  al intentar borrar la copia de seguridad!"<<std::endl;
					confirmar();

				}
				else{
					std::cin.ignore();
					std::cout<<"\n\t--¡Copia de seguridad borrada satisfactoriamente!"<<std::endl;
					confirmar();
				}

			}

		break;}

		case 4:{

			if((*gestor).listarCopia()==false)
				std::cout<<"\n\t-No existe ninguna Copia de Seguridad"<<std::endl;

			std::cin.ignore();
			confirmar();

		break;}

		case 5:{
			salir=1;

		break;}

		default:
			std::cout<<"\n\t-Opción incorrecta!";
		}

	}

}

void Menu::prepararImpersion(){

	std::string cadena;

	agenda_.prepararImpresion();

	std::cout<<"\n\t-¡Documento creado!"<<std::endl;
	confirmar();

}

void Menu::confirmar(){

	std::cout<<"\t-Pulse ENTER para salir.";
	getchar();
}


Menu::Menu() {
	// TODO Auto-generated constructor stub

}

Menu::~Menu() {
	// TODO Auto-generated destructor stub
}
