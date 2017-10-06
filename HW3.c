#include<stdio.h>
#include<stdlib.h>
#include<time.h>



int64_t* A_function(int64_t size)
{
    int64_t* a = (int64_t*)malloc(size * sizeof(int64_t));
    return a;
}


void randomarray(int64_t size, int64_t* a)
{
    for (int64_t st = 0; st < size; st++)
    {
        a[st] = rand() % 50-25;
    }

}

void B_function(int64_t size, int64_t* a)
{
    for (int64_t st = 0; st < size; st++)
    {
        printf("%lli ", a[st]);
    }
    printf("\n\n");
}

void C_function(int64_t* a)
{
    free(a);
}

int64_t* D_function(int64_t* size, int64_t* a, int64_t temp)
{
    *size = *size + 1;
    int64_t* y = realloc(a, *size * sizeof(int64_t));
    printf("For add element enter number\n");
    y[*size - 1] = temp;
    return y;
}


void* positive_without_repetitions(int64_t* size, int64_t* a, int64_t* b)
{
    int64_t size_c = 1;
    int64_t* c = (int64_t*)malloc(size_c * sizeof(int64_t));

    for (int64_t index = 0; index < *size; index++)
    {
        int64_t counter = 0;
        if(a[index] > 0)
        {
            for(int64_t index_c = 0; index_c < size_c; index_c++)
            {
                if(a[index] == c[index_c])
                {
                    counter++;
                    break;
                }
            }
            if(counter == 0)
            {
                c[size_c - 1] = a[index];
                size_c++;
                c = realloc(c, size_c * sizeof(int64_t));
            }
        }
    }
    for (int64_t index = 0; index < *size; index++)
    {
        int64_t counter = 0;
        if(b[index] > 0)
        {
            for(int64_t index_c = 0; index_c < size_c; index_c++)
            {
                if(b[index] == c[index_c])
                {
                    counter++;
                    break;
                }
            }
            if(counter == 0)
            {
                c[size_c - 1] = b[index];
                size_c++;
                c = realloc(c, size_c * sizeof(int64_t));
            }
        }
    }
    B_function(size_c, c);
    C_function(c);
}

int main()
{
    int64_t* a;
    int64_t* b;
    int64_t size = 0;
    printf("Enter size for array\n");
    scanf("%lli", &size);
    srand(time(NULL));
    a = A_function(size);
    b = A_function(size);
    randomarray(size, a);
    randomarray(size, b);
    B_function(size, a);
    B_function(size, b);
    positive_without_repetitions(&size, a, b);
    C_function(a);
    C_function(b);
    return 0;
}