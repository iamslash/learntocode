// //https://algospot.com/judge/problem/read/NUMBERGAME

#include <cstdio>
#include <string>
#include <vector>
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int MAX_N = 15;
const int MAX_USED = 1<<MAX_N;
int K;
string WORD[MAX_N];
int CACHE[MAX_N][MAX_USED];
int OVERLAP[MAX_N][MAX_N];

// 오버랩 미리 계산하기
int get_overlap(string & src, string & dst)
{
    int len = dst.size();
    while(len > 0)
    {
        if (src.find(dst.substr(0, len)) != string::npos)
            break;        
        len--;
    }

    return len;
}

void fill_overlap()
{
    for(int i=0; i<K; ++i)
    {
        for(int j=0; j<K; ++j)
        {
            string src = WORD[i];
            string dst = WORD[j];
            OVERLAP[i][j] = get_overlap(src, dst);
        }
    }
}

void print_overlap()
{
    for(int i=0; i<K; ++i)
    {
        for(int j=0; j<K; ++j)
        {
            printf(") %d ", OVERLAP[i][j]);
        }
        printf("\n");
    }
}

int restore(int last, int used)
{
    //printf("} %d %d\n", last, used);

    // base condition
    if (used == (1<<K)-1) return 0;

    // memoization
    int& r = CACHE[last][used];
    if (r != -1) return r;

    // recursion
    r = 0;

    for(int next=0; next<K; ++next)
    {
        int cand = OVERLAP[last][next] +
            restore(next, used | (1<<next));
        r = max(r, cand);
    }

    return r;
}

string reconstruct(int last, int used)
{
    //printf("> %d %d\n", last, used);

    // base condition
    if (used == (1<<K)-1) return "";

    // recursion
    for(int next=0; next<K; ++next)
    {
        if (used & (1<<next)) continue;

        int if_used = OVERLAP[last][next] + restore(next, used | (1<<next));
        if (restore(last, used) == if_used)
        {
            return (WORD[next].substr(OVERLAP[last][next]) +
                    reconstruct(next, used | (1<<next)));
        }
    }
    
    return "****oops****";
}

string get_result()
{
    int max_restore_val = 987654321;
    int r = 0;
    for (int last=0; last<K; ++last)
    {
        int cand = restore(last, 1<<last);

        // printf(" %d %d\n", last, cand);
        
        if (max_restore_val > cand)
        {
            r = last;
            max_restore_val = cand;
        }
    }

    // printf(" %d\n", r);
    
    return WORD[r] + reconstruct(r, 1<<r);
}

int main() {
    
    int C; // number of cases
    scanf("%d", &C);
    
    for(int c=0; c<C; ++c)
    {
        // init chache
        for (int i=0; i<MAX_N; ++i)
            for (int j=0; j<=MAX_USED; ++j)
                CACHE[i][j] = -1;

        scanf("%d", &K);
        // input datas
        for(int i=0; i<K; ++i)
        {
            char buf[64] = {0,};
            scanf("%s", buf);
            WORD[i] = buf;
        }

        fill_overlap();
        // print_overlap();
        printf("%s\n", get_result().c_str());
    }
  
    return 0;
}
