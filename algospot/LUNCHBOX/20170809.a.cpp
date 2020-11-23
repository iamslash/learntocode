//https://algospot.com/judge/problem/read/LUNCHBOX

#include <cstdio>
#include <string>
#include <vector>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <set>
#include <queue>

using namespace std;

int N;

int get_min_times(const vector<int> & v_m,
                  const vector<int> & v_e)
{
    int n = v_m.size();

    vector< pair<int, int> > v_order;

    for(int i=0; i<n; ++i)
    {
        v_order.push_back( make_pair(-v_e[i], i) );
    }
    sort(v_order.begin(), v_order.end());

    int r = 0;
    int time_to_eat = 0;
    for(int i=0; i<n; ++i)
    {
        int idx = v_order[i].second;
        time_to_eat += v_m[idx];
        r = max(r, time_to_eat + v_e[idx]);
    }

    return r;
}


int main() {
    
    int C; // number of cases
    scanf("%d", &C);
    
    for(int c=0; c<C; ++c)
    {
        scanf("%d", &N);

        vector<int> v_e; // 먹는데 걸리는 시간
        vector<int> v_m; // 데우는데 걸리는 시간

        for (int i=0; i<N; ++i)
        {
            int n;
            scanf("%d", &n);
            v_m.push_back(n);
        }
        
        for (int i=0; i<N; ++i)
        {
            int n;
            scanf("%d", &n);
            v_e.push_back(n);
        }
        
        printf("%d\n", get_min_times(v_m, v_e));

    }

    return 0;
}
