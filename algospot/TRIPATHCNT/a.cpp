#include <cstdio>
#include <string>
#include <vector>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <limits>
#include <cstddef>
        
using namespace std;

void dump(int I[][100], int N)
{
    for(int i=0; i<N; ++i)
    {
        for (int j=0; j<i+1; ++j)
        {
            printf("%d ", I[i][j]);
        }
        printf("\n");
    }
}

int get_max_path_cnt(int C_P[][101],
                     int I[][100],
                     int N, int y, int x)
{
    // memoization
    int & r = C_P[y][x];
    if (r >= 0) return r;

    // base condition
    if (y == N-1) return r = I[y][x];

    // recursion
    return r = I[y][x] + max(get_max_path_cnt(C_P, I, N, y+1, x),
                             get_max_path_cnt(C_P, I, N, y+1, x+1));
}

int get_result(int C_P[][101],
               int C_C[][100],
               int I[][100],
               int N, int y, int x)
{
    // base condition
    if (y == N-1) return 1;

    // memoization
    int & r = C_C[y][x];
    if (r >= 0) return r;

    r = 0;
    // recursion
    if (get_max_path_cnt(C_P, I, N, y+1, x) >=
        get_max_path_cnt(C_P, I, N, y+1, x+1))
    {
        r += get_result(C_P, C_C, I, N, y+1, x);
    }
    if (get_max_path_cnt(C_P, I, N, y+1, x) <=
        get_max_path_cnt(C_P, I, N, y+1, x+1))
    {
        r += get_result(C_P, C_C, I, N, y+1, x+1);
    }
    
    return r;
}

int main() {
    
    int C; // number of cases
    scanf("%d", &C);
    
    for(int c=0; c<C; ++c)
    {
        int N;
        int INPUT[100][100] = {0,};
        int CACHE_P[100][101] = {0,}; // cache for path score
        memset(CACHE_P, -1, sizeof(CACHE_P));
        int CACHE_C[100][100] = {0,}; // cache for max path count
        memset(CACHE_C, -1, sizeof(CACHE_C));

        scanf("%d", &N);

        for(int i=0; i<N; ++i)
            for (int j=0; j<i+1; ++j)
                scanf("%d", &INPUT[i][j]);

        // dump(INPUT, N);
        printf("%d\n", get_result(CACHE_P, CACHE_C, INPUT, N, 0, 0));
        // printf("%d\n", get_max_path_cnt(CACHE_P, INPUT, N, 0, 0));
   }
  
    return 0;
}
