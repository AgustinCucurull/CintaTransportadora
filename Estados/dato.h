/*
¿Porque me la complique creando una clase dato?

Porque es mucho mas sencillo hacerla crecer despues, yo trabajo con objetos del tipo dato, pero me abstraigo por un tiempo de que tiene y es
mas sencillo hacer crecer la cantidad de cosas que posee. Por ejemplo tiene el valor_medido pero podria dar mantener la hora de la medicion, pero
he incluso mas cosas. Voy a hacer la logica para que el arduino no trabaje se la complique con ese objeto, que solo me de el float o la fecha y listo

*/

#include <iostream>

#ifndef DATO
#define DATO

class dato {
private:
    float valor_medido;
    // hora h_m_s;    PROXIMAMENTE

public:
    dato();
    ~dato();
    void SetDato(float valor); 
    float GetDato(); 
    void ImprimirDato(); 
};

#endif
