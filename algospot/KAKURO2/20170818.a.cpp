//https://algospot.com/judge/problem/read/KAKURO2

#include <cstdio>
#include <string>
#include <vector>
#include <iostream>
#include <cstring>
#include <algorithm>
// #include <set>
#include <cmath>
#include <queue>

using namespace std;

const int MAXN = 20;

int N, COLOR[MAXN][MAXN], VALUE[MAXN][MAXN], HINT[MAXN][MAXN][2];
int Q, SUM[MAXN*MAXN], LENGTH[MAXN*MAXN], KNOWN[MAXN*MAXN];
int CANDIDATES[10][46][1024];

void dump(int a[])
{
    for(int i=0; i<Q; ++i)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
}

// void dump(vector<int> a[], int n)
// {
//     printf("<..........\n");
//     for(int i=0; i<n; ++i)
//     {
//         for(int j=0; j<a[i].size(); ++j)
//         {
//             printf("%d ", a[i][j]);
//         }
//         printf("\n");
//     }
//     printf("..........>\n");
// }

// void dump_edible(vector<int>& a)
// {
//     printf("\t");
//     for(int j=0; j<a.size(); ++j)
//     {
//         printf("%d ", a[j]);
//     }
//     printf("\n");
// }


int get_size(int mask)
{
    int r = 0;
    for (int i=1; i<10; ++i)
    {
        if (mask >> i & 1)
            ++r;
    }
    return r;
}

int get_sum(int mask)
{
    int r = 0;

    for (int i=1; i<10; ++i)
    {
        if (mask >> i & 1)
            r += i;
    }

    return r;
}

// int get_candidates(int len, int sum, int known)
// {
//     //
//     int all_sets = 0;

//     for(int set = 0; set < 1024; set += 2)
//     {
//         if ( (set & known) == known &&
//              get_size(set) == len &&
//              get_sum(set) == sum)
//             all_sets |= set;
//     }

//     return all_sets & ~known;
// }

void generate_candidates()
{
    memset(CANDIDATES, 0, sizeof(CANDIDATES));

    for(int set = 0; set < 1024; set += 2)
    {
        int l = get_size(set);
        int s = get_sum(set);

        int subset = set;

        while(true)
        {
            // 숫자 하나의 합이 s이고 이미 subset 숫자가 쓰여있을때
            // 전체 숫자의 집합이 set이 되도록 나머지 숫자를 채워넣을 수 있다.
            CANDIDATES[l][s][subset] |= (set & ~subset);
            if (subset == 0)
                break;
            subset = (subset - 1) & set;
        }
    }
}

void put(int y, int x, int val)
{
    // propagation
    for(int h=0; h<2; ++h)
        KNOWN[HINT[y][x][h]] |= (1 << val);
    VALUE[y][x] = val;
}

void remove(int y, int x, int val)
{
    // propagation
    for(int h=0; h<2; ++h)
        KNOWN[HINT[y][x][h]] ^= (1 << val);
    VALUE[y][x] = 0;
}

// 힌트 번호가 주어질 때 후보의 집합을 반환한다.
int get_cand_hint(int hint)
{
    return CANDIDATES[LENGTH[hint]][SUM[hint]][KNOWN[hint]];
}

int get_cand_coord(int y, int x)
{
    return get_cand_hint(HINT[y][x][0]) &
        get_cand_hint(HINT[y][x][1]);
}

void print_solution()
{
    for(int i=0; i<N; ++i)
    {
        for(int j=0; j<N; ++j)
        {
            printf("%d ", VALUE[i][j]);
        }
        printf("\n");
    }
}

bool search()
{
    int y=-1, x=-1, min_cands = 1023;
    for(int i=0; i<N; ++i)
    {
        for(int j=0; j<N; ++j)
        {
            if (COLOR[i][j] == 1 && VALUE[i][j] == 0)
            {
                int cands = get_cand_coord(i, j);
                if (get_size(min_cands) > get_size(cands))
                {
                    min_cands = cands;
                    y = i; x = j;
                }
            }
        }
    }


    printf("[%d,%d] %d\n", y, x, min_cands);
    
    if (min_cands == 0)
        return false;

    if (y == -1)
    {
        print_solution();
        return true;
    }

    // recursion
    for (int val=1; val<=9; ++val)
    {
        if (min_cands & (1 << val))
        {
            put(y, x, val);
            if (search())
                return true;
            remove(y, x, val);
        }
    }

    return false;
}

int get_length(int y, int x, int dir)
{
    int r = 0;
    int i = y, j = x;

    dir == 0 ? ++j : ++i;

    while(COLOR[i][j] == 1)
    {
        ++r;
        
        if (dir == 0)
            ++j;
        else
            ++i;
        
        if (i>N || j>N)
            break;
    }
    return r;
}

int main() {
    
    int T; // number of T
    scanf("%d", &T);
    
    for(int t=0; t<T; ++t)
    {
        scanf("%d", &N);
        for (int i=0; i<N; ++i)
        {
            for (int j=0; j<N; ++j)
            {
                scanf("%d", &COLOR[i][j]);
                VALUE[i][j] = 0;
            }
        }

        scanf("%d", &Q);
        for (int i=0; i<Q; ++i)
        {
            int y, x, dir, sum;
            scanf("%d", &y);
            scanf("%d", &x);
            scanf("%d", &dir);
            scanf("%d", &sum);

            y -= 1;
            x -= 1;

            HINT[y][x][dir] = i;
            SUM[i] = sum;
            LENGTH[i] = get_length(y, x, dir);
        }

        // dump(LENGTH);
        // dump(SUM);

        generate_candidates();
        memset(KNOWN, 0, sizeof(KNOWN));
        printf("%d\n", search());
    }

    return 0;
}

// int main()
// {
//     // printf("%d\n", get_size(3)); // 2
//     // printf("%d\n", get_size(8)); // 1
//     printf("%d\n", get_sum(3)); // 3
//     printf("%d\n", get_sum(8)); // 4
// }
