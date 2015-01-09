/*
 * GestorCS.cpp
 *
 *  Created on: 9/1/2015
 *      Author: cosmic0
 */

#include "GestorCS.h"


bool GestorCS::realizarCopia (Agenda a){ //Realiza una copia de agenda.juda a /CS/fechaYhora.juda Para ello tiene que volcar los datos existentes de Agenda a agenda.juda

	//Volcamos tod0 el contenido de la agenda pasada por referencia a agenda.juda
	//Primero comprobamos si existe agenda.juda

	std:: ifstream f ("agenda.juda");
		  if (f.is_open())
		  {
			  f.close();
			  //Existe el fichero agenda.juda. Este caso es un poco más complicado, vamos a volvar los contactos de agenda.juda a la agenda actual,
			  //para que queden ordenados y después volcar toda la agenda de manera normal.
			  Agenda aux; //Agenda auxiliar donde volcaremos toda la agenda.juda

			  std::ifstream fentrada("agenda.juda", std::ios::in | std::ios::binary); //Abrimos agenda.juda en modo binario

			     fentrada.read(reinterpret_cast<char *>(&aux), sizeof(Agenda)); //Lo escribimos en agenda auxiliar. aux

			     fentrada.close(); //Cerramos

			  //Ahora hay que ir volcando cada contacto de aux a la agenda a. Para que la función de insertar los deje ordenados.
			     std::list<Contacto> lista=aux.getListaContactos(); //Lista en la que guardamos la lista de contactos de aux.


			     for(std::list<Contacto>::iterator pos=lista.begin(); pos!=lista.end();pos++){ //Recorremos la lista

			    	 	 a.insertarContacto(*pos); //Insertamos el contacto en la agenda a.
			     }
			     //Ya tenemos la agenda definitiva en "a" ahora simplemente hay que crear un agenda.juda con los datos de "a".
			     system("rm agenda.juda"); //Eliminamos el agenda.juda obsoleto.
			     //No existe el fichero agenda.juda
			     			  std::ofstream file ("agenda.juda", std::ios::out | std::ios::binary); //Lo creamos

			     			   file.write(reinterpret_cast<char *>(&a), sizeof(Agenda)); //Y escribimos el contenido de la agenda

			     			   file.close(); //Cerramos.
		   }
		  else{
			  f.close();
			  //No existe el fichero agenda.juda
			  std::ofstream file ("agenda.juda", std::ios::out | std::ios::binary); //Lo creamos

			   file.write(reinterpret_cast<char *>(&a), sizeof(Agenda)); //Y escribimos el contenido de la agenda

			   file.close(); //Cerramos.
		  }

		  //PROCESO DE COPIA de seguridad de agenda.juda

	system("mkdir CS");

    time_t tiempo = time(0);
     struct tm *tlocal = localtime(&tiempo);
     char salida[128];
     strftime(salida,128,"%d.%m.%y-%H:%M:%S",tlocal);

     std::string output(salida);
     std::string cadena="cp agenda.juda /CS/" + output + ".juda";

	if(system(cadena.c_str())==-1){
		return false;
	}
	else{
		return true;
	}
}

bool GestorCS::restaurarCopia (std::string nombre){ // Restaura la copia de seguridad indicada en string nombre, tiene que venir con la extensión, y las comprobaciones de que exista las hace la función.
	std::string cadena="/CS/" + nombre;
	 std:: ifstream f (cadena.c_str());
	  if (f.is_open())
	  {
		  f.close();

			if(system("rm agenda.juda")==-1){
				return false;
			}
			cadena= "cp " + cadena + "agenda.juda";
			if(system(cadena.c_str())==-1){
				return false;
			}
			else
				return true;
	   }
	  else{
		  f.close();
		  return false; //No existe el archivo del que restaurar la copia.
	  }
}

bool GestorCS::borrarCopia (std::string nombre){ // Borra la copia de seguridad indicada en string nombre, tiene que venir con la extensión, y las comprobaciones de que exista las hace la función.
	std::string cadena="/CS/" + nombre;
	 std:: ifstream f (cadena.c_str());
	  if (f.is_open())
	  {
		  f.close();

			cadena= "rm  " + cadena;
			if(system(cadena.c_str())==-1){
				return false;
			}
			else
				return true;
	   }
	  else{
		  f.close();
		  return false; //No existe la copia de seguridad que hay que borrar.
	  }
}
bool GestorCS::listarCopia (){ // Borra la copia de seguridad indicada en string nombre, tiene que venir con la extensión, y las comprobaciones de que exista las hace la función.
	if(system("ls CP")==-1){
					return false;
				}
				else
					return true;
}
GestorCS::GestorCS() {
	// TODO Auto-generated constructor stub

}

GestorCS::~GestorCS() {
	// TODO Auto-generated destructor stub
}

