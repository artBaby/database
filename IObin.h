#ifndef IOBIN_H
#define IOBIN_H

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <time.h>
#include <string.h>
#include <windows.h>
//#include "treap.h"
#include "main.h"

//int buferr;
//int realwidth(int width);
//FILE* OpenF(char *filename);

//void LoadBMPData(unsigned char *image, unsigned int size, FILE *filename);
void WriteBin(char *filename, char* data, long int data_length);
char *ReadBin(char *value, char *buf);
size_t GetSize(char *value);


#endif // !IOBIN_H
