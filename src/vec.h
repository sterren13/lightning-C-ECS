#include <stdlib.h>
#define SIZE_CHECK
typedef size_t index_t;
typedef size_t typeSize_t;

typedef struct vec_t {
    void* data;
    index_t size;
    index_t capacity;
#ifdef SIZE_CHECK
    typeSize_t elemSize;
#endif
} vec_t;

int vec_init(vec_t* v, index_t preSize, typeSize_t elemSize, typeSize_t alignment);
void vec_resize(vec_t* v, index_t newCapacity, typeSize_t elemSize);
void vec_append(vec_t* v, void* data, typeSize_t elemSize);