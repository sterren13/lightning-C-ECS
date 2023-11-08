#include "vec.h"

int vec_init(vec_t* v, index_t preCapacity, typeSize_t elemSize, typeSize_t alignment) {
    v->capacity = preCapacity;
    v->size = 0;
    v->data = malloc(elemSize*preCapacity);
    if (!v->data)
        return 0;
    #ifdef SIZE_CHECK
        v->elemSize = elemSize;
    #endif
    return 1;
}

void vec_resize(vec_t* v, index_t newCapacitye, typeSize_t elemSize) {
    v->capacity = newCapacitye;
    v->data = realloc(v->data, newCapacitye);
}

void vec_append(vec_t* v, void* data, typeSize_t elemSize) {

}