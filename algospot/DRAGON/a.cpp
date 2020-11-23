//https://algospot.com/judge/problem/read/DRAGON

#include <cstdio>
#include <string>
#include <vector>
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int MAX = 1000000000 + 1;
int N, P, L;
int LENGTH[51]; // X or Y를 i번 진화한 후의 문자열 길이

void precalc()
{
    LENGTH[0] = 1;
    for (int i = 1; i <= 50; ++i)
    {
        LENGTH[i] = min(MAX, LENGTH[i-1] * 2 + 2);
    }
}

const string EXPAND_X = "X+YF";
const string EXPAND_Y = "FX-Y";

char expand(const string & dragon_curve, int generations, int skip)
{
    //printf("%s %d %d\n", dragon_curve.c_str(), generations, skip);
    // base condition
    if (generations == 0)
    {
        return dragon_curve[skip];
    }

    // recursion
    for (int i=0; i<dragon_curve.size(); ++i)
    {
        if (dragon_curve[i] == 'X' ||
            dragon_curve[i] == 'Y')
        {
            if (skip >= LENGTH[generations])
                skip -= LENGTH[generations];
            else if (dragon_curve[i] == 'X')
                return expand(EXPAND_X, generations-1, skip);
            else
                return expand(EXPAND_Y, generations-1, skip);
        }
        else if (skip > 0)
            --skip;
        else
            return dragon_curve[i];
    }
    
    return '#'; // no effective
}

int main() {
    
    int C; // number of cases
    scanf("%d", &C);

    precalc();
    
    for(int c=0; c<C; ++c)
    {
        scanf("%d", &N);
        scanf("%d", &P);
        scanf("%d", &L);

        for (int i=0; i<L; ++i)
            printf("%c", expand("FX", N, P+i-1));
        printf("\n");
    }
  
    return 0;
}
