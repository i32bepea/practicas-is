#include "agenda.h"

bool Agenda::insertarContacto(Contacto c)
{

	list <Contacto>::iterator it;
	
	
	
	if(!listaContactos_.empty()){
	
		for(it=listaContactos_.begin();it!=listaContactos_.end();it++){
		
			//MÉTODO DE ORDENACIÓN 			
	
		}

	}
	
	else
		
		listaContactos_.push_back(c);
			
	
	return true;


}

bool Agenda::buscarContacto(string apellido)
{
	
	list <Contacto>::iterator it;
	bool encontrado = false;
	
	if(!listaContactos_.empty()){
	
		for(it=listaContactos_.begin();it!=listaContactos_.end();it++){
		
				if(it->getApellidos() == apellido){
					
					cout<<(*it);
					encontrado = true;
				}
		}
		
		
		if(!encontrado)	cout<<"No hay ningun Contacto con ese apellido"<<endl;
			
		return true;
	}
	
	else
		
		return false;

}
bool Agenda::borrarContacto(string DNI)
{
list <Contacto>::iterator it;
int encontrado = 0;

	if(!listaContactos_.empty())
	{		
		for(it=listaContactos_.begin();it!=listaContactos_.end()&&encontrado==0;it++)
		{
			if((*it).getDNI()==DNI)
			{
			encontrado=1;
			listaContactos_.remove((*it));
			}
		}
	return true;	
	}
	else
	return false;
	
}
bool Agenda::modificarContacto(string DNI)
{
list <Contacto>::iterator it;
int encontrado = 0;

	if(!listaContactos_.empty())
	{		
		for(it=listaContactos_.begin();it!=listaContactos_.end()&&encontrado==0;it++)
		{
			if((*it).getDNI()==DNI)
			{
			encontrado=1;
			//Leer contacto y añadir los nuevos datos en el viejo contacto.
			}
		}
	return true;	
	}
	else
	return false;
}
bool Agenda::listarContactos()
{
list <Contacto>::iterator it;


	if(!listaContactos_.empty())
	{		
		for(it=listaContactos_.begin();it!=listaContactos_.end();it++)
		{
		cout<<(*it);
		}
	return true;		
	}
	return false;
	
}	
bool Agenda::listarFavoritos()
{

list <Contacto>::iterator it;

	if(!listaContactos_.empty())
	{		
		for(it=listaContactos_.begin();it!=listaContactos_.end();it++)
		{
			if(listaContactos_.getFavorito())
			cout<<(*it);
		}
	return true;		
	}
	return false;

}
bool Agenda::realizarCopia()
{

}
bool Agenda::restaurarCopia(string nombre)
{

}
bool Agenda::borrarCopia(string nombre)
{

}
bool Agenda::listarCopias()
{

}

friend ostream &operator(ostream &o,const Contacto c)
{

	std::vector <Direccion>::iterator it0;
	std::vector <Redes>::iterator it1;
	std::vector <std::string>::iterator it2;

	o<<"Nombre: "<<c.getNombre()<<endl;
	o<<"Apellido: "<<c.getApellido()<<endl;
	o<<"DNI: "<<c.getDNI()<<endl;
	o<<"Email: "<<c.getEmail()<<endl;
	o<<"Número veces usado: "<<c.getVecesUsado()<<endl;
	o<<"Favorito: "<<c.getFavorito()<<endl;

	for(it0=c.getDireccion().begin();it0!=c.getDireccion().end();it0++)
	
		o<<"Direccion: "<<(*it0).provincia<<", "<<(*it0).ciudad<<", "<<(*it0).tipoCalle<<", "<<(*it0).calle<<", "<<(*it0).numero<<", "<<(*it0).CP<<endl;
	
	
	for(it1=c.getRedes().begin();it1!=c.getRedes().end();it1++)
	
		o<<"Tipo de Red: "<<(*it1).redSocial<<" Usuario: "<<(*it1).usuario<<endl;
		
	for(it2=c.getTelefonos().begin();it2!=c.getTelefonos().end();it2++)
	
		o<<"Teléfono: "<<(*it2)<<endl;
	


	return o;
}


