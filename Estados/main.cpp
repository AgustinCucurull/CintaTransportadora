#include "controlador.h"
#include "chorno.h"
#include "ctransporte.h"

int main(int argc, char const *argv[]){
	
	controlador * c = controlador::GetInstance();

	chorno * ch1 = new chorno();
	chorno * ch2 = new chorno();
	ctransporte * ct1 = new ctransporte();
	ctransporte * ct2 = new ctransporte();

	c->AgregarCinta(ch1);
	c->AgregarCinta(ch2);
	c->AgregarCinta(ct1);
	c->AgregarCinta(ct2);
    
	std::cout<< "La cantida de cintas es " << c->CantidadDeCintas() << std::endl;

    delete ch1;
    delete ch2;
    delete ct1;
    delete ct2;
	delete c;

	return 0;
}