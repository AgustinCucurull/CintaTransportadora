/*
En este codigo escribire los detalles de la implementacion de esta pizarra.
*/

#include "datoscompartidos.h"

// Inicia sin instancias 
datoscompartidos* datoscompartidos::instancia = 0;

datoscompartidos::datoscompartidos(){

	std::cout<< "Se ha creado una pizarra" << std::endl;

}

// Cuando se llame al getInstance solo se encargara de que haya uno, lo llamare en el constructor del controlador
datoscompartidos* datoscompartidos::getInstance() {
	
	if (instancia == 0) {
	
		instancia = new datoscompartidos;
	
	}
	
	return instancia;
}



void EscribirDato(std::string id_sensor, float valor) {


}

void EnviarDato(std::string id_cinta){


}
