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
