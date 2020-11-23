#include <cstdio>
#include <string>
#include <vector>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <limits>
#include <cstddef>
        
using namespace std;

int C;// case
int N, D, P; // town count, days, start town
int CON[50][50] = {0,};
int T; // end town count
int GOALTOWNS[50] = {0,}; 
double CACHE[51][51] = {0,}; // probability of town, days
int DEG[50] = {0.};

void dump(int CON[][50], int N)
{
    for(int y=0; y<N; ++y)
    {
        for(int x=0; x<N; ++x)
        {
            printf("%d ", CON[y][x]);
        }
        printf("\n");
    }
}
// days가 지나면 p에서 q까지 도착할 조건부 확률
double get_result(int p, int q, int days )
{
    // base condition
    if (days == N)
        return (p == q) ? 1.0 : 0.0;
    
    // memoization
    double & r = CACHE[p][days];
    if (r >= -0.5) return r;

    // recursion
    r = 0.0;
    for (int n=0; n<N; ++n)
    {
        if (CON[p][n] > 0)
            r += get_result(n, q, days+1) / DEG[p];
    }
    
    return r;
}

int main() {
    
    scanf("%d", &C);
    
    for(int c=0; c<C; ++c)
    {
        memset(CON, 0, sizeof(CON));
        memset(DEG, 0, sizeof(DEG));
        memset(GOALTOWNS, 0, sizeof(GOALTOWNS));
        memset(CACHE, -1, sizeof(CACHE));

        scanf("%d", &N);
        scanf("%d", &D);
        scanf("%d", &P);
        
        for(int y=0; y<N; ++y)
        {
            for(int x=0; x<N; ++x)
            {
                scanf("%d", &CON[y][x]);
                if (CON[y][x] > 0)
                    DEG[y]++;
            }
        }
        scanf("%d", &T);
        for(int x=0; x<T; ++x)
            scanf("%d", &GOALTOWNS[x]);
        
        for(int t=0; t<T; ++t)
        {
            printf("%0.8f ", get_result(P, GOALTOWNS[t], 1));
        }
        // dump(CON, N);
        // for(int y=0; y<N; ++y)
        //     printf("%d ", DEG[y]);
        printf("\n");
    }
  
    return 0;
}
