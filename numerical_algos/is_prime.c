#include<stdio.h>
#include<stdint.h>
#include<math.h>
#include<stdlib.h>
#include<stdbool.h>

#define debug_print(fmt, ...) \
	do { if (DEBUG) fprintf(stderr, fmt, __VA_ARGS__); } while (0)
#define DEBUG 0

int main()
{
	uint32_t i=0,number,stop,factor;
	bool arr[100];

	printf("Enter a number whose prime factors need to be found out\n");
	scanf("%u" ,&number);
	for(i=0;i<number;i++)
	{
		arr[i]=true;
		debug_print("value at location %u is %d\n" ,i,arr[i]);
	}

	stop = sqrt(number);
	factor = 2;
	
	while(factor<stop)
	{
		debug_print("value of factor inside main while is %u\n" ,factor);
		if(arr[factor]==true)
		{
			debug_print("if condition is true arr[factor] %d\n" ,arr[factor]);
			for(i=factor*factor;i<number;i++)
			{
				debug_print("inside for loop, value of i %u\n" ,i);
				if(i%factor == 0)
				{
					arr[i]=false;
					debug_print("inside final while, value at location %u is %d\n" ,i,arr[i]);
				}
			}
		}
		factor++;
	}

	printf("Prime factors for number entered by you are\n");
	for(i=2;i<number;i++)
	{
		if(arr[i]==true)
		{
			printf("%u\n" ,i);
		}
	}
	return 0;
}




