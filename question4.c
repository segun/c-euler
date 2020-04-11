#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *itoa(int number) {
    int len = snprintf(NULL, 0, "%d", number);
    char *str = malloc(len + 1);

    snprintf(str, len + 1, "%d", number);
    return str;
}

int is_palindrome(char s[]) {
    //printf("is %s a palindrome?\n", s);
    int i = 0;
    int k = strlen(s) - 1;

    int mid = (k + 1) / 2;

    int count = 0;
    while (count <= mid) {
        if (s[i] == s[k]) {
            count++;
            i++;
            k--;
        } else {
            return 0;
        }

        if (i == k || i == mid || k == mid) {
            if (s[i] == s[k]) {
                printf("%s a palindrome?\n", s);
                return 1;
            } else {
                return 0;
            }
        }
    }

    return 0;
}

int largest_palindrome() {
    int max = 0;
    for (int i = 100; i <= 999; i++) {
        for (int j = i; j <= 999; j++) {
            int product = i * j;
            char *s = itoa(product);
            if (is_palindrome(s) && product > max) {
                max = product;
            }
        }
    }

    return max;
}

int main(int argc, char **argv) {
    printf("%d\n", is_palindrome("906609"));
    int lp = largest_palindrome();
    printf("%d\n", lp);
}