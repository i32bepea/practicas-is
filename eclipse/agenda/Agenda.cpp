/*
 * Agenda.cpp
 *
 *  Created on: 14/12/2014
 *      Author: cosmic0
 */

#include "Agenda.h"
#include <cstring>
#include <cstdio>
#include <iostream>


bool Agenda::insertarContacto(const Contacto &c){

	if(c.getNombre()=="" || c.getApellidos()=="" || c.getDni()=="")
			return false; //Comprobamos que los campos obligatorios han sido insertados.

	std::list<Contacto>::iterator ant;
	int salir=0,cont;

	if(!listaContactos_.empty()){
		for(std::list<Contacto>::iterator pos=listaContactos_.begin(),cont=0; pos!=listaContactos_.end()&&salir==0;pos++,cont++){

			if(strcmp(c.getApellidos().c_str(),(*pos).getApellidos().c_str())>0){
				if(cont==0)
					listaContactos_.insert(pos,c); //Lo insertamos el primero de la lista.
				else
					listaContactos_.insert(ant,c);
				salir=1;
			}
			else{
				ant=pos;

			}

		}

	}

	else{
		listaContactos_.push_back(c);
		}

	return true;
}

int Agenda::buscarContacto (const std::string &apellidos){
	//Devuelve 0 si está vacía, 1 si lo ha encontrado y -1 si no existe.

	int encontrado=0;

	if(listaContactos_.empty()){
		return 0;
	}
	for(std::list<Contacto>::iterator pos=listaContactos_.begin();pos!=listaContactos_.end();pos++){
		if(apellidos==pos->getApellidos()){
			imprimirContacto(*pos);
			encontrado=1;
		}

	}
	if(encontrado==0)
		return -1;
	else
		return 1;

}

int Agenda::borrarContacto (const std::string &DNI){
	//Devuelve 0 si está vacía, 1 si lo ha borrado y -1 si no existe.

	int encontrado=0;

	if(listaContactos_.empty()){
		return 0;
	}
	for(std::list<Contacto>::iterator pos=listaContactos_.begin();pos!=listaContactos_.end();pos++){
		if(DNI==pos->getDni()){
			listaContactos_.erase(pos);
			encontrado=1;
		}

	}

	if(encontrado==0)
		return -1;
	else
		return 1;

}


int Agenda::modificarContacto (const std::string &DNI){
	//-1 significa que ha intentado borrar alguno de los campos obligatorios.
	std::cout<<"1. Modificar contacto entero.\n2.Modificar por parámetros.\nIntroduzca el número de la opción deseada:";
	int opt;
	Contacto aux;
	std::cin>>opt;
	switch(opt){
	case 1:
		borrarContacto (DNI);


		break;
	case 2:


		break;

	default:
		std::cout<<"Opción incorrecta!\n";

	}

	int encontrado=0;
	std::string auxiliar;
	for(std::list<Contacto>::iterator pos=listaContactos_.begin();pos!=listaContactos_.end()&&encontrado==0;pos++){
		if((*pos).getDni()==DNI){
			aux=(*pos);
			encontrado=1;
		}
	}
	if(encontrado==1){
	std::cout<<"Pulse ENTER en caso de que no quiera modificar dicho campo, o BARRA ESPACIADORA para borrar dicho campo(Recuerde que no se pueden borrar los campos Nombre, Apellidos y DNI:\n";

	std::cout<<"Nombre:";
	std::cin<<auxiliar;
		if(auxiliar==" "){
			//ERROR NO SE PUEDE BORRAR
			return -1;
		}
		else if(auxiliar!=""){

			aux.setNombre(auxiliar);
		}
	}
	return encontrado;


}




void Agenda::imprimirContacto (const Contacto &c){

	std::vector <Direccion>::iterator it0;
	std::vector <Redes>::iterator it1;
	std::vector <std::string>::iterator it2;

	std::cout<<"Nombre: "<<c.getNombre()<<std::endl;
	std::cout<<"Apellidos: "<<c.getApellidos()<<std::endl;
	std::cout<<"DNI: "<<c.getDni()<<std::endl;
	std::cout<<"Email: "<<c.getEmail()<<std::endl;
	std::cout<<"Número veces usado: "<<c.getVecesUsado()<<std::endl;
	std::cout<<"Favorito: "<<c.isFavorito()<<std::endl;

	for(it0=c.getDireccion().begin();it0!=c.getDireccion().end();it0++)

		std::cout<<"Dirección: "<<(*it0).provincia<<", "<<(*it0).ciudad<<", "<<(*it0).tipoCalle<<", "<<(*it0).calle<<", "<<(*it0).numero<<", "<<(*it0).CP<<std::endl;


	for(it1=c.getRedesSociales().begin();it1!=c.getRedesSociales().end();it1++)

		std::cout<<"Tipo de Red: "<<(*it1).redSocial<<" Usuario: "<<(*it1).usuario<<std::endl;

	for(it2=c.getTelefonos().begin();it2!=c.getTelefonos().end();it2++)

		std::cout<<"Teléfono: "<<(*it2)<<std::endl;
}





Agenda::Agenda() {
	// TODO Auto-generated constructor stub

}

Agenda::~Agenda() {
	// TODO Auto-generated destructor stub
}

