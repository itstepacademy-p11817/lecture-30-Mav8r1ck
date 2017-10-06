#include<stdio.h>
#include<stdlib.h>


void B_function(uint64_t size, uint64_t* a)
{
    for (uint64_t st = 0; st < size; st++)
    {
        printf("%llu ", a[st]);
    }
    printf("\n\n");
}


void* finding_primes(uint64_t* start, uint64_t* stop)
{
    uint64_t size = 1;
    uint64_t* a = (uint64_t*)malloc(size * sizeof(uint64_t));

    for (uint64_t index = *start; index <= *stop; index++)
    {
        int counter = 0;
        for(uint64_t  j = 1; j <= index; j++)
        {
            if(index % j == 0)
            {
                counter++;
                if(counter > 2)
                {
                    break;
                }
            }
        }
        if(counter == 2)
        {
            a[size-1]=index;
            size++;
            a = realloc(a, size * sizeof(uint64_t));
        }
    }
    B_function(size, a);
}

int main()
{
    uint64_t start = 0;
    uint64_t stop = 0;
    printf("Enter start number\n");
    scanf("%llu", &start);
    printf("Enter stop number\n");
    scanf("%llu", &stop);
    finding_primes(&start, &stop);
    return 0;
}