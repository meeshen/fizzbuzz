#include<stdio.h>
#include<stdlib.h>
#include"fizz.c"

// fizzbuzz - works well up to 8 digits, "unsafe" with 9, partially wrong at 9+

int i;
int start = 1;
int stop = 100; // 99999999 = 0x5f5e0ff = safe limit

char out[9];

int main()
{
	for( i=start; i<stop+1; i++ )
	{
		fizz(i, out);
		printf("%s\n",out);
	}

	return 0;
}
