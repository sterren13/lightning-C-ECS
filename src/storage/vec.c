#include "storage/vec.h"
#include "until.h"
#include <assert.h>

int vec_init(vec_t* v, index_t preSize, typeSize_t elemSize) {
    v->capacity = preSize;
    v->size = 0;
    #ifdef SIZE_CHECK
        v->elemSize = elemSize;
    #endif
    int a = posix_memalign((void**)&v->data, 64,preSize * elemSize);
    assert(a == 0);
    if (v->data == NULL)
        return 0;
    return 1;
}

void vec_resize(vec_t* v, index_t newCapacity, typeSize_t elemSize) {
    #ifdef SIZE_CHECK
        assert(v->elemSize == elemSize);
    #endif
    v->capacity = newCapacity;
    void* newPtr = nullptr;
    int a = posix_memalign(&newPtr, 64,newCapacity * elemSize);
    assert(a == 0);
    memcpy(newPtr, (void*)v->data, v->size * elemSize);
    free(v->data);
    v->data = newPtr;
}

void vec_clear(vec_t* v) {
    v->size = 0;
}

void vec_free(vec_t* v) {
    ecs_free(v->data);
    v->data = NULL;
    v->size = 0;
    v->capacity = 0;
}

void vec_append(vec_t* v, void* data, typeSize_t elemSize) {
    #ifdef SIZE_CHECK
        assert(v->elemSize == elemSize);
    #endif
    if (v->size == v->capacity) {
        vec_resize(v, v->capacity * 2, elemSize);
    }
    ecs_memcopy(v->data + v->size * elemSize, data, elemSize);
    v->size++;
}

int vec_remove(vec_t* v, index_t index, typeSize_t elemSize) {
    #ifdef SIZE_CHECK
        assert(v->elemSize == elemSize);
    #endif
    if (index >= v->size)
        return 0;
    ecs_memcopy(v->data + (index * elemSize), v->data + ((v->size-1)*elemSize), elemSize);
    v->size--;
    return 1;
}

void* vec_remove_back(vec_t* v, typeSize_t elemSize) {
    #ifdef SIZE_CHECK
        assert(v->elemSize == elemSize);
    #endif
    if (v->size == 0)
        return NULL;
    v->size--;
    return v->data + (v->size * elemSize);
}

void* vec_get(vec_t* v, index_t index, typeSize_t elemSize) {
    #ifdef SIZE_CHECK
        assert(v->elemSize == elemSize);
    #endif
    if (index >= v->size)
        return NULL;
    return v->data + (index * elemSize);
}

void vec_set(vec_t* v, index_t index, void* data, typeSize_t elemSize) {
    #ifdef SIZE_CHECK
        assert(v->elemSize == elemSize);
    #endif
    if (index >= v->size)
        return;
    ecs_memcopy(v->data + (index * elemSize), data, elemSize);

}

typeSize_t vec_size(vec_t* v) {
    return v->size;
}

typeSize_t vec_capacity(vec_t* v) {
    return v->capacity;
}

void* vec_front(vec_t* v) {
    if (v->size == 0)
        return NULL;
    return v->data;
}

void* vec_end(vec_t* v, typeSize_t elemSize) {
    #ifdef SIZE_CHECK
        assert(v->elemSize == elemSize);
    #endif
    if (v->size == 0)
        return NULL;
    return v->data + ((v->size-1) * elemSize);
}

void* vec_back(vec_t* v, typeSize_t elemSize) {
    #ifdef SIZE_CHECK
        assert(v->elemSize == elemSize);
    #endif
    if (v->size == 0)
        return NULL;
    return v->data + ((v->size) * elemSize);
}