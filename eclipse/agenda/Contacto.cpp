/*
 * Contacto.cpp
 *
 *  Created on: 14/12/2014
 *      Author: cosmic0
 */

#include "Contacto.h"

std::ostream &operator<<(std::ostream &o,const Contacto &c){

	std::vector <Direccion>::const_iterator it0;
	std::vector <Redes>::const_iterator it1;
	std::vector <std::string>::const_iterator it2;

	o<<"=========================================================================="<<std::endl;
	o<<"\t-Nombre: "<<c.getNombre()<<std::endl;
	o<<"\t-Apellido: "<<c.getApellidos()<<std::endl;
	o<<"\t-DNI: "<<c.getDni()<<std::endl;
	o<<"\t-Email: "<<c.getEmail()<<std::endl;
	o<<"\t-Número veces usado: "<<c.getVecesUsado()<<std::endl;
	o<<"\t-Favorito: "<<c.isFavorito()<<std::endl;

	for(it0=c.getDireccion().begin();it0!=c.getDireccion().end();it0++)
		o<<"\t-Direccion: "<<(*it0).provincia<<", "<<(*it0).ciudad<<", "<<(*it0).tipoCalle<<", "<<(*it0).calle<<", "<<(*it0).numero<<", "<<(*it0).CP<<std::endl;
	for(it1=c.getRedesSociales().begin();it1!=c.getRedesSociales().end();it1++)
		o<<"\t-Tipo de Red: "<<(*it1).redSocial<<" Usuario: "<<(*it1).usuario<<std::endl;
	for(it2=c.getTelefonos().begin();it2!=c.getTelefonos().end();it2++)
		o<<"\t-Teléfono: "<<(*it2)<<std::endl;

	o<<"=========================================================================="<<std::endl;

return o;
}

