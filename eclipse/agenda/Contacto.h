/*
 * Contacto.h
 *
 *  Created on: 14/12/2014
 *      Author: cosmic0
 */

#ifndef CONTACTO_H_
#define CONTACTO_H_

#include <string>
#include <vector>
#include <iostream>

struct Direccion{
	std::string calle;
	int numero;
	long CP;
	std::string ciudad;
	std::string provincia;
	std::string tipoCalle;
};
struct Redes{
	std::string redSocial;
	std::string usuario;
};

class Contacto {

private:
	std::string DNI_;
	std::string nombre_;
	std::string apellidos_;
	std::vector <Direccion> direccion_;
	std:: string email_;
	std::  vector <Redes> redesSociales_;
	int vecesUsado_;
	bool favorito_;
	std::vector <std::string> telefonos_;



public:
	Contacto();
	virtual ~Contacto();

	const std::string& getApellidos() const {
		return apellidos_;
	}

	void setApellidos(const std::string& apellidos) {
		apellidos_ = apellidos;
	}

	const std::vector<Direccion>& getDireccion() const {
		return direccion_;
	}

	void setDireccion(const std::vector<Direccion>& direccion) {
		direccion_ = direccion;
	}

	const std::string& getDni() const {
		return DNI_;
	}

	void setDni(const std::string& dni) {
		DNI_ = dni;
	}

	const std::string& getEmail() const {
		return email_;
	}

	void setEmail(const std::string& email) {
		email_ = email;
	}

	bool isFavorito() const {
		return favorito_;
	}

	void setFavorito(bool favorito) {
		favorito_ = favorito;
	}

	const std::string& getNombre() const {
		return nombre_;
	}

	void setNombre(const std::string& nombre) {
		nombre_ = nombre;
	}

	const std::vector<Redes>& getRedesSociales() const {
		return redesSociales_;
	}

	void setRedesSociales(const std::vector<Redes>& redesSociales) {
		redesSociales_ = redesSociales;
	}

	const std::vector<std::string>& getTelefonos() const {
		return telefonos_;
	}

	void setTelefonos(const std::vector<std::string>& telefonos) {
		telefonos_ = telefonos;
	}

	int getVecesUsado() const {
		return vecesUsado_;
	}

	void setVecesUsado(int vecesUsado) {
		vecesUsado_ = vecesUsado;
	}
};

#endif /* CONTACTO_H_ */
