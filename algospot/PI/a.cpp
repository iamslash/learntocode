#include <cstdio>
#include <string>
#include <vector>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <limits>
#include <cstddef>
        
using namespace std;

//const int INF = numeric_limits<int>::max();
const int INF = 987654321;

int get_lv(char N[10000], int n, int beg, int end)
{
    // 0. 모든 숫자가 같을 때 (예: 333, 5555) 난이도: 1
    bool b = true;
    char f = N[beg];
    for (int i=beg+1; i<=end; ++i)
    {
        if (f != N[i])
        {
            b = false;
            break;
        }
    }
    if (b) return 1;
    
    // 1. 숫자가 1씩 단조 증가하거나 단조 감소할 때 (예: 23456, 3210) 난이도: 2
    if (N[beg+1]-N[beg]==-1)
    {
        b = true;
        for (int i=beg+1; i<end; ++i)
        {
            if (N[i+1] - N[i] != -1)
            {
                b = false;
                break;
            }
        }
        if (b) return 2;
    }
    else if (N[beg+1]-N[beg]==1)
    {
        b = true;
        for (int i=beg+1; i<end; ++i)
        {
            if (N[i+1] - N[i] != 1)
            {
                b = false;
                break;
            }
        }
        if (b) return 2;
    }
    
    // 2. 두 개의 숫자가 번갈아 가며 출현할 때 (예: 323, 54545) 난이도: 4
    b = true;
    for (int i=2; i<=end-beg; ++i)
    {
        if (N[beg + (i%2)] != N[beg+i])
        {
            b = false; break;
        }
    }

    if (b) return 4;
    
    // 3. 숫자가 등차 수열을 이룰 때 (예: 147, 8642) 난이도: 5
    b = true;
    for (int i=beg+1; i<end; ++i)
    {
        if (N[beg+1]-N[beg] != N[i+1]-N[i])
        {
            b = false; break;
        }
    }

    if (b) return 5;


    // 그 외의 경우 난이도: 10    
    return 10;    
}

int get_result(int C[10000],
               char N[10000],
               int n,
               int idx)
{
    // base condition
    if (idx == n) return 0;
 
    // memoization
    int & r = C[idx];
    if (r >= 0) return r;

    // recursion
    r = INF;
    for(int i=3; i<6; ++i)
    {
        if (idx + i <= n)
        {
            int lv = get_lv(N, n, idx, idx + i - 1);
            r = min(r,
                    lv + get_result(C, N, n, idx + i));
            // printf("[%d, %d] %d\n", idx, idx+i-1, lv);
 
        }
    }
    
    return r;
}

int main() {
    
    int C; // number of cases
    scanf("%d", &C);
    
    for(int c=0; c<C; ++c)
    {
        int N;
        char INPUT[10000] = {0,};
        int CACHE[10002] = {0,};
        memset(CACHE, -1, sizeof(CACHE));

        scanf("%s", INPUT);
        N = strlen(INPUT);
        
        //printf("%s\n", INPUT);
        printf("%d\n", get_result(CACHE, INPUT, N, 0));
        // for (int i=2; i<5; ++i)
        //     printf("%d ", get_lv(INPUT, N, 0, i));
        // printf("\n");        
   }
  
    return 0;
}
