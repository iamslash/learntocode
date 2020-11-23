//https://algospot.com/judge/problem/read/ZIMBABWE

#include <cstdio>
#include <string>
#include <vector>
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int MOD = 1000000007;
string e, digits;
int N, M;
int CACHE[1<<14][20][2]; // taken, mod, less

int price(int index, int taken, int mod, int less)
{
    //printf("[%d] %c : %d %d %d\n", index, e[index], taken, mod, less );
    
    // base condition
    if (index == N)
        return (less && mod == 0) ? 1 : 0;

    // memoization
    int & r = CACHE[taken][mod][less];
    if ( r >= 0) return r;

    // recursion
    r = 0;

    for (int next = 0; next < N; ++next)
    {
        if ( (taken & (1 << next)) == 0)
        {
            // 
            if (!less && e[index] < digits[next])
                continue;
            // 같은 숫자는 한번만
            if (next > 0 && digits[next-1] == digits[next] &&
                (taken & (1 << (next-1))) == 0)
                continue;
            //
            int nextTaken = taken | (1 << next);
            int nextMod = (mod * 10 + digits[next] - '0') % M;
            int nextLess = less || e[index] > digits[next];

            //printf(" [%d] %c\n", next, digits[next]);
            
            r += price(index+1, nextTaken, nextMod, nextLess);
            r %= MOD;
        }
    }

    return r;
}

int main() {
    
    int C; // number of cases
    scanf("%d", &C);
    
    for(int c=0; c<C; ++c)
    {
        // init variables
        memset(CACHE, -1, sizeof(CACHE));

        char buff[32] = {0,};
        scanf("%s", buff);
        e = buff;
        digits = buff;
        sort(digits.begin(), digits.end());
        N = e.size();
        scanf("%d", &M);

        //
        printf("%d\n", price(0, 0, 0, 0));
    }
  
    return 0;
}
