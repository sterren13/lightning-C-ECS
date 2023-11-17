//
// Created by arno on 11/16/23.
//

#ifndef ECS_ECSTYPE_H
#define ECS_ECSTYPE_H
#include <stdint.h>

#define MAX_ENTITIES 104856
#define MAX_ENTITY_COMPONENTS 4096
typedef uint32_t ECS_entity_t;
typedef uint32_t ECS_entity_ID_t;
typedef uint16_t ECS_entity_Version_t;
const ECS_entity_t ECS_entity_NULL = 0;

#define GET_ENTITY_ID(entity) ((entity) & 0xFFFFF)
#define GET_ENTITY_VERSION(entity) (((entity) >> 20) & 0xFFF)
#define SET_ENTITY_ID(entity, id) ((entity) = ((entity) & 0xFFF00000) | (id))
#define SET_ENTITY_VERSION(entity, version) ((entity) = ((entity) & 0x000FFFFF) | ((version) << 20))

typedef uint64_t ComponentID_t;

#endif //ECS_ECSTYPE_H
