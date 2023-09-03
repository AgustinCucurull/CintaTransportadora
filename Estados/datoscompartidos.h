/*

En este codigo creare la arquitectura de datos comportidos del tipo pizzara 

[IMPORTANTE: Volviendo a leer, aun estamos a tiempo de cambiarlo a repositorio

    > Repositorio: Si es el consumidor quien busca los datos

    > Pizzara: Suscripcion, la pizzara envia los datos

Me parece que seria mejor que cada cinta revise lo datos por si sola... 

].

El sistema de datos compartidos es quien mantiene un control de todos los datos. Pero no es quien mantiene la cantidad cintas. 

*/

#include "dato.h"
#include <list>

#ifndef DATOSCOMPARTIDOS
#define DATOSCOMPARTIDOS

class datoscompartidos {
    private:
        //ESTRUCTURA PARA ALMACENAR LOS DATOS
        //Los sensores deben enviar los datos en ese formato y las cintas lo deben poder leer
        //Lo voy a hacer como una lista de listas, estan las listas principales, una por cada sensor, ahi se van almacenando los datos <MANTIENE LOS DATOS>
        std::list<std::list<dato *> *> lista_de_almacenamiento;

        //ESTRUCTURA DE REGISTRO
        //Mantiene un control de las cintas y de los sensores existentes, mostrando que sensores son de interes por cada cinta.
        //La lista principal será igual al largo de las cintas, y cada uno tendra una lista con los id de los sensores a los que se suscribio
        
        //std::list<std::list<id_sensor *> *> registro_de_suscripcion;

        static datoscompartidos* instancia;

    protected:

        datoscompartidos();

    public:

        static datoscompartidos* getInstance(); 

        void EscribirDato(std::string id_sensor, dato valor);

        void EnviarDato(std::string id_cinta);

};

#endif