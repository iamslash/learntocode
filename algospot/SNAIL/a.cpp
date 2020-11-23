#include <cstdio>
#include <string>
#include <vector>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <limits>
#include <cstddef>
        
using namespace std;

int N, M; // 거리, 
double CACHE[1000][2001]; // days, climbed

double get_result(double C[][2001], int N, int M, int days, int climbed)
{
    // base condition
    if (days == M + 1)
    {
        if (climbed >= N)
            return 1.0;
        else
            return 0.0;
    }
    
    // memoization
    double & r = C[days][climbed];
    if (r >= -0.5) return r;

    // printf("%d %d\n", days, climbed);
    
    // recursion
    return r = (double)0.75 * get_result(C, N, M, days+1, climbed + 2) +
        (double)0.25 * get_result(C, N, M, days+1, climbed + 1);
}

int main() {
    
    int C; // number of cases
    scanf("%d", &C);
    
    for(int c=0; c<C; ++c)
    {
        memset(CACHE, -1.0, sizeof(CACHE));

        scanf("%d", &N);
        scanf("%d", &M);
        printf("%0.10f\n", get_result(CACHE, N, M, 1, 0));
    }
  
    return 0;
}
