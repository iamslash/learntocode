//https://algospot.com/judge/problem/read/ARCTIC

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

int N;
double dist[101][101];

// 거리가 d이하인 기지들만을 연결했을 때 모든 기지가 연결되는지 여부를
// 반환한다.
bool decision(double d)
{
    // 이미 방문한놈
    vector<bool> visited(N, false);
    visited[0] = true;

    // 앞으로 방문해야할 놈
    queue<int> q;
    q.push(0);

    // 연결된 놈들의 개수
    int seen = 0;
    
    while( !q.empty() )
    {
        int here = q.front();
        q.pop();
        ++seen;

        for (int there = 0; there < N; ++there)
        {
            if (!visited[there] && dist[here][there] <= d)
            {
                visited[there] = true;
                q.push(there);
            }
        }
    }
    return seen == N;
}

// 모든 기지르 연결 할 수 있는 최소의 d를 반환한다.
double optimize()
{
    double lo=0, hi=1416.00;
    for(int i=0; i<100; ++i)
    {
        double mid = (lo + hi) / 2;

        if (decision(mid))
            hi = mid;
        else
            lo = mid;
    }

    return hi;
}

void precal(const vector<pair<double, double> > & pos)
{

    for (int i=0; i<pos.size(); ++i)
    {
        for (int j=0; j<pos.size(); ++j)
        {
            double diff_x = pos[j].first - pos[i].first;
            double diff_y = pos[j].second - pos[i].second;
            
            dist[i][j] = sqrtf( diff_x * diff_x + diff_y * diff_y ); 
        }
    }
}

// 
int main() {
    
    int T; // number of T
    scanf("%d", &T);
    
    for(int t=0; t<T; ++t)
    {
        scanf("%d", &N);
        vector<pair<double, double> > pos;

        for (int i=0; i<N; ++i)
        {
            double x, y;
            scanf("%lf", &x);
            scanf("%lf", &y);
            pos.push_back(make_pair(x, y));
        }

        precal(pos);

        printf("%0.2lf\n", optimize());
    }

    return 0;
}
