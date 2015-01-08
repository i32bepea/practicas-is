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
#include <cstdlib>


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
Contacto * Agenda::buscarContactoAux (const std::string &DNI,int * devuelto){ //La misma función que buscarContacto con la diferencia de que busca por DNI, devuelve un puntero hacia el contacto y no lo imprime.
	//Devuelve por referencia 0 si está vacía, 1 si lo ha encontrado y -1 si no existe.

	int encontrado=0;

	if(listaContactos_.empty()){
		(*devuelto)=0;
	}
	for(std::list<Contacto>::iterator pos=listaContactos_.begin();pos!=listaContactos_.end();pos++){
		if(DNI==pos->getDni()){
			return pos;
			encontrado=1;
		}

	}
	if(encontrado==0)
		(*devuelto)=1;
	else
		(*devuelto)=1;

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
//-1 significa que ha intentado borrar alguno de los campos obligatorios. 0 que no existe el contacto que se quiere modificar.
	int devuelto;
	Contacto * c;//Puntero que contendrá la dirección del contacto;
	c=buscarContactoAux(DNI,&devuelto); //Se busca el contacto y se guarda la dirección de memoria real, en c.
	if(devuelto!=1){ //Comprueba si existe el contacto que se quiere modificar y si no existe se devuelve 0.
		return 0; //Tiene que mostrarse en pantalla el error.
	}


std::cout<<"1. Modificar contacto entero.\n2.Modificar por parámetros.\nIntroduzca el número de la opción deseada:";
int opt;
Contacto aux;
std::cin>>opt;
switch(opt){
	case 1:
		borrarContacto (DNI);
		std::cin>>aux;
		if(insertarContacto (aux)==false)
			std::cout<<"ERROR! Ha habido un error a la hora de introducir el contacto en la agenda";
	break;

	case 2:
		int salir=0;
		while (salir==0){ //Menú de modificación de contacto por parámetros.
			system("clear");
			std::cout<<"1. Modificar DNI.\n2. Modificar nombre.\n3. Modificar apellidos.\n4. Modificar direcciones.\n5. Modificar email.\n6. Modificar redes sociales.\n7. Modificar favorito.\n8. Modificar teléfonos.\n9. Atrás.";
			int opt;
			std::cin>>opt;
				switch(opt){
				case 1:
						std::string cadena;
						std::cout<<"Introduzca el DNI:";
						std::cin<<cadena;
						if(cadena=="")//Comprueba que no ha dejado el campo vacio.
							return -1; //El error tiene que ser mostrado por pantalla en el programa principal.
						(*c).setDni(cadena); //Introduce el campo en el contacto.
				break;
				case 2:
					std::string cadena;
					std::cout<<"Introduzca el nombre:";
					std::cin<<cadena;
					if(cadena=="")//Comprueba que no ha dejado el campo vacio.
						return -1; //El error tiene que ser mostrado por pantalla en el programa principal.
					(*c).setNombre(cadena); //Introduce el campo en el contacto.
				break;
				case 3:
					std::string cadena;
					std::cout<<"Introduzca los apellidos:";
					std::cin<<cadena;
					if(cadena=="")//Comprueba que no ha dejado el campo vacio.
						return -1; //El error tiene que ser mostrado por pantalla en el programa principal.
					(*c).setApellidos(cadena); //Introduce el campo en el contacto.
				break;
				case 4:

				break;
				case 5:
					std::vector <Direccion>::iterator it0;
					int i=1;
					aux=(*c);
					for(it0=aux.getDireccion().begin();it0!=aux.getDireccion().end();it0++,i++)
							std::cout<<i<<". Dirección: "<<(*it0).provincia<<", "<<(*it0).ciudad<<", "<<(*it0).tipoCalle<<", "<<(*it0).calle<<", "<<(*it0).numero<<", "<<(*it0).CP<<std::endl;

					std::cout<<"Introduzca el número de la dirección a modificar:";
					int opt=1;
					while(opt>=1||opt<=i){ //Método para comprobar que la dirección introducida es correcta.
						std::cin>>opt;
						if(opt<1||opt>i){
							opt=1;
							std::cout<<"ERROR! La dirección introducida no existe.\nIntroduzca el número de la dirección a modificar:";
						}
						else
							opt=0;
					}

					std::vector <Direccion> v=aux.getDireccion;
					//Recogemos los datos de la dirección.
					std::cout<<"Introduzca la calle:";
					std::cin>>v[opt-1].calle;
					std::cout<<"Introduzca el número:";
					std::cin>>v[opt-1].numero;
					std::cout<<"Introduzca el código postal:";
					std::cin>>v[opt-1].CP;
					std::cout<<"Introduzca la ciudad:";
					std::cin>>v[opt-1].ciudad;
					std::cout<<"Introduzca la provincia:";
					std::cin>>v[opt-1].provincia;
					std::cout<<"Introduzca el número:";
					std::cin>>v[opt-1].numero;
					std::cout<<"Introduzca el tipo de calle:";
					std::cin>>v[opt-1].tipoCalle;

					(*c).setDireccion(v); //Asignamos el vector de direcciones al contacto real.

				break;
				case 6:

				break;
				case 7:

				break;
				case 8:

				break;
				case 9:
						salir=1;
				break;
				default:
					std::cout<<"Opción incorrecta!";


				}
		}

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

