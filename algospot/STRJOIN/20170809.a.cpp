//https://algospot.com/judge/problem/read/STRJOIN

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

int get_min_cats(const vector<int>& v_nums)
{
    priority_queue<int, vector<int>, greater<int> > pq;
    for(int i=0; i<v_nums.size(); ++i)
        pq.push(v_nums[i]);

    int r = 0;

    while (pq.size() > 1)
    {
        int n_1 = pq.top(); pq.pop();
        int n_2 = pq.top(); pq.pop();
        pq.push(n_1 + n_2);
        r += n_1 + n_2;
    }

    return r;
    
}

int main() {
    
    int C; // number of cases
    scanf("%d", &C);
    
    for(int c=0; c<C; ++c)
    {
        scanf("%d", &N);

        vector<int> v_nums;

        for (int i=0; i<N; ++i)
        {
            int n;
            scanf("%d", &n);
            v_nums.push_back(n);
        }

        printf("%d\n", get_min_cats(v_nums));

    }

    return 0;
}
