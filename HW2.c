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
/*
void C_function(int64_t* a)
{
    free(a);
}
*/
int64_t* D_function(int64_t* size, int64_t* a, int64_t temp)
{
    *size = *size + 1;
    int64_t* y = realloc(a, *size * sizeof(int64_t));
    printf("For add element enter number\n");
    y[*size - 1] = temp;
    return y;
}


void distribution(int64_t* size, int64_t* a)
{
    int64_t size_b = 1;
    int64_t* b = (int64_t*)malloc(size_b * sizeof(int64_t));
    int64_t size_c = 1;
    int64_t* c = (int64_t*)malloc(size_c * sizeof(int64_t));
    int64_t size_zero = 1;
    int64_t* zero = (int64_t*)malloc(size_zero * sizeof(int64_t));
    for (int64_t index = 0; index < *size; index++)
    {
        if(a[index] > 0)
        {
            b[size_b-1]=a[index];
            size_b++;
            b = realloc(b, size_b * sizeof(int64_t));

        }
        else if(a[index] < 0)
        {
            c[size_c-1]=a[index];
            size_c++;
            c = realloc(c, size_c * sizeof(int64_t));
        }
        else
        {
            zero[size_zero-1]=a[index];
            size_zero++;
            zero = realloc(zero, size_zero * sizeof(int64_t));
        }
    }
    B_function(size_b, b);
    B_function(size_c, c);
    B_function(size_zero, zero);
}

int main()
{
    int64_t* a;
    int64_t size = 0;
    printf("Enter size\n");
    scanf("%lli", &size);
    srand(time(NULL));
    a = A_function(size);
    randomarray(size, a);
    B_function(size, a);
    distribution(&size, a);
    return 0;
}