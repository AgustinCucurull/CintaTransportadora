/*

Esta es la interfaz de los estados de la cinta transportadora (.h)

*/

#include <iostream>
#ifndef ESTADO
#define ESTADO

class estado{

public:
	virtual void Mostrar();                			 		//Este estado deberia mostrar deberia devolver el estado actual
	//Para preguntar... Es un metodo de la propia cinta el establecer la velocidad de movimiento o solo el estado si esta detenido = 0 y en movimiento = 1.
	virtual void SetMovimiento(int mov) = 0;        	//Establece la velocidad de velocidad de la cinta, En caso de estar en 'apagado' o 'detenido', su vel = 0 
	virtual void SetSentido(int sen) = 0;		    	//Indica el sentido de movimiento reversa = -1, no_definido = 0 y avance = 1
	virtual void SetAlarma(int estado_de_la_alarma) = 0;	//El estado de la alarma puede ser 0 = apagado o 1 = encendido.

};

#endif