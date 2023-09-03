#include <iostream>
#include "cinta.h"

#ifndef CTRANSPORTE
#define CTRANSPORTE

class ctransporte : public cinta{
public:
	ctransporte();
	~ctransporte(){}

	void Mostrarse();
};

#endif