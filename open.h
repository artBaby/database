#ifndef OPEN_H
#define OPEN_H

#include "main.h"
#include "treap.h"
#include <stdlib.h>
#include "memget.h"

char *readstrfromfile(FILE *file);
treap_t *openfromfile(char *path);
char *parsestr(FILE* file);


#endif // !OPEN_H
