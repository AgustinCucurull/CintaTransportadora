#include "controlador.h"

controlador* controlador::instancia = nullptr;

controlador::controlador(){

		std::cout<< "Se ha creado un controlador" << std::endl;

		this->dc = datoscompartidos::getInstance();   //Cuando se crea un nuevo controlador automagicamente se crea una pizarra.

}

//Es quien permite crear un nuevo controlador
controlador* controlador::GetInstance() {

    if (instancia == nullptr) {
    
        instancia = new controlador;
    
    }
    
    return instancia;
}


//Agrega una nueva cinta
int controlador::AgregarCinta(cinta * cinta){

	int lantes = this->cintas.size();

	this->cintas.push_back(cinta);

	if(lantes < this->cintas.size()){

			return 0;

	} else {

			return 1;

	}

}

int controlador::CantidadDeCintas(){

		return this->cintas.size();

}

//Elimina la cinta del indice dado. ESTA VA A CAMBIAR EN UN FUTURO. MI IDEA ES QUE SE PUEDA ELIMINAR LAS CINTAS DESDE UN BOTON EN LA INTERFAZ
//PERO NECESITO PROBAR QUE SI SE PUEDAN SACAR CINTAS DE LA cintas 
int controlador::EliminarCinta(){

		if (!this->cintas.empty()){
			
				int indice;

				std::cout << "Por favor, ingrese un indice entre 0 y " << this->cintas.size() - 1 << std::endl;

				std::cin >> indice;

				if ((0 <= indice) && (indice < this->cintas.size())){
					
						std::list<cinta *>::iterator iterador = this->cintas.begin();
						
						std::advance(iterador, indice);

						this->cintas.erase(iterador);

						return 0;

				} else {

						std::cout << "La posicion ingresada esta fuera de rango" << std::endl;

						return 1;

				}

		} else {

				std::cout << "No se puede eliminar de una cintas sin cintas" << std::endl;

				return -1;

		}

}