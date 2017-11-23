#include<stdio.h>
#include<stdint.h>

int main()
{
	uint32_t a=57654390,b=712345990,remainder=0;

	while(b != 0)
	{
		printf("a: %u\tb: %u\tremainder: %u\n" ,a,b,remainder);
		remainder=a%b;
		a=b;
		b=remainder;
	}
	printf("GCD of given numbers is %u\n", a);
	return 0;
}


