#include<stdio.h>
#include<stdint.h>

int main()
{
	uint32_t a=12,b=54,remainder=0;
	uint32_t lcm_a=a, lcm_b=b,lcm;
	while(b != 0)
	{
		printf("a: %u\tb: %u\tremainder: %u\n" ,a,b,remainder);
		remainder=a%b;
		a=b;
		b=remainder;
	}
	printf("GCD of given numbers is %u\n", a);
	lcm = (lcm_a/a)*lcm_b;
	printf("LCM of given numbers is %u\n", lcm);
	return 0;
}


