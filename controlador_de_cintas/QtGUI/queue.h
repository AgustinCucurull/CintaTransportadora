#include <iostream>
#include <queue>
#include "data.h"

#ifndef QUEUE_H
#define QUEUE_H

// Creamos una clase que gestione la queue y sus operaciones
class queue {
private:
    std::queue<Data> queue;

public:
    // Método para cargar datas a la queue
    void Load(const Data& Data);

    // Método para sacar datas de la queue
    Data TakeOut();
};

#endif // QUEUE_H
