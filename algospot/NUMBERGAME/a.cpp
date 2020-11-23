// //https://algospot.com/judge/problem/read/NUMBERGAME

#include <cstdio>
#include <string>
#include <vector>
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int EMPTY = -987654321;
int N, BOARD[50];
int CACHE[50][50];

int play(int left, int right)
{
    //printf(" %d, %d\n", left, right);
    
    // base condition
    if (left > right) return 0;

    // memoization
    int& r = CACHE[left][right];
    if (r != EMPTY) return r;

    // recursion
    r = max(BOARD[left] - play(left + 1, right),
            BOARD[right] - play(left, right - 1));

    //
    if (right - left + 1 >= 2)
    {
        r = max(r, -play(left+2, right));
        r = max(r, -play(left, right-2));
    }
    
    return r;
}

int main() {
    
    int C; // number of cases
    scanf("%d", &C);
    
    for(int c=0; c<C; ++c)
    {
        // init chache
        for (int i=0; i<50; ++i)
            for (int j=0; j<50; ++j)
                CACHE[i][j] = EMPTY;

        scanf("%d", &N);
        // input datas
        for(int i=0; i<N; ++i)
        {
            scanf("%d", &BOARD[i]);
        }

        printf("%d\n", play(0, N-1));
    }
  
    return 0;
}
