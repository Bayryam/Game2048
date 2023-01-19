#include "Operations.h";


int getLengthOfString(const char* input)
{
	int len = 0;
	while (*input)
	{
		len++;
		input++;
	}
	return len;
}

char getSymbolFromDigit(int digit)
{
	return digit + '0';
}

int getNumberFromSymbol(char symbol)
{
	return symbol - '0';
}

void copyString(const char* source, char* dest)
{
	while (*source)
	{
		*dest = *source;
		dest++;
		source++;
	}
	*dest = '\0';
}

int getNumberLength(int number)
{
	int digits = 0;
	if (number == 0)
	{
		return 1;
	}

	while (number != 0)
	{
		number /= 10;
		digits++;
	}

	return digits;
}

