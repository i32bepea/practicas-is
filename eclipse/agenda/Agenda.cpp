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
#include <fstream>
#include <ctime>



/*Alvaro:
 * Cuando se declara un iterator de tipo vector hay que hacerlo const (const_iterator),
 * de esa forma ya no da fallo con el 'operator =' en los bucles cuando se intenta recorrer.
 *
 * Es necesario colocar llaves en cada 'case' del switch cuando se declaran variables dentro,
 * no se muy bien porque pero dejarlo así  o sino dará error al compilar.
 *
 * En la funcion Contacto * buscarContacto()->fallo en el return porque no considera igual Contacto* a iterator,
 * no lo he solucionado.
 *
 * También he solcionado otros fallos menores del codigo(puntos y comas, parentesis,...).
 *
 * He colocado el metodo de sobrecarga de flujo de salida en la clase Contacto(Hay que colocarlo hay o dará fallo),
 * elimino por tanto el metodo imprimirContacto(), utilizar 'std::cout<<Contacto' ahora.
 *
 * La funcion de sobrecarga de flujo de entrada que Dani ha subido al github no funciona del todo,
 * no la coloco hasta que no funcione, asi que si colocais un 'std::cin>>Contacto' dejarlo comentado para
 * que no de error.
 *
 * No he colocado los metodos de Copia de Seguridad, porque todo esto se organiza a partir de una iterfaz,
 * cuando se averigue los colocaré.
 *
 * No me he parado a ver si los metodos funcionan correctamente, solo me he dedicado a solucionar
 * los fallos que daban al intentar compilar.
*/



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
			std::cout<<*pos;
			encontrado=1;
		}
	}

	if(encontrado==0)
		return -1;
	else
		return 1;
}

