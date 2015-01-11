
#include "Contacto.h"
#include "gtest/gtest.h"

TEST(Contacto, ComprobarFunciones) {
  Contacto c;
  
 c.setDni("1234");
 c.setNombre("Joselu");
 c.setApellidos("Arcos García");
 c.setEmail("joselu@uco.es");
 c.setVecesUsado(20);
 c.setFavorito(true);


  EXPECT_EQ("1234", c.getDni());
  EXPECT_EQ("Joselu", c.getNombre());
  EXPECT_EQ("Arcos García", c.getApellidos());
  EXPECT_EQ("joselu@uco.es", c.getEmail());
  EXPECT_EQ(20, c.getVecesUsado());
  EXPECT_EQ(true, c.isFavorito());


}
TEST(Contacto, ComprobarVectorDirecciones) {
	Contacto c;

	std::vector <Direccion> dir;
	 Direccion d;
	 d.calle="calle";
	 d.numero=6;
	 d.CP=8;
	 d.ciudad="ciudad";
	 d.provincia="provincia";
	 d.tipoCalle="tipoCalle";
	 int i;
	 for(i=0;i<100;i++)
	 	 dir.push_back(d);

	 c.setDireccion(dir);
	 dir.clear();
	 dir=c.getDireccion();

	 for(i=0;i<100;i++){
	 Direccion d2=dir[i];

	   EXPECT_EQ(d.calle, d2.calle);
	   EXPECT_EQ(d.numero, d2.numero);
	   EXPECT_EQ(d.CP, d2.CP);
	   EXPECT_EQ(d.ciudad, d2.ciudad);
	   EXPECT_EQ(d.provincia, d2.provincia);
	   EXPECT_EQ(d.tipoCalle, d2.tipoCalle);
	 }


}
TEST(Contacto, ComprobarVectorRedesSociales) {
	Contacto c;
	 std::vector <Redes> red;
	 Redes r;
	 r.redSocial="redSocial";
	 r.usuario="usuario";
	 int i;
	 for(i=0;i<100;i++)
		 red.push_back(r);
	 c.setRedesSociales(red);
	 red.clear();
	 red=c.getRedesSociales();

	 for(i=0;i<100;i++){
	  Redes r2=red[0];
	  EXPECT_EQ(r.redSocial, r2.redSocial);
	  EXPECT_EQ(r.usuario, r2.usuario);
	 }
}

TEST(Contacto, ComprobarVectorTelefonos) {
	Contacto c;
	 std::vector <std::string> tel;
	 std::string t;
	 t="12345";

	 int i;
	 for(i=0;i<100;i++)
	 tel.push_back(t);
	 c.setTelefonos(tel);
	 tel.clear();
	 tel=c.getTelefonos();

	 for(i=0;i<100;i++){
	  std::string t2=tel[0];
	  EXPECT_EQ(t, t2);
	 }
}