std::istream &operator>>(std::istream &i,Contacto &c)
{
	std::string Nombre,Apellido,DNI,Email,Telefono;
	std::string favOpc,direccOpc,redOpc,tlfOpc;

	int opc=1;
	bool Favorito;

	struct Direccion direccAux;
	struct Redes redAux;
	std::vector <Direccion> vectorDirecc;
	std::vector <Redes> vectorRedes;
	std::vector <std::string> vectorTlf;

	std::cout<<"=========================================================================="<<std::endl;

	do{

	switch(opc){

		case 1:

			std::cout<<"\t-Introduzca el nombre del contacto (OBLIGATORIO): ";
			std::getline(i,Nombre,'\n');

			if(Nombre == "") {std::cout<<"\n##ERROR, no puede dejar en blanco un campo obligatorio\n"<<std::endl;}

			else{
				c.setNombre(Nombre);
				opc++;
			}
			break;

		case 2:

			std::cout<<"\t-Introduzca el apellido del contacto (OBLIGATORIO): ";
			std::getline(i,Apellido,'\n');
			c.setApellidos(Apellido);

			if(Apellido == "")std::cout<<"\n##ERROR, no puede dejar en blanco un campo obligatorio\n"<<std::endl;

			else opc++;
			break;

		case 3:

			std::cout<<"\t-Introduzca el DNI del contacto (OBLIGATORIO): ";
			std::getline(i,DNI,'\n');
			c.setDni(DNI);

			if(DNI == "")std::cout<<"\n##ERROR, no puede dejar en blanco un campo obligatorio\n"<<std::endl;

			else opc++;
			break;

		case 4:

			std::cout<<"\t-Introduzca el correo(Pulse ENTER si quiere dejarlo en blanco): ";
			std::getline(i,Email,'\n');
			c.setEmail(Email);
			opc++;
			break;

		case 5:

			std::cout<<"\t-¿El contacto es favorito? (s,n): ";
			std::getline(i,favOpc,'\n');

			if(favOpc == "s" || favOpc == "S"){
				c.setFavorito(true);
				opc++;
			}
			else if(favOpc == "n" || favOpc == "N"){
				c.setFavorito(false);
				opc++;
			}
			else std::cout<<"\n##ERROR, opción inválida\n"<<std::endl;
			break;

		case 6:

			std::cout<<"\t-¿Quiere introducir alguna dirección?(s/n): ";
			std::getline(i,direccOpc,'\n');

			if(direccOpc!="s" && direccOpc!="S" && direccOpc!="n" && direccOpc!="N") std::cout<<"\n##ERROR, opción inválida\n"<<std::endl;

			else{

				while(direccOpc == "s" || direccOpc == "S"){
					std::cout<<" \n\t-Introduzca los siguientes datos de la Direccion "<<std::endl;
					std::cout<<"\t\t+Introduzca la provincia: ";
					std::getline(i,direccAux.provincia,'\n');
					std::cout<<"\t\t+Introduzca la ciudad: ";
					std::getline(i,direccAux.ciudad,'\n');

					do{
						std::cout<<"\t\t+Introduzca el tipo de calle (calle,avenida,carretera o plaza): ";
						std::getline(i,direccAux.tipoCalle,'\n');

					}while(direccAux.tipoCalle!="calle" && direccAux.tipoCalle!="avenida" && direccAux.tipoCalle!="carretera" && direccAux.tipoCalle!="plaza");

					std::cout<<"\t\t+Introduzca el nombre de la calle: ";
					std::getline(i,direccAux.calle,'\n');
					std::cout<<"\t\t+Introduzca el número: ";
					i>>direccAux.numero;
					std::cout<<"\t\t+Introduzca el Código Postal: ";
					i>>direccAux.CP;

					vectorDirecc.push_back(direccAux);

					std::cout<<"\t-¿Quiere introducir otra dirección?(s/n): ";
					std::getline(i,direccOpc,'\n');

				}
				opc++;
				c.setDireccion(vectorDirecc);
			}
			break;

		case 7:

			std::cout<<"\t-¿Quiere introducir alguna Red Social?(s/n): ";
			std::getline(i,redOpc,'\n');

			if(redOpc!="s" && redOpc!="S" && redOpc!="n" && redOpc!="N") std::cout<<"\n##ERROR, opción inválida\n"<<std::endl;

			else{

				while(redOpc=="s" || redOpc=="S"){

					std::cout<<"\t\t+Introduce la redSocial: ";
					getline(i,redAux.redSocial,'\n');
					std::cout<<"\t\t+Introdue el usuario de la red: ";
					getline(i,redAux.usuario,'\n');


					vectorRedes.push_back(redAux);

					std::cout<<"\t-¿Quiere introducir otra Red Social?(s/n): ";
					std::getline(i,redOpc,'\n');


				}


				opc++;
				c.setRedesSociales(vectorRedes);

			}
			break;

		case 8:

			std::cout<<"\t-Introduzca un telefono(OBLIGATORIO): ";
			std::getline(i,Telefono,'\n');
			vectorTlf.push_back(Telefono);

			if(Telefono == "") std::cout<<"\n##ERROR, opción inválida\n"<<std::endl;

			else{
				do{

				std::cout<<"\t-¿Quiere introducir algún otro telefono?(s/n): ";
				std::getline(i,tlfOpc,'\n');

					if(tlfOpc == "s" || tlfOpc == "S"){
						std::cout<<"\t-Introduzca un telefono: ";
						std::getline(i,Telefono,'\n');
						vectorTlf.push_back(Telefono);
					}

				}while(tlfOpc == "s" || tlfOpc == "S");

				c.setTelefonos(vectorTlf);
				opc++;
			}


			break;
	}

	}while(opc<9);

	std::cout<<"=========================================================================="<<std::endl;

return i;
}

Contacto::Contacto() {

	vecesUsado_ = 0;
	favorito_ = false;

	// TODO Auto-generated constructor stub

}

Contacto::~Contacto() {
	// TODO Auto-generated destructor stub
}

