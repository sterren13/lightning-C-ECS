//
// Created by arno on 11/16/23.
//
#include "ECS/register.h"
#include "ECS/table.h"

typedef struct {
    u_int64_t id;
    ECS_table_index_t index;
} ECS_register_entity_t;

void ECS_register_init(ECS_register_t* rig) {
    rig->entities = aligned_alloc(64, sizeof(ECS_register_entity_t) * MAX_ENTITIES);
}

void ECS_register_destroy(ECS_register_t* rig) {
    free(rig->entities);
}

void ECS_register_component(ECS_register_t* rig, u_int64_t id) {

}

ECS_entity_t ECS_register_new_entity(ECS_register_t* rig){

}

void ECS_register_destroy_entity(ECS_register_t* rig, ECS_entity_t entity) {

}

void ECS_register_add_component(ECS_register_t* rig, ECS_entity_t entity, u_int64_t id, void* component, size_t size) {

}

void ECS_register_remove_component(ECS_register_t* rig, ECS_entity_t entity, u_int64_t id, size_t size) {

}

void* ECS_register_get_component(ECS_register_t* rig, ECS_entity_t entity, u_int64_t id) {

}
