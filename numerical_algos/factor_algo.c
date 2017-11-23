#include<stdio.h>
#include<stdint.h>
#include<math.h>
#include<stdlib.h>

int main()
{
	uint32_t arr[100],i=0,number,stop,factor;

	printf("Enter a number whose factors need to be found\n");
	scanf("%u" ,&number);
	
	stop = sqrt(number);
	while(number%2 == 0)
	{
		arr[i]=2;
		number /= 2;
		i++;
	}
	factor = 3;
	while(factor<stop)
	{
		while(number%factor == 0)
		{
			arr[i]=factor;
			number /= factor;
			i++;
		}
		factor = factor + 2;
	}
	if(number != 1)
	{
		arr[i]=number;
		i++;
	}

	stop=i;
	i=0;
	printf("\nFactors are: \n");
	for(i=0;i<stop;i++)
	{
		printf("%u\n" ,arr[i]);
	}
}
	

