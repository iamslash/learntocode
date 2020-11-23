//https://algospot.com/judge/problem/read/BOARDCOVER2

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

const double PI = 2.0 * acos(0);
int N;
double Y[100], X[100], R[100];
pair<double, double> ranges[100];

const int INF = 987654321;


void convert_to_range()
{
    for(int i=0;i<N;++i)
    {
        double loc = fmod(2*PI + atan2(Y[i], X[i]), 2*PI);
        double range = 2.0 * asin(R[i] / 2.0 / 8.0);
        ranges[i] = make_pair(loc - range, loc + range);
    }

    sort(ranges, ranges + N);
}

int solve_linear(double begin, double end)
{
    int used = 0, idx = 0;
    while (begin < end)
    {
        double max_cover = -1;
        while(idx < N && ranges[idx].first <= begin)
        {
            max_cover = max(max_cover, ranges[idx].second);
            ++idx;
        }
        if (max_cover <= begin)
            return INF;

        begin = max_cover;
        ++used;
    }

    return used;
}

int solve_circular()
{
    int r = INF;

    sort(ranges, ranges + N);

    for(int i=0; i< N; ++i)
    {
        if (ranges[i].first <= 0 || ranges[i].second >= 2 * PI)
        {
            double begin = fmod(ranges[i].second, 2 * PI);
            double end= fmod(ranges[i].first + 2 * PI, 2 * PI);

            r = min(r, 1 + solve_linear(begin, end));
        }
    }

    return r;
}

int main() {
    
    int C; // number of cases
    scanf("%d", &C);
    
    for(int c=0; c<C; ++c)
    {
        scanf("%d", &N);

        for(int i=0; i<N; ++i)
        {
            scanf("%lf", &Y[i]);
            scanf("%lf", &X[i]);
            scanf("%lf", &R[i]);
        }

        convert_to_range();
        int r = solve_circular();
        if (r == INF)
            printf("IMPOSSIBLE\n");
        else
            printf("%d\n", r);
    }

    


    return 0;
}
