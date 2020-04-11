#include <stdio.h>

#define MAX 4000000

int sum_even(int n1, int n2, int acc) {
    int next = n1 + n2;

    if (next >= MAX) {
        return acc;
    }    

    acc = acc + (next % 2 == 0 ? next : 0);

    n1 = n2;
    n2 = next;    
    return sum_even(n1, n2, acc);
}

int main()
{
    int n1 = 1;
    int n2 = 2;
    int acc = 2;

    int se = sum_even(n1, n2, acc);

    printf("%d\n", se);

    return 0;
}