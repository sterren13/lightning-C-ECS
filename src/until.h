#include <stdlib.h>

/*
* allocate memory
* @param size: size of memory
* @return: pointer to memory
*/
#define ecs_malloc(size) malloc(size)

/*
* free memory
* @param ptr: pointer to memory
*/
#define ecs_free(ptr) free(ptr)

/*
* reallocate memory
* @param ptr: pointer to memory
* @param size: size of memory
* @return: pointer to memory
*/
#define ecs_realloc(ptr, size) realloc(ptr, size)

/*
* allocate memory and set to zero
* @param size: size of memory
* @return: pointer to memory
*/
#define ecs_calloc(size) calloc(1, size)

/*
* copy memory
* @param dst: destination pointer
* @param src: source pointer
* @param size: size of memory
*/
#define ecs_memcopy(dst, src, size) memcpy(dst, src, size)