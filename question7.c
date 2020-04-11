#include <math.h>
#include <stdio.h>
#include <stdlib.h>

int is_prime(n) {
    long sq_root = (long) sqrt(n);    

    if (n < 2) {
        return 0;
    }

    if (n == 2) {
        return 1;
    }

    // if is even it's not a prime
    if(n % 2 == 0) {
        return 0;
    }
    
    for (int i = 2; i <= sq_root + 1; i++) {
        if (n % i == 0) {
            return 0;
        }
    }

    return 1;
}

int find_nth_prime(number, count, limit) {
    int new_number = number + 1;
    int new_nth = count;
    if (is_prime(number)) {
        printf("%d is prime: true\n", number);
        new_nth = count + 1;
    } else {
        printf("%d is prime: false\n", number);
    }

    if (new_nth == limit) {
        return number;
    }

    return find_nth_prime(new_number, new_nth, limit);
}

int main(int argc, char **argv) {
    long limit = atol(argv[1]);
    printf("%d\n", find_nth_prime(1, 0, limit));
}