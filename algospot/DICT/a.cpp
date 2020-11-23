//https://algospot.com/judge/problem/read/DICT

#include <cstdio>
#include <string>
#include <vector>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <limits>
#include <cstddef>

// k에서 빼기연산을 해야한다. k-BC[][]값이 ???
const int MAX_K = 1000000000 + 100; // ???

using namespace std;

int C;// case

int BC[201][201] = {0,}; // [n][m] : binomial coefficient

void init_BC()
{
    // init 
    memset(BC, 0, sizeof(BC));

    // nCr = n-1Cr-1 + n-1Cr
    for (int n=0; n<=200; ++n)
    {
        BC[n][0] = BC[n][n] = 1;

        for (int r=1; r<n; ++r)
        {
            BC[n][r] = min(MAX_K, BC[n-1][r-1] + BC[n-1][r]);
        }
    }
}

void dump_BC(int N, int M)
{
    for (int n=0; n<=N; ++n)
    {
        for (int m=0; m<=M; ++m)
            printf("%d ", BC[n][m]);
        printf("\n");
    }
}


// return k th string
// n을 기준으로 경우의수를 따지기
string get_result(int n, int m, int k)
{
    if (BC[n+m][n] < k) return "NONE";
    
    // printf("%d %d %d\n", n, m, k);
    // printf(" %d\n", BC[n+m-1][n-1]);

    // base condition
    if (n == 0) return string(m, 'b');
    // recursion
    if (k <= BC[n+m-1][n-1])
        return "a" + get_result(n-1, m, k);
    return "b" + get_result(n, m-1, k-BC[n+m-1][n-1]); 
}

int main() {

    init_BC();
    //dump_BC();

    scanf("%d", &C);
    
    for(int c=0; c<C; ++c)
    {
        int N, M, K;
        
        // input
        scanf("%d", &N);
        scanf("%d", &M);
        scanf("%d", &K);

        // print result
        printf("%s\n", get_result(N, M, K).c_str());
    }
  
    return 0;
}
