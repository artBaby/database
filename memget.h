#ifndef MEMGET_H
#define MEMGET_H
#include "main.h"

kvp_t *memget(kvp_t *database, char* key, char* value, data_type_t data_type_t, size_t data_length);

#endif // !MEMGET_H
