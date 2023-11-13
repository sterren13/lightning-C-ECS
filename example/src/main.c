#include <stdio.h>
#include "staticHashmap.h"
#include "Hash/hashFunctions.h"
#include "Hash/xxhash.h"
#include "Hash/City.h"
#include "component.h"
#include "vec.h"
#include <string.h>

uint64_t hashString(char* string) {
    int len = (int)strlen(string);
    //return MurmurHash64( string, len, 0);
    return XXH64(string, len, 0);
    //return CityHash64(string, len);
}

int main(int argc, char **argv) {

    StaticHashmap_entry_t entries[] = {
            {hashString("position"), "test position"},
            {hashString("velocity"), "test velocity"},
            {hashString("acceleration"), "test acceleration"},
            {hashString("test"), "test test"},
            {hashString("test2"), "test test2"},
            {hashString("test3"), "test test3"},
            {hashString("test4"), "test test4"},
            {hashString("test5"), "test test5"},
            {hashString("test6"), "test test6"},
            {hashString("test7"), "test test7"},
            {hashString("test8"), "test test8"},
            {hashString("test9"), "test test9"}
    };
    StaticHashmap_t map;
    StaticHashmap_init(entries, sizeof(entries) / sizeof(StaticHashmap_entry_t), &map);

    printf("%s\n", (char*)StaticHashmap_get(&map, hashString("position")));
    printf("%s\n", (char*)StaticHashmap_get(&map, hashString("velocity")));
    printf("%s\n", (char*)StaticHashmap_get(&map, hashString("acceleration")));
    printf("%s\n", (char*)StaticHashmap_get(&map, hashString("test")));
    printf("%s\n", (char*)StaticHashmap_get(&map, hashString("test2")));
    printf("%s\n", (char*)StaticHashmap_get(&map, hashString("test3")));
    printf("%s\n", (char*)StaticHashmap_get(&map, hashString("test4")));
    printf("%s\n", (char*)StaticHashmap_get(&map, hashString("test5")));
    printf("%s\n", (char*)StaticHashmap_get(&map, hashString("test6")));
    printf("%s\n", (char*)StaticHashmap_get(&map, hashString("test7")));
    printf("%s\n", (char*)StaticHashmap_get(&map, hashString("test8")));
    printf("%s\n", (char*)StaticHashmap_get(&map, hashString("test9")));

    StaticHashmap_free(&map);

    return 0;
}