//
// Created by arno on 11/16/23.
//

#ifndef ECS_REGISTER_H
#define ECS_REGISTER_H
#include "storage/vec.h"
#include "storage/staticHashmap.h"
#include "ECS/ECSType.h"

typedef struct {
    vec_t* entities; // spare set of entities link to table and index in table
    StaticHashmap_t* components;
    vec_t* tables;
} ECS_register_t;

void ECS_register_init(ECS_register_t* rig);

void ECS_register_destroy(ECS_register_t* rig);

void ECS_register_component(ECS_register_t* rig, u_int64_t id);

ECS_entity_t ECS_register_new_entity(ECS_register_t* rig);

void ECS_register_destroy_entity(ECS_register_t* rig, ECS_entity_t entity);

void ECS_register_add_component(ECS_register_t* rig, ECS_entity_t entity, u_int64_t id, void* component, size_t size);

#define ECS_register_add_component_t(rig, entity, id, component) \
    ECS_register_add_component(rig, entity, id, component, sizeof(component))

void ECS_register_remove_component(ECS_register_t* rig, ECS_entity_t entity, u_int64_t id, size_t size);

#define ECS_register_remove_component_t(rig, entity, id, type) \
    ECS_register_remove_component(rig, entity, id, sizeof(type))

void* ECS_register_get_component(ECS_register_t* rig, ECS_entity_t entity, u_int64_t id);

#define ECS_register_get_component_t(rig, entity, id, type) \
    (type*)ECS_register_get_add_component(rig, entity, id, sizeof(type))

#endif //ECS_REGISTER_H
