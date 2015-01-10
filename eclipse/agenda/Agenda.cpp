/*
/home/alvaro/Escritorio/IS/practicas-is/eclipse/agenda/Debug
/home/alvaro/Escritorio/IS/practicas-is/eclipse/agenda/Agenda.cpp
/home/alvaro/Escritorio/IS/practicas-is/eclipse/agenda/Agenda.h
/home/alvaro/Escritorio/IS/practicas-is/eclipse/agenda/Contacto.cpp
/home/alvaro/Escritorio/IS/practicas-is/eclipse/agenda/Contacto.h
/home/alvaro/Escritorio/IS/practicas-is/eclipse/agenda/GestorCS.h
/home/alvaro/Escritorio/IS/practicas-is/eclipse/agenda/GestorCSFichero.cpp
/home/alvaro/Escritorio/IS/practicas-is/eclipse/agenda/GestorCSFichero.h
/home/alvaro/Escritorio/IS/practicas-is/eclipse/agenda/Main.cpp
/home/alvaro/Escritorio/IS/practicas-is/eclipse/agenda/Menu.cpp
/home/alvaro/Escritorio/IS/practicas-is/eclipse/agenda/Menu.h * Agenda.cpp
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
 * La funcion de sobrecarga de flujo de entrada que Dani ha subido al github no funciona del tod,
 * no la coloco hasta que no funcione, asi que si colocais un 'std::cin>>Contacto' dejarlo comentado para
 * que no de error.
 *
 * No he colocado los metodos de Copia de Seguridad, porque tod esto se organiza a partir de una iterfaz,
 * cuando se averigue los colocaré.
 *
 * No me he parado a ver si los metodos funcionan correctamente, solo me he dedicado a solucionar
 * los fallos que daban al intentar compilar.
*/

