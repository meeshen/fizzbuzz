void fizz( int num, char* str ) //str is type char[9]
{
	void* vp = str;

	if( num%3 == 0 )
	{		
		*(int*)vp = 0x7a7a6966; // 0x7a7a6966 = little-endian "fizz"
		vp += 4;
	}

	if( num%5 == 0 )
	{
		*(int*)vp = 0x7a7a7562; // 0x7a7a7562 = little-endian "buzz"
		vp += 4;
	}

	*(char*)vp = '\0';

	// if neither fizz or buzz then str terminates at 0
	if( str[0] == '\0' )
	{
		// "fun" dec2str converter (up to 8 digits)
		while( num != 0 )
		{
			*(long*)((char*)vp+1) = *(long*)vp; // shift array right
			*str = num%10 + 48; // places new digit at str start
			num /= 10; // next digit, will terminate when none left
		}
	}
}

