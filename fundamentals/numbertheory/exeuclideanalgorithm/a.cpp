// Copyright (C) 2017 by iamslash
// https://en.wikibooks.org/wiki/Algorithm_Implementation/Mathematics/Extended_Euclidean_algorithm#Recursive_algorithm

#include <cstdio>
#include <cstdlib>

#include <cstdio>
#include <cstdlib>

int xgcd(int a, int b, int& x, int &y) {
    // baseb condition
    if (b == 0) {
        x = 1;
        y = 0;
        printf("%d = %d * %d + %d * %d\n", a, a, x, b, y); 
        return a;
    }

    // recursion
    int x1, y1;
    int gcd = xgcd(b, a%b, x1, y1);
    x = y1;
    y = x1 - a/b * y1;
    printf("%d = %d * %d + %d * %d\n", gcd, a, x, b, y);
    return gcd;
}

int main() {
    int a = 1020, b = 790;
    int x, y;
    int gcd = xgcd(a, b, x, y);
    return 0;
}

// 10 = 10 * 1 + 0 * 0
// 10 = 30 * 0 + 10 * 1
// 10 = 100 * 1 + 30 * -3
// 10 = 230 * -3 + 100 * 7
// 10 = 790 * 7 + 230 * -24
// 10 = 1020 * -24 + 790 * 31
