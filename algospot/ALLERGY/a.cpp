//https://algospot.com/judge/problem/read/ALLERGY

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

const int MAX_INT = 987654321;

int N, M;
int best;

// for fast search
// can_eat[i] : i번 친구가 먹을 수 있는 음식의 집합
// eaters[i] : i번 음식을 먹을 수 있는 친구들의 집합
vector<int> can_eat[50], eaters[50];

void dump(vector<int> a[], int n)
{
    printf("<..........\n");
    for(int i=0; i<n; ++i)
    {
        for(int j=0; j<a[i].size(); ++j)
        {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
    printf("..........>\n");
}

void dump_edible(vector<int>& a)
{
    printf("\t");
    for(int j=0; j<a.size(); ++j)
    {
        printf("%d ", a[j]);
    }
    printf("\n");
}

// food : 이번에 고려해야할 음식의 번호
// edible : 지금까지 고른 음식중 i번 친구가 먹을 수 있는 음식의 수
// chosen : 지금까지 고른 음식의 수
void slow_search(int food, vector<int>& edible, int chosen)
{
    // pruning
    
}

// chosen : 지금까지 고른 음식의 수
// edible : 지금까지 고른 음식중 i번 친구가 먹을 수 있는 음식의 수
void fast_search(vector<int>& edible, int chosen)
{
    // dump_edible(edible);
    
    // pruning
    if (chosen >= best)
        return;

    // 아직 먹을 음식이 없는 첫번째 친구를 찾는다.
    int first = 0;

    while(first < N && edible[first] > 0)
        ++first;

    // base condition
    // 모든 친구가 먹을 음식이 있는 경우 종료한다.
    if (first == N)
    {
        best = chosen;
        return;
    }

    // recursion
    // first가 먹을 수 있는 음식을 하나 만든다.
    for (int i=0; i< can_eat[first].size(); ++i)
    {
        int food = can_eat[first][i];

        for (int j=0; j<eaters[food].size(); ++j)
            edible[eaters[food][j]]++;
        fast_search(edible, chosen + 1);
        for (int j=0; j<eaters[food].size(); ++j)
            edible[eaters[food][j]]--;
    }
}

int main() {
    
    int T; // number of T
    scanf("%d", &T);
    
    for(int t=0; t<T; ++t)
    {
        // init global variables
        for(int i=0; i<50; ++i)
        {
            can_eat[i].clear();
            eaters[i].clear();
        }
        
        
        scanf("%d", &N);
        scanf("%d", &M);

        // make friends
        vector<string> friends;
        for(int i=0; i<N; ++i)
        {
            char buf[128]={0,};
            scanf("%s", buf);
            friends.push_back(buf);
        }

        // make foods
        for(int i=0; i<M; ++i)
        {
            int f=0;
            scanf("%d", &f);
            for(int j=0; j<f; ++j)
            {
                char buf[128]={0,};
                scanf("%s", buf);
                
                vector<string>::iterator it = find (friends.begin(), friends.end(), string(buf));
                // found a friend
                if (it != friends.end())
                {
                    int idx_friend = it - friends.begin();
                    int idx_food = i;

                    can_eat[idx_friend].push_back(idx_food);
                    eaters[i].push_back(idx_friend);                    
                }
            }
        }

        // dump(can_eat, N);
        // dump(eaters, M);

        vector<int> food_counts_of_friends;
        for(int i=0; i<N; ++i)
            food_counts_of_friends.push_back(0);
        
        // search
        best = MAX_INT;
        fast_search(food_counts_of_friends, 0);
        printf("%d\n", best);
        
    }

    return 0;
}
