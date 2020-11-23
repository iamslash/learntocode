//https://algospot.com/judge/problem/read/ARCTIC

#include <cstdio>
#include <string>
#include <vector>
#include <iostream>
#include <cstring>
#include <algorithm>
// #include <set>
#include <cmath>
#include <queue>

using namespace std;

int N;

const double PI = acos(-1.0);

double area(int M, int S, int C) {
    double x = (-S*S + M*M + C*C) / 2.0 / C;
    double y = sqrt(abs(M*M - x*x));
    double theta = 2.0 * acos(x / M);

    double circle = PI * M * M;
    double arch = circle * theta / 2 / PI;
    double triangle  = x * y;

    return arch - triangle;
}

// 
int main() {
    
    int T; // number of T
    scanf("%d", &T);
    
    for(int t=0; t<T; ++t)
    {
        double M, S, C;

        scanf("%lf", &M);
        scanf("%lf", &S);
        scanf("%lf", &C);
        
        double circle = PI * M * M;
        double left = area(M, S, C);
        double right = area(S, M, C);

        printf("%0.3f\n", circle - left - right);
     }

    return 0;
}
