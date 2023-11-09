#ifdef __cplusplus
extern "C" {
#endif
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

/*
* Initialize a vector with pre-allocated size.
* When using vec functions, elemSize will be checked if SIZE_CHECK is defined.
* It will check in some functions like vec_append, vec_remove, vec_pop.
* @param v: pointer to vector
* @param preSize: pre-allocated size
* @param elemSize: size of each element
* @return: 1 if success, 0 if failed
* @note: if SIZE_CHECK is defined, elemSize will be checked when using vec functions
* @see: vec_init_t
*/
int vec_init(vec_t* v, index_t preSize, typeSize_t elemSize);

/*
* Initialize a vector with pre-allocated size.
* @param v: pointer to vector
* @param preSize: pre-allocated size
* @param type: type of each element
* @see vec_init
*/
#define vec_init_t(v, preSize, type) \
    vec_init(v, preSize, sizeof(type))

/*
* Resize a vector.
* If newCapacity is smaller than current size, the data will be discarded.
* @param v: pointer to vector
* @param newCapacity: new capacity
* @param elemSize: size of each element
* @note: if SIZE_CHECK is defined, elemSize will be checked when using vec functions
* @see: vec_resize_t
*/
void vec_resize(vec_t* v, index_t newCapacity, typeSize_t elemSize);

/*
* Resize a vector.
* @param v: pointer to vector
* @param newCapacity: new capacity
* @param type: type of each element
* @see vec_resize
*/
#define vec_resize_t(v, newCapacity, type) \
    vec_resize(v, newCapacity, sizeof(type))

/*
* Clear a vector.
* Set size to 0, but capacity remains unchanged.
* @param v: pointer to vector
*/
void vec_clear(vec_t* v);

/*
* Free a vector.
* the data will be freed.
* @param v: pointer to vector
*/
void vec_free(vec_t* v);

/*
* Append an element to the end of a vector.
* @note When SIZE_CHECK is defined, elemSize will be checked.
* @param v: pointer to vector
* @param data: pointer to data
* @param elemSize: size of each element
* @see: vec_append_t
*/
void vec_append(vec_t* v, void* data, typeSize_t elemSize);

/*
* Append an element to the end of a vector.
* @param v: pointer to vector
* @param data: pointer to data
* @param type: type of each element
* @see vec_append
*/
#define vec_append_t(v, data, type) \
    vec_append(v, data, sizeof(type))

/*
* Remove an element from a vector of given index.
* De function will move the last element to the position of the removed element.
* @note When SIZE_CHECK is defined, elemSize will be checked.
* @param v: pointer to vector
* @param index: index of element to be removed
* @param elemSize: size of each element
* @return: 1 if success, 0 if failed
* @see: vec_remove_t
*/
int vec_remove(vec_t* v, index_t index, typeSize_t elemSize);

/*
* Remove an element from a vector of given index.
* @param v: pointer to vector
* @param index: index of element to be removed
* @param type: type of each element
* @see vec_remove
*/
#define vec_remove_t(v, index, type) \
    vec_remove(v, index, sizeof(type))

/*
* Remove the last element from a vector.
* @note When SIZE_CHECK is defined, elemSize will be checked.
* @param v: pointer to vector
* @param elemSize: size of each element
* @see: vec_remove_back_t
*/
void* vec_remove_back(vec_t* v, typeSize_t elemSize);

/*
* Remove the last element from a vector.
* @param v: pointer to vector
* @param type: type of each element
* @see vec_remove_back
*/
#define vec_remove_back_t(v, type) \
    (type*)vec_remove_back(v, sizeof(type))

/*
* Get a element from a vector of given index.
* Wen index is out of range, NULL will be returned.
* @note When SIZE_CHECK is defined, elemSize will be checked.
* @note When SIZE_CHECK is defined, elemSize will be checked.
* @param v: pointer to vector
* @param index: index of element to be removed
* @param elemSize: size of each element
* @return: pointer to element
* @see: vec_get_t
*/
void* vec_get(vec_t* v, index_t index, typeSize_t elemSize);

/*
* Get a element from a vector of given index.
* @param v: pointer to vector
* @param index: index of element to be removed
* @param type: type of each element
* @return: pointer to element
* @note do not use in loop, it will bie slow. use vec_front_t and vec_back_t instead.
* @see vec_get
*/
#define vec_get_t(v, index, type) \
    ((type*)vec_get(v, index, sizeof(type)))

/*
* Set a element of a vector of given index.
* @note When SIZE_CHECK is defined, elemSize will be checked.
* @param v: pointer to vector
* @param index: index of element to be removed
* @param data: pointer to data
* @param elemSize: size of each element
* @see: vec_set_t
*/
void vec_set(vec_t* v, index_t index, void* data, typeSize_t elemSize); // TODO change return type to int and return 1 if success 0 if failed

/*
* Set a element of a vector of given index.
* @param v: pointer to vector
* @param index: index of element to be removed
* @param data: pointer to data
* @param type: type of each element
* @see vec_set
*/
#define vec_set_t(v, index, data, type) \
    vec_set(v, index, data, sizeof(type))

/*
* Get the size of a vector.
* @param v: pointer to vector
* @return: size of vector
*/
typeSize_t vec_size(vec_t* v);

/*
* Get the capacity of a vector.
* @param v: pointer to vector
* @return: capacity of vector
*/
typeSize_t vec_capacity(vec_t* v);

/*
* Get the first element of a vector.
* @note pinter whill change when capacity changes.
* @param v: pointer to vector
* @return: pointer to first element
* @see: vec_front_t
*/
void* vec_front(vec_t* v);

/*
* Get the first element of a vector.
* @param v: pointer to vector
* @param type: type of each element
* @return: pointer to data
* @see vec_front
*/
#define vec_front_t(v, type) \
    ((type*)vec_front(v))

/*
 * Get the last element of a vector.
 * @param v: pointer to vector
 * @param type: type of each element
 * @return: pointer to last element
 * @see: vec_end_t
*/
void* vec_end(vec_t* v, typeSize_t elemSize);

/*
 * Get the last element of a vector.
 * @param v: pointer to vector
 * @param type: type of each element
 * @return: pointer to last element
 * @see: vec_end
*/
#define vec_end_t(v, type) \
    ((type*)vec_end(v, sizeof(type)))

/*
* Get the back ptr of a vector.
* @param v: pointer to vector
* @param elemSize: size of each element
* @return: pointer to last element
* @see: vec_back_t
*/
void* vec_back(vec_t* v, typeSize_t elemSize);

/*
* Get the back ptr of a vector.
* @param v: pointer to vector
* @param type: type of each element
* @return: pointer to last element
* @see vec_back
*/
#define vec_back_t(v, type) \
    ((type*)vec_back(v, sizeof(type)))

#ifdef __cplusplus
}
#endif