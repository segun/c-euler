#include <stdio.h>
#include "p_euler.h"
#include <sys/time.h>

int is_multiple_of(int n1, int n2, int number_to_check)
{
    if (number_to_check % n1 == 0 || number_to_check % n2 == 0)
    {
        return 1;
    }

    return 0;
}

int sum_of_multiples(int n1, int n2, int max)
{
    int sum = 0;
    for (int i = 0; i <= max; i++)
    {
        if (is_multiple_of(n1, n2, i))
        {
            sum += i;
        }
    }

    return sum;
}

int sum_divisible_by_n(int n, int target)
{
    /**
     * say n = 3 and targe is 20, sum divisible by 3 = 3 + 6 + 9 + 12 + 15 + 18 = 3(1+2+3+4+5+6)
     * 1+2+3... is an arithmetric sum which is defined by n(n+1)/2
     * */

    int max = target / n;
    int arith_sum = (max * (max + 1)) / 2;
    return n * arith_sum;
}

int efficient_solution(int n1, int n2, int max)
{
    /**
     * Sum divisible by n1 and n2 is 
     * sum divisible by n1 + sum divisible by n2 - sum divisible by (n1 * n2)
     **/

    return sum_divisible_by_n(n1, max) + sum_divisible_by_n(n2, max) - sum_divisible_by_n((n1 * n2), max);
}

int main()
{
    struct timeval stop, start;
    gettimeofday(&start, NULL);    
    printf("Sum of mutiples of 3 and 5 below 1000: %d\n", sum_of_multiples(3, 5, 9999));
    gettimeofday(&stop, NULL);
    printf("took %lu us\n", (stop.tv_sec - start.tv_sec) * 1000000 + stop.tv_usec - start.tv_usec); 
    gettimeofday(&start, NULL);    
    printf("Efficient SOlution: Sum of mutiples of 3 and 5 below 1000: %d\n", efficient_solution(3, 5, 9999));
    gettimeofday(&stop, NULL);
    printf("took %lu us\n", (stop.tv_sec - start.tv_sec) * 1000000 + stop.tv_usec - start.tv_usec);     
    return 0;
}