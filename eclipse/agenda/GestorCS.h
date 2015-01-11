
/*
 * GestorCS.h
 *
 *  Created on: 09/01/2015
 *      Author: alvaro
 */

#ifndef GESTORCS_H_
#define GESTORCS_H_

#include <string>
#include <vector>
#include <iostream>

class GestorCS {

private:

	//std::string fichero_;

public:
	GestorCS(){};
	virtual ~GestorCS(){};

	virtual bool realizarCopia() = 0;
	virtual bool restaurarCopia (std::string nombre) = 0;
	virtual bool borrarCopia (std::string nombre) = 0;
	virtual bool listarCopia () = 0;
	virtual void volcar() = 0;
	virtual void lectura() = 0;

};

#endif /* GESTORCS_H_ */
