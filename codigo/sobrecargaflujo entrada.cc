friend istream& operator(istream &i,Contacto c)
{
string Nombre,Apellido,DNI,Email,fav,provincia,ciudad,tipoCalle,calle,redSocial,usuario,telefono;
int VecesUsado,numero;
long CP;
bool Favorito;

	std::vector <Direccion>::iterator it0;
	std::vector <Redes>::iterator it1;
	std::vector <std::string>::iterator it2;

	do{
	std::cout<<"Introduce el nombre del contacto: ";
	i>>Nombre;
	c.setNombre(Nombre);
	std::cout<<endl;
	}while(Nombre=="");
	
	do{
	std::cout<<"Introduce el apellido: ";
	i>>Apellido;
	c.setApellido(Apellido);
	std::cout<<endl;
	}while(Apellido=="");
	
	do{
	std::cout<<"Introduce el DNI: ";
	i>>DNI;
	c.setDNI(DNI);
	std::cout<<endl;
	}while(DNI=="");
	
	
	std::cout<<"Introduce el correo: ";
	i>>Email;
	c.setEmail(Email);
	std::cout<<endl;
	
	
	std::cout<<"Introduce el número de veces usado: ";
	i>>VecesUsado;
	c.setVecesUsado(VecesUsado);
	std::cout<<endl;

º	std::cout<<"¿El contacto es favorito? (SI,NO): ";
	i>>fav;
		if(fav=="SI")
		Favorito=true;
		else
		Favorito=false;
		
	c.setFavorito(Favorito);
	

	for(it0=c.getDireccion().begin();it0!=c.getDireccion().end();it0++)
	{
	
		std::cout<<"Introduce los siguientes datos de la Direccion "<<endl;
		
		std::cout<<"Introduce la provincia: ";
		i>>(*it0).provincia;
		std::cout<<endl;
		
		std::cout<<"Introduce la ciudad: "
		i>>(*it0).ciudad;
		std::cout<<endl;
		
		do{
		std::cout<<"Introduce el tipo de calle (calle,avenida,carretera o plaza): ";
		i>>(*it0).tipoCalle;
		std::cout<<endl;
		}while((*it0).tipoCalle!="calle"&&(*it0).tipoCalle!="avenida"&&(*it0).tipoCalle!="carretera"&&(*it0).tipoCalle!="plaza");
		
		std::cout<<"Introduce la calle: ";
		i>>(*it0).calle;
		std::cout<<endl;
		
		std::cout<<"Introduce el número: ";
		i>>(*it0).numero;
		std::cout<<endl;
		
		std::cout<<"Introduce el Código Postal: ";
		i>>(*it0).CP;
		std::cout<<endl;
	}
	
	for(it1=c.getRedes().begin();it1!=c.getRedes().end();it1++)
	{
		do{
		std::cout<<"Introduce la redSocial (twitter o facebook): ";
		i>>(*it1).redSocial;
		std::cout<<endl;
		}while((*it1).redSocial!="twitter"&&(*it1).redSocial!="facebook");
		
		std::cout<<"Introduce el usuario de la red: ";
		i>>(*it1).usuario;
		std::cout<<endl;
	}
		
	for(it2=c.getTelefonos().begin();it2!=c.getTelefonos().end();it2++)
	{
		std::cout<<"Introduce el telefono: ";
		i>>(*it2).telefono
		std::cout<<endl;
	}
		
	return i;
	
}