bool Agenda::insertarContacto(const Contacto &c){ //Lo inserta, pero en la lista. Y ordena la lista.

	if(c.getNombre()=="" || c.getApellidos()=="" || c.getDni()=="")
			return false; //Comprobamos que los campos obligatorios han sido insertados.

	std::list<Contacto>::iterator ant;
	int salir=0,cont=0;

	if(!listaContactos_.empty()){
		for(std::list<Contacto>::iterator pos=listaContactos_.begin(); pos!=listaContactos_.end()&&salir==0;pos++){

			if(strcmp(c.getApellidos().c_str(),(*pos).getApellidos().c_str()) < 0){

				if(cont==0)
					listaContactos_.push_front(c); //Lo insertamos el primero de la lista.

				else
					listaContactos_.insert(pos,c);
				salir=1;
			}

			if(strcmp(c.getApellidos().c_str(),(*pos).getApellidos().c_str()) == 0){

				if(pos == listaContactos_.end()){

					listaContactos_.insert(pos,c);
					salir = 1;
				}


			}

			ant = pos;
			cont++;
		}

		if(salir == 0) listaContactos_.push_back(c);

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

Contacto Agenda::buscarContactoAux (const std::string &DNI,int * devuelto){
//La misma función que buscarContacto con la diferencia de que busca por DNI,devuelve el contacto y no lo imprime.
//Devuelve por referencia 0 si está vacía, 1 si lo ha encontrado y -1 si no existe.
	Contacto aux;
	if(listaContactos_.empty()){
		(*devuelto)=0;
	}

	for(std::list<Contacto>::iterator pos=listaContactos_.begin();pos!=listaContactos_.end();pos++){
		if(DNI==pos->getDni()){
			(*devuelto)=1;
			return *pos;
		}
	}

	*devuelto=0;
	return aux;
}

int Agenda::borrarContacto (const std::string &DNI){
	//Devuelve 0 si está vacía, 1 si lo ha borrado y -1 si no existe.

	int encontrado=0;

	if(listaContactos_.empty()){
		return 0;
	}
	for(std::list<Contacto>::iterator pos=listaContactos_.begin();pos!=listaContactos_.end()&&encontrado==0;pos++){
		if(DNI==pos->getDni()){
			listaContactos_.erase(pos);
			encontrado=1;
		}

	}

	if(encontrado==0)
		return -1;
	else{
		return 1;

	}
}

int Agenda::modificarContacto (const std::string &DNI){
//-1 significa que ha intentado borrar alguno de los campos obligatorios. 0 que no existe el contacto que se quiere modificar.
	int devuelto;
	std::string opcControl;
	Contacto contacto;
	contacto=buscarContactoAux(DNI,&devuelto);//Se busca el contacto y se guarda la dirección de memoria real, en c.
	Contacto * c=&contacto;


	if(devuelto!=1) //Comprueba si existe el contacto que se quiere modificar y si no existe se devuelve 0.
		return 0; //Tiene que mostrarse en pantalla el error.

	int opt;
	Contacto aux;

	std::cout<<"1. Modificar contacto entero.\n2.Modificar por parámetros.\nIntroduzca el número de la opción deseada:";
	std::cin>>opt;

	switch(opt){


	case 1:

		do{
			std::cout<<"¿Está seguro de que desea modificar el Contacto entero?, perderá los datos del Contacto guardado (s/n): ";
			getchar();
			std::getline(std::cin,opcControl,'\n');

		}while(opcControl!="s" && opcControl!="S" && opcControl!="n" && opcControl!="N");

		if(opcControl == "s" || opcControl == "S"){

			borrarContacto (DNI);
			std::cin>>aux;
			if(insertarContacto (aux)==false)
				std::cout<<"ERROR! Ha habido un error a la hora de introducir el contacto en la agenda";
		}

		break;

	case 2: {

		do{
			std::cout<<"¿Está seguro de que desea modificar el parametro del contacto?, perderá el dato del Contacto guardado (s/n): ";
			std::getline(std::cin,opcControl,'\n');
		}while(opcControl!="s" && opcControl!="S" && opcControl!="n" && opcControl!="N");

		if(opcControl == "s" || opcControl == "S"){

		int salir=0;
		while (salir==0){ //Menú de modificación de contacto por parámetros.

			system("clear");
			int opt;

			std::cout<<"1. Modificar DNI.\n2. Modificar nombre.\n3. Modificar apellidos.\n4. Modificar direcciones.\n5. Modificar email.\n6. Modificar redes sociales.\n7. Modificar favorito.\n8. Modificar teléfonos.\n9. Atrás.";
			std::cin>>opt;

			switch(opt){

			case 1:{
				std::cin.clear();
				std::string cadena;
				std::cout<<"Introduzca el DNI:";
				getchar();
				std::getline(std::cin,cadena,'\n');

				if(cadena=="")//Comprueba que no ha dejado el campo vacio.
					return -1; //El error tiene que ser mostrado por pantalla en el programa principal.

				(*c).setDni(cadena); //Introduce el campo en el contacto.

			break;}

			case 2:{

				std::string cadena;

				std::cout<<"Introduzca el nombre:";
				std::getline(std::cin,cadena,'\n');

				if(cadena=="")//Comprueba que no ha dejado el campo vacio.
					return -1; //El error tiene que ser mostrado por pantalla en el programa principal.

				(*c).setNombre(cadena); //Introduce el campo en el contacto.

			break;}

			case 3:{

				std::string cadena;

				std::cout<<"Introduzca los apellidos:";
				std::getline(std::cin,cadena,'\n');

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
				std::getline(std::cin,v[opt-1].calle,'\n');
				std::cout<<"Introduzca el número:";
				std::cin>>v[opt-1].numero;
				std::cout<<"Introduzca el código postal:";
				std::cin>>v[opt-1].CP;
				std::cout<<"Introduzca la ciudad:";
				std::getline(std::cin,v[opt-1].ciudad,'\n');
				std::cout<<"Introduzca la provincia:";
				std::getline(std::cin,v[opt-1].provincia,'\n');
				std::cout<<"Introduzca el número:";
				std::cin>>v[opt-1].numero;
				std::cout<<"Introduzca el tipo de calle:";
				std::getline(std::cin,v[opt-1].tipoCalle,'\n');

				(*c).setDireccion(v); //Asignamos el vector de direcciones al contacto real.

				break;}

			case 5:{

				std::string cadena;

				std::cout<<"Introduzca el email:";
				std::getline(std::cin,cadena,'\n');

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
				std::getline(std::cin,v1[opt-1].redSocial,'\n');
				std::cout<<"Introduzca el usuario:";
				std::getline(std::cin,v1[opt-1].usuario,'\n');


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
				std::getline(std::cin,v2[opt-1],'\n');

				(*c).setTelefonos(v2); //Asignamos el vector de teléfonos al contacto real.*/

			break;}

			case 9:
				borrarContacto (DNI);

				if(insertarContacto(contacto)==false)
					std::cout<<"ERROR! Ha habido un error a la hora de introducir el contacto modificado en la agenda";

				salir=1;

			break;

			default:
				std::cout<<"Opción incorrecta!";
		}
		}

	}

	break;}

	default:
		std::cout<<"Opción incorrecta!\n";
	}

return 1;
}

bool Agenda::listarContactos () {

	if(listaContactos_.empty()){
			return false;
	}

	else {

		for(std::list<Contacto>::iterator pos=listaContactos_.begin();pos!=listaContactos_.end();pos++){

			std::cout << (*pos);
			//imprimirContacto(*pos);
		}
			return true;
	}
}

int Agenda::listarFavoritos() {
//Devuelve 0 si está vacía, -1 si no hay ningún cotacto favorito o 1 si por lo menos hay uno.

	int cont = 0;

	if(listaContactos_.empty()){
				return 0;
		}

		else {

			for(std::list<Contacto>::iterator pos=listaContactos_.begin();pos!=listaContactos_.end();pos++){

				if(pos->isFavorito()==true) {
					cont++;
					std::cout << (*pos);
					//imprimirContacto(*pos);

				}
			}

		if(cont == 0)
			return -1;

		else
			return 1;
		}
}
void Agenda::volcado(){
	//Primero comprobamos si existe agenda.juda, abrimos fichero binario.

	std:: ifstream f ("agenda.juda", std::ios::binary);

	if (f.is_open()){
		f.close();
		system("rm agenda.juda"); //Eliminamos agenda.juda si esta existe.
	}

	else{

		f.close();//No existe por lo que no hay que eliminarla.
	}

	std::vector <Direccion>::const_iterator it0;
	std::vector <Redes>::const_iterator it1;
	std::vector <std::string>::const_iterator it2;

	std::ofstream file ("agenda.juda", std::ios::binary); //Creamos fichero.

	std::list<Contacto> auxLista = getListaContactos(); //Lista auxiliar donde guardaremos los contactos de la agenda.

	Contacto c;

	int size; //Auxiliar donde se guardarán los enteros del contacto, asi como el tamaño de lista y vectores.
	bool fav; //Auxiliar para boolean.
	long cp;  //Auxiliar para long.

	size = getListaContactos().size();

	//Escribimos el número de Contactos al principio del fichero binario, para poder leerlo despues y usarlo en el bucle

	file.write ((char*)&size, sizeof(int));

	for(std::list<Contacto>::iterator pos=auxLista.begin();pos!=auxLista.end();pos++){

		c = *pos;
		char cad[200];

		//Los string los pasamos a tipo char para poder copiarlos en el fichero Binario.

		strcpy(cad,c.getNombre().c_str());
		file.write ((char*) cad, 200*sizeof (char));
		strcpy(cad,c.getApellidos().c_str());
		file.write ((char*) cad, 200*sizeof (char));
		strcpy(cad,c.getDni().c_str());
		file.write ((char*) cad, 200*sizeof (char));
		strcpy(cad,c.getEmail().c_str());
		file.write ((char*) cad, 200*sizeof (char));

		size = c.getVecesUsado();
		file.write ((char*) &size, sizeof (int));

		fav = c.isFavorito();
		file.write ((char*) &fav, sizeof (bool));

		//Escribimos tamaño del vector Dirección

		size = c.getDireccion().size();
		file.write ((char*) &size, sizeof(int));

		for(it0=c.getDireccion().begin();it0!=c.getDireccion().end();it0++){

			strcpy(cad,it0->provincia.c_str());
			file.write ((char*) cad, 200*sizeof (char));
			strcpy(cad,it0->ciudad.c_str());
			file.write ((char*) cad, 200*sizeof (char));
			strcpy(cad,it0->tipoCalle.c_str());
			file.write ((char*) cad, 200*sizeof (char));
			strcpy(cad,it0->calle.c_str());
			file.write ((char*) cad, 200*sizeof (char));

			size = it0->numero;
			file.write ((char*) &size, sizeof (int));

			cp = it0->CP;
			file.write ((char*) &cp, sizeof (long));
		}

		size = c.getRedesSociales().size();

		//Escribimos el tamaño del vector Redes Sociales.

		file.write ((char*) &size, sizeof(int));

		for(it1=c.getRedesSociales().begin();it1!=c.getRedesSociales().end();it1++){

			strcpy(cad,it1->redSocial.c_str());
			file.write ((char*) cad, 200*sizeof (char));
			strcpy(cad,it1->usuario.c_str());
			file.write ((char*) cad, 200*sizeof (char));
		}

		size = c.getTelefonos().size();

		//Escribimos el tamaño del vector Telefono.

		file.write ((char*) &size, sizeof(int));



		for(it2=c.getTelefonos().begin();it2!=c.getTelefonos().end();it2++){

			strcpy(cad,(*it2).c_str());
			file.write ((char*)cad , 200*sizeof (char));
		}



	}

	file.close(); //Cerramos.
}

void Agenda::leerAgendaJuda(){
	//Primero comprobamos si existe agenda.juda

	std:: ifstream f ("agenda.juda", std::ios::binary);

	if (f.is_open()){

		f.close();

		//-------------------VARIABLES AUXILIARES--------------------------

		int sizeList, sizeVdirecc, sizeVredes, sizeVtlf,size;
		bool fav;
		long cp;

		char cad[200];

		struct Direccion direccAux;
		struct Redes redAux;

		std::vector <Direccion> vectorDirecc;
		std::vector <Redes> vectorRedes;
		std::vector <std::string> vectorTlf;

		std::list<Contacto> auxLista; //Lista auxiliar donde guardaremos los contactos de agenda.juda
		Contacto c;

		//---------------------------------------------------------------

		std::ifstream fentrada("agenda.juda", std::ios::binary); //abrimos agenda.juda

		fentrada.read((char*)&sizeList,sizeof(int));  //Número de contactos en la Agenda

		while(sizeList != 0){

			sizeList--;

			//Leemos en char y lo pasamos a string

			fentrada.read ((char*) cad, 200*sizeof (char));
			std::string Nombre(cad);

			fentrada.read ((char*) cad, 200*sizeof (char));
			std::string Apellido(cad);

			fentrada.read ((char*) cad, 200*sizeof (char));
			std::string DNI(cad);

			fentrada.read ((char*) cad, 200*sizeof (char));
			std::string Email(cad);

			fentrada.read ((char*) &size, sizeof (int));
			fentrada.read ((char*) &fav, sizeof (bool));

			//Asignamos valores en Contacto

			c.setNombre(Nombre);
			c.setApellidos(Apellido);
			c.setDni(DNI);
			c.setEmail(Email);
			c.setVecesUsado(size);
			c.setFavorito(fav);

			fentrada.read((char*)&sizeVdirecc,sizeof(int));  //Número de Direcciones del contacto

			while(sizeVdirecc != 0){

				sizeVdirecc--;


				fentrada.read ((char*) cad, 200*sizeof (char));
				std::string provincia(cad);

				fentrada.read ((char*) cad, 200*sizeof (char));
				std::string ciudad(cad);

				fentrada.read ((char*) cad, 200*sizeof (char));
				std::string tipoCalle(cad);

				fentrada.read ((char*) cad, 200*sizeof (char));
				std::string calle(cad);

				fentrada.read ((char*) &size, sizeof (int));
				fentrada.read ((char*) &cp, sizeof (long));

				direccAux.provincia = provincia;
				direccAux.ciudad = ciudad;
				direccAux.tipoCalle = tipoCalle;
				direccAux.calle = calle;
				direccAux.numero = size;
				direccAux.CP = cp;
				vectorDirecc.push_back(direccAux);

			}

			//Asignamos vectorDirecc a Contacto y repetimos proceso con resto de vectores.

			c.setDireccion(vectorDirecc);

			fentrada.read((char*)&sizeVredes, sizeof(int)); //Número de Redes Sociales del contacto

			while(sizeVredes != 0){

				sizeVredes--;
				fentrada.read ((char*) cad, 200*sizeof (char));
				std::string RedSocial(cad);

				fentrada.read ((char*) cad, 200*sizeof (char));
				std::string Usuario(cad);

				redAux.redSocial = RedSocial;
				redAux.usuario = Usuario;

				vectorRedes.push_back(redAux);


			}

			c.setRedesSociales(vectorRedes);

			fentrada.read((char*)&sizeVtlf, sizeof(int)); //Número de telefonos del contacto

			while(sizeVtlf != 0){

				sizeVtlf--;

				fentrada.read ((char*) cad, 200*sizeof (char));
				std::string Telefono(cad);

				vectorTlf.push_back(Telefono);

			}

			c.setTelefonos(vectorTlf);

			//Asignamos Contacto en lista auxiliar.

			auxLista.push_back(c);

			//Limpiamos vectores para evitar que se mezclen datos de diferentes Contactos.

			vectorDirecc.clear();
			vectorRedes.clear();
			vectorTlf.clear();



		}

		//Volcamos la lista a la agenda.
		setListaContactos(auxLista);

		//Cerramos

		fentrada.close();
	}

	else
		f.close();//No existe el fichero agenda.juda No se hace nada, ya que no hay datos que volcar.
}
Agenda::Agenda() {

	leerAgendaJuda();
}

Agenda::~Agenda() {

}
