#include <cstdio>
#include <string>
#include <vector>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <limits>
#include <cstddef>

const int PRIME = 1000000007;

using namespace std;

int C;// case
int N; 
int CACHE[101] = {0,}; //
int CACHE_2[101] = {0,}; //

int get_tile(int width)
{
    // base condition
    if (width <= 1) return 1;

    // memoization
    int & r = CACHE[width];
    if (r >= 0) return r;

    // recursion
    return r = (get_tile(width-2) +
                get_tile(width-1))
        % PRIME;
}

int get_result(int width)
{
    if (width % 2 == 1)
    {   
        return (get_tile(width) -
                get_tile(width/2) + PRIME) % PRIME; 
    }

    // else

    int r = 0;

    r = get_tile(width);
    r = (r - get_tile(width/2) + PRIME) % PRIME;
    r = (r - get_tile(width/2-1) + PRIME) % PRIME;
    
    return r;
}

// int get_result(int width)
// {
//     // base condition
//     if (width <= 2) return 0;

//     // memoization
//     int & r = CACHE_2[width];
//     if (r >= 0) return r;

//     // recursion
//     int r = 0;

//     r = get_result(width-2) % PRIME;
    
//     return r;
// }

int main() {
    
    scanf("%d", &C);
    
    for(int c=0; c<C; ++c)
    {
        memset(CACHE, -1, sizeof(CACHE));

        scanf("%d", &N);

        printf("%d\n", get_result(N));
    }
  
    return 0;
}
