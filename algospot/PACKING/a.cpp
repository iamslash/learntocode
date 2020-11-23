//https://algospot.com/judge/problem/read/PACKING

#include <cstdio>
#include <string>
#include <vector>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <limits>
#include <cstddef>

const int INF = 987654321;

using namespace std;

int C;// case
int N, W; // 개수, 용량
char I_NAME[100][21] = {0,}; // 이름
int I_WEIGHT[100] = {0,}; // 무게
int I_NEED[100] = {0,}; // 절박도

int CACHE[1001][101] = {0,}; // 용량, 서수 : 최대절박도

void dump(int A[], int N)
{
    for (int i=0; i<N; ++i)
        printf("%d ", A[i]);
    printf("\n");
}

void dump(char A[][21], int N)
{
    for (int i=0; i<N; ++i)
        printf("%s ", A[i]);
    printf("\n");
}

// return: 절박도
int get_result(int capacity, int idx)
{
    // printf("%d %d\n", capacity, idx);
    
    // base condition
    if (idx >= N) return 0;
    if (capacity <= 0) return 0;

    // memoization
    int & r = CACHE[capacity][idx];
    if (r >= 0) return r;

    // recursion
    if (I_WEIGHT[idx] > capacity)
        // 이번 물건은 너무 무겁다. 다음 물건부터 삽입 시도 하자.
        r = get_result(capacity, idx + 1);
    else
        // 이번 물건을 삽입한 경우 삽입하지 않은 경우
        r = max(get_result(capacity, idx+1),
                get_result(capacity - I_WEIGHT[idx], idx+1) +
                I_NEED[idx]);
    
    return r;
}

void make_items_packed(vector<string> & items, int capacity, int idx)
{

    // printf("-> %d %d\n", capacity, idx);
    
    // base condition
    if (idx == N) return;

    // recursion
    // idx아이템을 삽입힐 때와 삽입하지 않을때에 최대 절박도가 같다면 idx아이템은
    // 포함되지 않는다.
    if (get_result(capacity, idx) == get_result(capacity, idx+1))
    {
        make_items_packed(items, capacity, idx+1);
    }
    else
    {
        items.push_back(I_NAME[idx]);
        make_items_packed(items, capacity-I_WEIGHT[idx], idx+1);
    }
}

int main() {
    
    scanf("%d", &C);
    
    for(int c=0; c<C; ++c)
    {
        memset(I_NAME, 0, sizeof(I_NAME));
        memset(I_WEIGHT, -1, sizeof(I_WEIGHT));
        memset(I_NEED, -1, sizeof(I_NEED));
        memset(CACHE, -1, sizeof(CACHE));

        scanf("%d", &N);
        scanf("%d", &W);

        for(int i=0; i<N; ++i)
        {
            scanf("%s", I_NAME[i]);
            scanf("%d", &I_WEIGHT[i]);
            scanf("%d", &I_NEED[i]);
        }
        
        // dump(I_NAME, N);
        // dump(I_WEIGHT, N);
        // dump(I_NEED, N);
        int max_need = get_result(W, 0);
        vector<string> items;
        make_items_packed(items, W, 0);
        
        printf("%d %lu\n", max_need, items.size());
        for(int i=0; i<items.size(); ++i)
            printf("%s\n", items[i].c_str());
    }
  
    return 0;
}
