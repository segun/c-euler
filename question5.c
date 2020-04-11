#include <stdio.h>

long gcd(long a, long b) {
    if (b == 0) {
        return a;
    }

    return gcd(b, a % b);
}

long lcm(long a, long b) {
    if (b > a) {
        int temp = b;
        b = a;
        a = temp;
    }

    return (a/(gcd(a, b))) * b;
}

long smallest_positive_number() {
    long n = 1;
    for (int i = 1; i <= 20; i++) {
        n = lcm(n, i);
    }

    return n;
}

int main() {
    printf("%ld\n", smallest_positive_number());
    return 0;
}