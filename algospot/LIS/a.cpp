#include <cstdio>
#include <string>
#include <vector>
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

void dump(int I[], int N)
{
    for (int i=0; i<N; ++i)
        printf("%d ", I[i]);
    printf("\n");
}

int LIS(int I[], int C[], int N, int idx)
{
    // printf("[%d] %d\n", idx, I[idx]);
    
    // base condition
    int & r = C[idx];
    if (r >= 0) return r;

    r = 1;
    // recursion
    for (int n=idx+1; n<N; ++n)
    {
        if (I[idx] < I[n])
        {
            r = max(r, LIS(I, C, N, n) + 1);
        }
    }

    // printf("[%d] %d, %d\n", idx, I[idx], r);

    return r;
}


int get_result(int I[], int C[], int N)
{
    int r = 0;
    for(int i=0; i<N; ++i)
        r = max(r, LIS(I, C, N, i));
    return r;   
}

int main() {
    
    int C; // number of cases
    scanf("%d", &C);
    
    for(int c=0; c<C; ++c)
    {
        int N;
        int INPUT[500] = {0,};
        int CACHE[500] = {0,};
        memset(INPUT, 0, sizeof(INPUT));
        memset(CACHE, -1, sizeof(CACHE));
        scanf("%d", &N);

        for (int n=0; n<N; ++n)
        {
            scanf("%d", &INPUT[n]);
        }

        // dump(INPUT, N);
        
        printf("%d\n", get_result(INPUT, CACHE, N));
   }
  
    return 0;
}
