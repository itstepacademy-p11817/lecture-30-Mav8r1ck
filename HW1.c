#include<stdio.h>
#include<stdlib.h>
#include<time.h>



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

uint64_t* removing_primes(uint64_t* size, uint64_t* a)
{
    for (uint64_t index = 0; index < *size; index++)
    {
        int counter = 0;
        for(uint64_t  j = 1; j <= a[index]; j++)
        {
            if(a[index] % j == 0)
            {
                counter++;
            }
        }
        if(counter == 2)
        {
            a = F_function(size, a, index);
        }
    }
    return a;
}

int main()
{
    uint64_t* a;
    uint64_t size = 0;
    uint64_t size_y = 1;
    printf("Enter size\n");
    scanf("%llu", &size);
    srand(time(NULL));
    a = A_function(size);
    randomarray(size, a);
    B_function(size, a);
    a = removing_primes(&size, a);
    B_function(size, a);
    return 0;
}