#include "main.h"

void add_input(void) {
    char c;
	int count_quot;
	count_quot = 0;
    while ( scanf("%c", &c) == 1 /*&& c!= '\n'*/ ) {
		if ( c == '\"') count_quot++;
		if ( count_quot == 4) break;
	}  
}

int ident_str(char *str) {
	int i, count;
	count = 0;
	
	for (i = 0; i < strlen(str); ++i)
	{
		if (str[i] == '\"')
			count++;		
	}
	if (count == 2) return 2;		//2 " - means that value is a num
	else if (count == 4) return 4;	//4 " - means that value is a str or bin_dat
	else if (count == 3) return 3;
	else return count;					//other - syntax error
}

char *get_str(char *str) {	
    char *enter = strrchr(str, '\n');
    if (enter)
        *enter = '\0';
    return str;
}
