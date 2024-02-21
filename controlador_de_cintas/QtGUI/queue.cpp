#include "queue.h"

void queue::Load(const Data& Data) {
        queue.push(Data);
}

Data queue::TakeOut() {
        if (!queue.empty()) {
                Data Data = queue.front();
                queue.pop();

                return Data;
        }
}
