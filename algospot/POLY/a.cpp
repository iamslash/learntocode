#include <cstdio>
#include <string>
#include <vector>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <limits>
#include <cstddef>

const int MOD = 10000000;

using namespace std;

int C;// case
int N; 
int CACHE[101][101] = {0,}; // 

// 첫번째 줄의 사격형의 수는 fir이다.
// 두번째 줄의 사격형의 수는 sec이다.
// n은 fir를 포함한 사격형의 수이다.
int poly(int n, int fir)
{
    // base condition
    if (n == fir) return 1;

    // memoization
    int & r = CACHE[n][fir];
    if (r >= 0) return r;

    // recursion
    r = 0;

    for (int sec=1; sec<=n-fir; ++sec)
    {
        int extra = fir + sec - 1;
        int r_sub = extra * poly(n-fir, sec);
        r_sub %= MOD;
        r += r_sub;
        r %= MOD;
    }
    
    return r;
}

int get_result()
{
    int r = 0;
    for (int i=1; i<=N; ++i)
    {
        r += poly(N, i);
        r %= MOD;
    }
    return r;
}

int main() {
    
    scanf("%d", &C);
    
    for(int c=0; c<C; ++c)
    {
        memset(CACHE, -1, sizeof(CACHE));

        scanf("%d", &N);

        printf("%d\n", get_result());
    }
  
    return 0;
}
