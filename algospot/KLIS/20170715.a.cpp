//https://algospot.com/judge/problem/read/KLIS

#include <cstdio>
#include <string>
#include <vector>
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int MAX = 2000000000;
int N, K;
int CACHE_LEN[501];
int CACHE_CNT[501];
int INPUT[500];

void dump(int I[], int N)
{
    printf("++++++++++\n");
    for (int i=0; i<N; ++i)
        printf("%d ", I[i]);
    printf("\n----------\n");
}

void dump_followers(vector<pair<int, int> > & f)
{
    for (int i=0; i<f.size(); ++i)
    {
        printf("[%d] %d %d\n", i, f[i].first, f[i].second);
    }
}

int lis3(int start)
{
    // printf("{%d}\n", start); 
    
    // base condition
    // memoization
    int & r = CACHE_LEN[start + 1];
    if (r >= 0) return r;

    // recursion
    r = 1;
    for (int next = start + 1; next < N; ++next)
    {
        if (start == -1 || INPUT[start] < INPUT[next])
        {
            r = max(r, lis3(next) + 1);
            // printf("[%d] %d\n", start, r);
        }
    }

    // printf("[%d] %d, %d\n", idx, I[idx], r);
    return r;
}

// count of lis from start
int count(int start)
{
    // base condition
    if (lis3(start) == 1) return 1;
    
    // memoization
    int & r = CACHE_CNT[start + 1];
    if (r >= 0) return r;

    // recursion
    r = 0;
    for (int next = start + 1; next < N; ++next)
    {
        if ( (start == -1 || INPUT[start] < INPUT[next]) &&
             lis3(start) == lis3(next) + 1)
        {
            r = min<long long>(MAX, (long long)r + count(next));
        }
    }

    return r;
    
}

void reconstruct(int start, int skip, vector<int>& lis)
{
    // 
    if (start != -1) lis.push_back(INPUT[start]);

    // number, idx of INPUT
    vector<pair<int, int> > followers;
    for (int next = start+1; next < N; ++next)
    {
        if ( (start == -1 || INPUT[start] < INPUT[next]) &&
             lis3(start) == lis3(next) + 1)
        {
            followers.push_back(make_pair(INPUT[next], next));
        }
    }

    //dump_followers(followers);
    sort(followers.begin(), followers.end());

    //
    for (int i = 0; i< followers.size(); ++i)
    {
        int idx = followers[i].second;
        int cnt = count(idx);

        if (cnt <= skip)
            skip -= cnt;
        else
        {
            reconstruct(idx, skip, lis);
            break;
        }
    }
}

void print_result()
{
    vector<int> L;
    reconstruct(-1, K-1, L);
    printf("%lu\n", L.size());
    for (int i=0; i<L.size(); ++i)
    {
        printf("%d ", L[i]);
    }
    printf("\n");
}

int main() {
    
    int C; // number of cases
    scanf("%d", &C);
    
    for(int c=0; c<C; ++c)
    {
        // init variables
        memset(CACHE_LEN, -1, sizeof(CACHE_LEN));
        memset(CACHE_CNT, -1, sizeof(CACHE_CNT));

        scanf("%d", &N);
        scanf("%d", &K);

        for (int n=0; n<N; ++n)
        {
            scanf("%d", &INPUT[n]);
        }

        // dump(INPUT, N);
        print_result();
   }
  
    return 0;
}
