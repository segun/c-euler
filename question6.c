#include <stdio.h>
#include <stdlib.h>

/**
 * The difference between sum of squares and square of sums can be broken down into
 * (a + b  + c + d)^2 - a^2 + b^2 + c^2 + d^2
 * a^2 + b^2 + c^2 + d^2 2ab + 2ac + 2ad + 2bc + 2bd + 2cd - a^2 + b^2 + c^2 + d^2
 * 
 * This means all the  squares cancel out leaving us with 
 * 2ab + 2ac + 2ad + 2bc + 2bd + 2cd
 * 
 * This is represented in the algorith below
 * */
long sum_square_difference(int start, int end) {
    long sum = 0;
    for (int i = start; i <= end; i++) {
        for (int j = (i + 1); j <= end; j++) {
            sum += 2 * i * j;
        }
    }

    return sum;
}

int main (int args, char **argv) {
    int start = atoi(argv[1]);
    int end = atoi(argv[2]);

    printf("%ld\n", sum_square_difference(start, end));
}