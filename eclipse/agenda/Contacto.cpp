/*
 * Contacto.cpp
 *
 *  Created on: 14/12/2014
 *      Author: cosmic0
 */

#include "Contacto.h"

Contacto::Contacto() {

	vecesUsado_ = 0;
	favorito_ = false;

	// TODO Auto-generated constructor stub

}

Contacto::~Contacto() {
	// TODO Auto-generated destructor stub
}

std::ostream &operator<<(std::ostream &o,const Contacto &c){

	std::vector <Direccion>::const_iterator it0;
	std::vector <Redes>::const_iterator it1;
	std::vector <std::string>::const_iterator it2;

	o<<"Nombre: "<<c.getNombre()<<std::endl;
	o<<"Apellido: "<<c.getApellidos()<<std::endl;
	o<<"DNI: "<<c.getDni()<<std::endl;
	o<<"Email: "<<c.getEmail()<<std::endl;
	o<<"Número veces usado: "<<c.getVecesUsado()<<std::endl;
	o<<"Favorito: "<<c.isFavorito()<<std::endl;

	for(it0=c.getDireccion().begin();it0!=c.getDireccion().end();it0++)
		o<<"Direccion: "<<(*it0).provincia<<", "<<(*it0).ciudad<<", "<<(*it0).tipoCalle<<", "<<(*it0).calle<<", "<<(*it0).numero<<", "<<(*it0).CP<<std::endl;
	for(it1=c.getRedesSociales().begin();it1!=c.getRedesSociales().end();it1++)
		o<<"Tipo de Red: "<<(*it1).redSocial<<" Usuario: "<<(*it1).usuario<<std::endl;
	for(it2=c.getTelefonos().begin();it2!=c.getTelefonos().end();it2++)
		o<<"Teléfono: "<<(*it2)<<std::endl;

return o;
}

