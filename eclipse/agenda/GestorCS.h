
/*
 * GestorCS.h
 *
 *  Created on: 09/01/2015
 *      Author: alvaro
 */

#ifndef GESTORCS_H_
#define GESTORCS_H_

class GestorCS {

private:

	std::string fichero_;

public:
	GestorCS();
	virtual ~GestorCS();

	virtual bool realizarCopia(Agenda a) = 0;
	virtual bool restaurarCopia (std::string nombre) = 0;
	virtual bool borrarCopia (std::string nombre) = 0;
	virtual bool listarCopia () = 0;
};

#endif /* GESTORCS_H_ */
