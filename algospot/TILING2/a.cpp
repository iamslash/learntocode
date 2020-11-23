#include <cstdio>
#include <string>
#include <vector>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <limits>
#include <cstddef>
        
using namespace std;

const int PRIME = 1000000007;

int get_result(int C[100],
               int N, int idx)
{
    // base condition
    if (idx >= N-1) return 1;

    // memoization
    int & r = C[idx];
    if (r >= 0) return r;

    // recursion
    return r = (get_result(C, N, idx + 1) +
                get_result(C, N, idx + 2))
        % PRIME; 
}

int main() {
    
    int C; // number of cases
    scanf("%d", &C);
    
    for(int c=0; c<C; ++c)
    {
        int N;
        int CACHE[100] = {0,};
        memset(CACHE, -1, sizeof(CACHE));

        scanf("%d", &N);

        printf("%d\n", get_result(CACHE, N, 0));
   }
  
    return 0;
}
