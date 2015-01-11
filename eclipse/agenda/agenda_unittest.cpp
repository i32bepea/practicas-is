
#include "Agenda.h"
#include "Contacto.h"
#include "GestorCS.h"
#include "GestorCSFichero.h"
#include "gtest/gtest.h"

TEST(Agenda, InsertarContacto) {
	Agenda a;
	Contacto c;
  
 c.setDni("1234");
 c.setNombre("Ulises");
 c.setApellidos("Baena Herruzo");


  EXPECT_EQ(true, a.insertarContacto(c));

  c.setDni("");
  c.setNombre("");
  c.setApellidos("Abostin");

  EXPECT_EQ(false, a.insertarContacto(c));

  c.setDni("z");
  c.setNombre("z");
  c.setApellidos("Abostin");

  EXPECT_EQ(true, a.insertarContacto(c));


  std::list <Contacto> l=a.getListaContactos();

  int i=0;
  for(std::list<Contacto>::iterator pos=l.begin();pos!=l.end();pos++){
	  if(i==0)
		  EXPECT_EQ((*pos).getApellidos(), "Abostin");
	  else
		  EXPECT_EQ((*pos).getApellidos(), "Baena Herruzo");

		  i++;
  }
}
TEST(Agenda, BuscarContacto) {
	Agenda a;
	Contacto c;

 c.setDni("1234");
 c.setNombre("Ulises");
 c.setApellidos("Baena Herruzo");

 EXPECT_EQ(a.buscarContacto("Baena Herruzo"),0);

 	 a.insertarContacto(c);

 EXPECT_EQ(a.buscarContacto("Baena Herruzo"),1);

 EXPECT_EQ(a.buscarContacto("Arcos"),-1);

}
TEST(Agenda, BuscarContactoAux) {
	Agenda a;
	Contacto c;
	 int devuelto;

 c.setDni("1234");
 c.setNombre("Ulises");
 c.setApellidos("Baena Herruzo");

	Contacto aux=a.buscarContactoAux("1234",&devuelto);
	EXPECT_EQ(devuelto,0);

	 a.insertarContacto(c);

	 aux=a.buscarContactoAux("1234",&devuelto);
	EXPECT_EQ(aux.getDni(),c.getDni());
	EXPECT_EQ(devuelto,1);

	aux=a.buscarContactoAux("12345",&devuelto);
	EXPECT_EQ(devuelto,-1);
}

TEST(Agenda, BorrarContacto) {
	Agenda a;
	Contacto c;
	int devuelto;
 c.setDni("1234");
 c.setNombre("Ulises");
 c.setApellidos("Baena Herruzo");

	devuelto=a.borrarContacto("1234");
	EXPECT_EQ(devuelto,0);

	 a.insertarContacto(c);

	 devuelto=a.borrarContacto("12345");
	EXPECT_EQ(devuelto,-1);

	devuelto=a.borrarContacto("1234");
	EXPECT_EQ(devuelto,1);
}
TEST(Agenda, ListarContactos) {
	Agenda a;
	Contacto c;
 c.setDni("1234");
 c.setNombre("Ulises");
 c.setApellidos("Baena");

	EXPECT_EQ(a.listarContactos(),false);
	 a.insertarContacto(c);

	EXPECT_EQ(a.listarContactos(),true);
}
TEST(Agenda, listarFavoritos) {
	Agenda a;
	Contacto c;
	int devuelto;
 c.setDni("1234");
 c.setNombre("Ulises");
 c.setApellidos("Baena Herruzo");

	devuelto=a.listarFavoritos();
	EXPECT_EQ(devuelto,0);

	 a.insertarContacto(c);

	 devuelto=a.listarFavoritos();
	EXPECT_EQ(devuelto,-1);

	c.setFavorito(true);
	 a.insertarContacto(c);
	devuelto=a.listarFavoritos();
	EXPECT_EQ(devuelto,1);
}
