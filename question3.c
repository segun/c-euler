#include <math.h>
#include <stdio.h>
#include <stdlib.h>

long find_largest_prime_factor(long number, long prime) {    
    printf("Finding Largest Prime. [%ld, %ld] \n", number, prime);

    if(number == prime) {
        return prime;
    }

    long sq_root = (long) sqrt(number);

    if (prime > sq_root) {
        // if there are no factors from 2 to sqrt(N) then N is a prime number
        return number;
    }

    // divide by prime, is there a remainder?
    long rem = number % prime;
    if (rem > 0) {
        return find_largest_prime_factor(number, ++prime);
    } else {
        long newFactor = (number / prime);
        return find_largest_prime_factor(newFactor, prime);
    }
}

int main(int argc, char *argv[]) {     
    long number = atol(argv[1]);
    printf("Largest Primt Factor For: %ld \n", number);
    printf("Largest Prime Factor = %ld \n", find_largest_prime_factor(number, 2));
    return 0; 
}