Contacto * Agenda::buscarContactoAux (const std::string &DNI,int * devuelto){
//La misma función que buscarContacto con la diferencia de que busca por DNI, devuelve un puntero hacia el contacto y no lo imprime.
//Devuelve por referencia 0 si está vacía, 1 si lo ha encontrado y -1 si no existe.
	int encontrado=0;

	if(listaContactos_.empty()){
		(*devuelto)=0;
	}

	for(std::list<Contacto>::iterator pos=listaContactos_.begin();pos!=listaContactos_.end();pos++){
		if(DNI==pos->getDni()){

			//return pos;  Alvaro:Dejo esto comentado hasta que se solucione
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

	c=buscarContactoAux(DNI,&devuelto);//Se busca el contacto y se guarda la dirección de memoria real, en c.

	if(devuelto!=1) //Comprueba si existe el contacto que se quiere modificar y si no existe se devuelve 0.
		return 0; //Tiene que mostrarse en pantalla el error.

	int opt;
	Contacto aux;

	std::cout<<"1. Modificar contacto entero.\n2.Modificar por parámetros.\nIntroduzca el número de la opción deseada:";
	std::cin>>opt;

	switch(opt){


	case 1:

		borrarContacto (DNI);
		//std::cin>>aux; Alvaro:Dejar comentado hasta que Dani termine la sobrecarga de flujo de entrada
		if(insertarContacto (aux)==false)
			std::cout<<"ERROR! Ha habido un error a la hora de introducir el contacto en la agenda";

		break;

	case 2: {

		int salir=0;
		while (salir==0){ //Menú de modificación de contacto por parámetros.

			system("clear");
			int opt;

			std::cout<<"1. Modificar DNI.\n2. Modificar nombre.\n3. Modificar apellidos.\n4. Modificar direcciones.\n5. Modificar email.\n6. Modificar redes sociales.\n7. Modificar favorito.\n8. Modificar teléfonos.\n9. Atrás.";
			std::cin>>opt;

			switch(opt){

			case 1:{

				std::string cadena;
				std::cout<<"Introduzca el DNI:";
				std::cin>>cadena;

				if(cadena=="")//Comprueba que no ha dejado el campo vacio.
					return -1; //El error tiene que ser mostrado por pantalla en el programa principal.

				(*c).setDni(cadena); //Introduce el campo en el contacto.

			break;}

			case 2:{

				std::string cadena;

				std::cout<<"Introduzca el nombre:";
				std::cin>>cadena;

				if(cadena=="")//Comprueba que no ha dejado el campo vacio.
					return -1; //El error tiene que ser mostrado por pantalla en el programa principal.

				(*c).setNombre(cadena); //Introduce el campo en el contacto.

			break;}

			case 3:{

				std::string cadena;

				std::cout<<"Introduzca los apellidos:";
				std::cin>>cadena;

				if(cadena=="")//Comprueba que no ha dejado el campo vacio.
					return -1; //El error tiene que ser mostrado por pantalla en el programa principal.

				(*c).setApellidos(cadena); //Introduce el campo en el contacto.

			break;}

			case 4:{

				std::vector <Direccion>::const_iterator it0;
				int i=1;
				aux=(*c);

				for(it0=aux.getDireccion().begin();it0!=aux.getDireccion().end();it0++,i++)
					std::cout<<i<<". Dirección: "<<(*it0).provincia<<", "<<(*it0).ciudad<<", "<<(*it0).tipoCalle<<", "<<(*it0).calle<<", "<<(*it0).numero<<", "<<		(*it0).CP<<std::endl;

				std::cout<<"Introduzca el número de la dirección a modificar:";

				int opt=1;

				while(opt>=1||opt<=i){//Método para comprobar que la dirección introducida es correcta.

					std::cin>>opt;
					if(opt<1||opt>i){
						opt=1;
						std::cout<<"ERROR! La dirección introducida no existe.\nIntroduzca el número de la dirección a modificar:";
					}

					else
						opt=0;
				}

				std::vector <Direccion> v=aux.getDireccion();
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

				break;}

			case 5:{

				std::string cadena;

				std::cout<<"Introduzca el email:";
				std::cin>>cadena;

				if(cadena=="")//Comprueba que no ha dejado el campo vacio.
					return -1; //El error tiene que ser mostrado por pantalla en el programa principal.

				(*c).setEmail(cadena); //Introduce el campo en el contacto.

			break;}

			case 6:{

				std::vector <Redes>::const_iterator it1;
				int i=1;
				aux=(*c);

				for(it1=aux.getRedesSociales().begin();it1!=aux.getRedesSociales().end();it1++,i++)
					std::cout<<i<<". Red social: "<<(*it1).redSocial<<", usuario: "<<(*it1).usuario<<std::endl;

				std::cout<<"Introduzca el número de la dirección a modificar:";
				int opt=1;

				while(opt>=1||opt<=i){ //Método para comprobar que la red social introducida es correcta.

					std::cin>>opt;
					if(opt<1||opt>i){
						opt=1;
						std::cout<<"ERROR! La red social introducida no existe.\nIntroduzca el número de la red social a modificar:";
					}
					else
						opt=0;
				}

				std::vector <Redes> v1=aux.getRedesSociales();
				//Recogemos los datos de la red social.
				std::cout<<"Introduzca la red social:";
				std::cin>>v1[opt-1].redSocial;
				std::cout<<"Introduzca el usuario:";
				std::cin>>v1[opt-1].usuario;

				(*c).setRedesSociales(v1); //Asignamos el vector de direcciones al contacto real.

			break;}

			case 7:{

				std::cout<<"Introduzca 'S' si es favorito y 'N' si no es favorito:";
				char fav;
				int control=0;

				while(control==0){ //Controla si la opción escogida es correcta, si no lo es vuelve a pedir su introducción.

					std::cin>>fav;
					if(fav=='s'||fav=='S'){
						(*c).setFavorito(true);
						control=1;
					}

					else if(fav=='n'||fav=='N'){
						(*c).setFavorito(false);
						control=1;
					}

					else{
						std::cout<<"Opción incorrecta. Vuelva a introducirla: ";
					}
				}

			break;}

			case 8:{

				std::vector <std::string>::const_iterator it2;
				int i=1;
				aux=(*c);

				for(it2=aux.getTelefonos().begin();it2!=aux.getTelefonos().end();it2++,i++)
					std::cout<<i<<". Número de teléfono: "<<(*it2)<<std::endl;

				std::cout<<"Introduzca el número de la dirección a modificar:";

				int opt=1;

				while(opt>=1||opt<=i){ //Método para comprobar que el teléfono introducida es correcta.

					std::cin>>opt;
					if(opt<1||opt>i){
						opt=1;
						std::cout<<"ERROR! El teléfono introducido no existe.\nIntroduzca el número de el teléfono a modificar:";
					}

					else
						opt=0;
				}

				std::vector <std::string> v2 = aux.getTelefonos();
				//Recogemos los datos del número de teléfono.
				std::cout<<"Introduzca el número de teléfono:";
				std::cin>>v2[opt-1];

				(*c).setTelefonos(v2); //Asignamos el vector de teléfonos al contacto real.*/

			break;}

			case 9:
				salir=1;

			break;

			default:
				std::cout<<"Opción incorrecta!";
		}
	}

	break;}

	default:
		std::cout<<"Opción incorrecta!\n";
	}

return 1;
}

Agenda::Agenda() {
	// TODO Auto-generated constructor stub

}

Agenda::~Agenda() {
	// TODO Auto-generated destructor stub
}

