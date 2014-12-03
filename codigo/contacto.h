#ifndef CONTACTO_H
#define CONTACTO_H

#include <string>


using namespace std;

class Contacto{
	
	private:
		
		string DNI_;
		string nombre_;
		string apellidos_;
		string direccion_;
		string tFijo_;
		string tMovil_;
		string email_;
		string redesSociañes_[2];
		int vecesUsado_;
		bool favorito_;
		
	public:
	
	
		inline Contacto(){vecesUsado_=0;favorito_=false;};
		
		inline string getDNI(){return DNI_;};
		inline string getNombre(){return nombre_;};
		inline string getApellidos(){return apellidos_;};
		inline string getDireccion(){return direccion_;};
		inline string getTFijo(){return tFijo_;};
		inline string getTMovil(){return tMovil_;};
		inline string getEmail(){return email_;};
		inline string getRedesSociales(){return redesSociales_;};
		inline int getVecesUsado(){return vecesUsado_;};
		inline bool getFavorito(){return favorito_;};
		
		inline void setDNI(string dni){DNI_=dni;};
		inline void setNombre(string nombre){nombre_=nombre;};
		inline void setApellidos(string apellidos){apellidos_=apellidos;};
		inline void setDireccion(string direccion){direccion_=direccion;};
		inline void setTFijo(string tFijo){tFijo_=tFijo;};
		inline void setTMovil(string tMovil){tMovil_=tMovil;};
		inline void setEmail(string email){email_=email;};
		inline void setRedesSociales(string redesSociales){redesSociales_=redesSociales;};
		inline void setVecesUsado(int vecesUsado){vecesUsado_=vecesUsado;};
		inline void setFavorito(bool favorito){favorito_=favorito;};
	
}
#endif
