#include <cstdio>
#include <string>
#include <vector>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <limits>
#include <cstddef>
        
using namespace std;

const long long LLMIN = numeric_limits<long long>::min();

void dump(int I[], int N)
{
    for (int i=0; i<N; ++i)
        printf("%d ", I[i]);
    printf("\n");
}

int get_result(int C[][101],
               long long I_1[], int N_1,
               long long I_2[], int N_2,
               int idx_1, int idx_2)
{

    // memoization
    int & r = C[idx_1+1][idx_2+1];
    if (r >= 0) return r;

    // base condition
    // recursion
    r = 2;
    long long idx_1_val = idx_1 < 0 ? LLMIN : I_1[idx_1];
    long long idx_2_val = idx_2 < 0 ? LLMIN : I_2[idx_2];
    long long max_val = max(idx_1_val, idx_2_val);

    for (int next_idx_1 = idx_1+1; next_idx_1 < N_1; ++next_idx_1)
        if (max_val < I_1[next_idx_1])
            r = max(r, get_result(C, I_1, N_1, I_2, N_2, next_idx_1, idx_2)+1);

    for (int next_idx_2 = idx_2+1; next_idx_2 < N_2; ++next_idx_2)
        if (max_val < I_2[next_idx_2])
            r = max(r, get_result(C, I_1, N_1, I_2, N_2, idx_1, next_idx_2)+1);

    // printf("[%d] %lld [%d] %lld {%d}\n",
    //        idx_1, I_1[idx_1], idx_2, I_2[idx_2],
    //        r);
    
    return r;   
}

int main() {
    
    int C; // number of cases
    scanf("%d", &C);
    
    for(int c=0; c<C; ++c)
    {
        int N_1, N_2;
        long long INPUT_1[100] = {0,};
        long long INPUT_2[100] = {0,};
        int CACHE[101][101] = {0,};
        memset(CACHE, -1, sizeof(CACHE));
        scanf("%d", &N_1);
        scanf("%d", &N_2);

        for (int n=0; n<N_1; ++n)
            scanf("%lld", &INPUT_1[n]);
        for (int n=0; n<N_2; ++n)
            scanf("%lld", &INPUT_2[n]);

        // dump(INPUT_1, N_1);
        // dump(INPUT_2, N_2);
        // printf("----------\n");
        
        printf("%d\n", get_result(CACHE, INPUT_1, N_1, INPUT_2, N_2, -1, -1)-2);
   }
  
    return 0;
}
