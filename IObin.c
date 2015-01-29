#include "IObin.h"
#include <malloc.h>



size_t GetSize(char *value)
{
	 FILE* source = NULL;
    long int source_size = 0;
	source = fopen( value, "rb" );

	fseek( source, 0, SEEK_END );
	source_size = ftell( source );
	return source_size;
}

char *ReadBin(char* value, char* buf) {

    FILE* source = NULL; 
    long int source_size = 0;

    source = fopen( value, "rb" );
    if (!source) {  return NULL; }

    fseek( source, 0, SEEK_END );
    source_size = ftell( source );
    printf( "Source size is %ld\n", source_size );
    
    buf = (char*)malloc( source_size );   
    rewind( source );
	fread( buf, source_size, 1, source );
    fclose( source );

    return buf;
}

void WriteBin(char *filename, char* data, long int data_length)
{
    FILE* dest = NULL;
    long int source_size = 0;

    dest = fopen( filename, "wb" );
    if (!dest) { printf("Could not open file\n"); return; }

    rewind( dest );
	fwrite( data, data_length, 1, dest );

    fclose( dest );   
    return;
}

