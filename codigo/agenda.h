#ifndef AGENDA_H
#define AGENDA_H
#include "contacto.h"
#include <list>
#include <string>

class Agenda{

		private:
			list <Contacto> listaContactos_;
			list <string> listaCopiaSeguridad_;

		public:
			bool insertarContacto(Contacto c);
			bool buscarContacto(string apellido);
			bool borrarContacto(string DNI);
			bool modificarContacto(string DNI);
			bool listarContactos();
			bool listarFavoritos();
			bool realizarCopia();
			bool restaurarCopia(string nombre);
			bool borrarCopia(string nombre);
			bool listarCopias();	
	};



#endif
