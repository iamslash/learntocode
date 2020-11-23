#include <cstdio>
#include <string>
#include <vector>
#include <iostream>

using namespace std;

void dump(int B[][100], int N)
{
    for (int y=0; y<N; ++y)
    {
        for (int x=0; x<N; ++x)
        {
            printf("%d ", B[y][x]);
        }
        printf("\n");
    }
    printf("-----------\n");

}

bool is_path(int N, int C[][100], int B[][100], int x, int y)
{
    // printf("[%d] %d, %d\n", N, y, x);
    
    // base condition
    if (x == N-1 && y == N-1) return true;
    if (x >= N || y >= N) return false;

    int & r = C[y][x];
    if (r >= 0) return r;

    // recursion
    return r = is_path(N, C, B, x + B[y][x], y) ||
        is_path(N, C, B, x, y + B[y][x]);
}

int main() {
    
    int C; // number of cases
    
    scanf("%d", &C);
    
    for(int c=0; c<C; ++c)
    {
        int N;
        scanf("%d", &N);
        int B[100][100];
        int C[100][100];

        for (int y=0; y<N; ++y)
        {
            for (int x=0; x<N; ++x)
            {
                scanf("%d", &B[y][x]);
                C[y][x] = -1;
            }
        }

        // dump(B, N);
        
        printf("%s\n", is_path(N, C, B, 0, 0) == true ? "YES" : "NO");
    }
  
    return 0;
}
