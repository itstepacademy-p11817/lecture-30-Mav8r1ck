#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<stdint.h>
#include <stdbool.h>

uint64_t* A_function(uint64_t size) 
{
	uint64_t* a = (uint64_t*)malloc(size * sizeof(uint64_t));
	return a;
}


void randomarray(uint64_t size, uint64_t* a)
{
	for (uint64_t st = 0; st < size; st++)
	{
		a[st] = rand() % 100;
	}

}

void B_function(uint64_t size, uint64_t* a)
{
	for (uint64_t st = 0; st < size; st++)
	{
		printf("%llu ", a[st]);
	}
	printf("\n\n");
}

void C_function(uint64_t* a)
{
	free(a);
}

uint64_t* D_function(uint64_t* size, uint64_t* a, uint64_t temp)
{
	*size = *size + 1;
	uint64_t* y = realloc(a, *size * sizeof(uint64_t));
	printf("For add element enter number\n");
	y[*size - 1] = temp;
	return y;
}

uint64_t* E_function(uint64_t* size, uint64_t* a, uint64_t temp, uint64_t index)
{
	*size = *size + 1;
	uint64_t* y = realloc(a, *size * sizeof(uint64_t));
	for (uint64_t i = (*size-1); i >= index; i--)
	{
		y[i] = y[i - 1];
	}
	y[index] = temp;
	return y;
}

uint64_t* F_function(uint64_t* size, uint64_t* a, uint64_t index)
{
	for (uint64_t i = index; i < *size; i++)
	{
		a[i] = a[i + 1];
	}
	*size = *size - 1;
	uint64_t* y = realloc(a, *size * sizeof(uint64_t));
	return y;
}

int main()
{
	uint64_t* a;
	uint64_t size = 0;
	printf("Enter size\n");
	scanf_s("%llu", &size);
	srand(time(NULL));
	a = A_function(size);
	randomarray(size, a);
	B_function(size, a);
	printf("For add element enter number\n");
	uint64_t temp = 0;
	scanf_s("%llu", &temp);
	a = D_function(&size, a, temp);
	B_function(size, a);
	printf("For add element enter number\n");
	scanf_s("%llu", &temp);
	printf("Enter index\n");
	uint64_t index = 0;
	scanf_s("%llu", &index);
	a = E_function(&size, a, temp, index);
	B_function(size, a);
	printf("For delete element enter index\n");
	scanf_s("%llu", &index);
	a = F_function(&size, a, index);
	B_function(size, a);
	system("pause");
	return 0;
}