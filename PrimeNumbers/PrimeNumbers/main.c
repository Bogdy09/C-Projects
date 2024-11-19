#include <stdio.h>

int prime_number(int n)
{
    if(n==2)
        return 1;
    if(n<2)
        return 0;
    if(n%2==0)
        return 0;
    for(int i=3;i*i<=n;i+=2)
        if(n%i==0)
            return 0;
    return 1;
}

int relatively_prime(int a, int b)
{
    while(b!=0)
    {
        int r=a%b;
        a=b;
        b=r;
    }
    return a;
}

int a(int n)
{
    int i=2;
    while(n>0)
    {
        if(prime_number(i)) {
            printf("%d ", i);
            n--;
        }
        i++;
    }
    printf("\n");
    return 0;
}

int b(int v[], int i)
{
    int start=0, end, max=0, maxstart, maxend;
    for(int j=0;j<i-1;j++)
    {
        if(relatively_prime(v[j], v[j+1])==1)
        {
            end=j+1;
            if(end-start+1>=max) {
                max = end - start + 1;
                maxstart = start;
                maxend = end;
            }

        }
        else
        {
            start=j+1;
        }

    }
    for(int j=maxstart; j<=maxend;j++)
        printf("%d ", v[j]);
    printf("\n");
    return 0;
}
int read(int v[])
{
    int i=0;
    int x;
    printf("\nPlease enter a number: ");
    scanf("%d", &x);
    while(x!=-1)
    {
        v[i++]=x;
        printf("Please enter a number: ");
        scanf("%d", &x);
    }
    for(int j=0;j<i;j++)
    {
        printf("%d ", v[j]);
    }
    printf("\n");
    return i;
}


int main()
{
    while(1) {
        printf("1. Read a vector:");
        printf("\n2. First functionality:");
        printf("\n3. Second functionality:");
        printf("\n0. Exit");
        printf("\nPlease choose an option: ");
        int x;
        scanf("%d", &x);
        int v[100], i;
        while (x < 0 || x > 3) {
            printf("\nInvalid choice. Please choose an option again: ");
            scanf("%d", &x);
        }
        if (x == 1) {
            i=read(v);
        }
        if (x == 2) {
            int n;
            printf("Please enter a number:");
            scanf("%d", &n);
            a(n);
        }
        if (x == 3) {
            b(v, i);
        }
    }
}
