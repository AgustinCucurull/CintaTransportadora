/*
El controlador es el mas importarte de todos su funcionalidad es la de gestionar las cintas (y en un futuro los sensores).
*/

#include <list> // Para usar std::vector
#include "cinta.h"
#include "datoscompartidos.h"

#ifndef CONTROLADOR
#define CONTROLADOR

class controlador {
	private:
	    static controlador* instancia;
	    
	    datoscompartidos * dc;

	    std::list<cinta*> cintas;
	    //std::list<sensor*> sensores;    PROXIMAMENTE

	protected:
	    controlador();

	public:
		static controlador* GetInstance(); 
		int AgregarCinta(cinta *cinta);
		int EliminarCinta();
		int CantidadDeCintas();
};

#endif