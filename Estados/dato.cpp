#include "dato.h"

dato::dato(){

	this->valor_medido = 0.0;

}

//PROXIMAMENTE, SE LE PRODRIA DAR COMO PARAMETRO LA HORA TAMBIEN
void dato::SetDato(float valor_medido){

	this->valor_medido = valor_medido;

}

float dato::GetDato(){

	return this->valor_medido;

}

void dato::ImprimirDato(){

	std::cout << " : " << this->valor_medido << " : " << std::endl;

}
