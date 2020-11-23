//https://algospot.com/judge/problem/read/MATCHORDER

#include <cstdio>
#include <string>
#include <vector>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <set>

using namespace std;

int N;

int get_korean_wins(const vector<int> & v_russians,
                    const vector<int> & v_koreans)
{
    int n_size_of_russians = v_russians.size();
    int n_wins = 0;

    multiset<int> ratings(v_koreans.begin(), v_koreans.end());

    for(int n_rus = 0; n_rus < n_size_of_russians; ++n_rus)
    {
        // 이길 수 없는 경우
        if ( *ratings.rbegin() < v_russians[n_rus])
        {
            ratings.erase(ratings.begin());
        }
        // 이길 수 있는 경우
        else
        {
            ratings.erase(ratings.lower_bound(v_russians[n_rus]));
            n_wins++;
        }
    }
    
    return n_wins;
}

int main() {
    
    int C; // number of cases
    scanf("%d", &C);
    
    for(int c=0; c<C; ++c)
    {
        scanf("%d", &N);

        vector<int> v_russians;
        vector<int> v_koreans;

        for(int i=0; i<N; ++i)
        {
            int n;
            scanf("%d", &n);
            v_russians.push_back(n);
        }

        for(int i=0; i<N; ++i)
        {
            int n;
            scanf("%d", &n);
            v_koreans.push_back(n);
        }

        printf("%d\n", get_korean_wins(v_russians, v_koreans));
    }

    return 0;
}
