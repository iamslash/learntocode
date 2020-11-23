//https://algospot.com/judge/problem/read/DARPA

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

int N, M;

// 결정 문제: 정렬되어 있는 locations중 camera를 선택해 모든 카메라
// 간의 간격이 gap이상이 되는 방법이 있는지를 반환한다.
bool decision(const vector<double>& locations,
              int camera_cnt, double gap)
{
    double limit = -1;
    int installed = 0;
    
    for(int i=0; i<locations.size(); ++i)
    {
        if (limit <= locations[i])
        {
            ++installed;
            limit = locations[i] + gap;
        }
    }

    return installed >= camera_cnt;
}

// 최적화 문제: 정렬되어 있는 locations중 camera_cnt를 선택해 최소
// 간격을 최대화 한다.
double optimize(const vector<double>& locations,
                int camera_cnt)
{
    double lo = 0;
    double hi = 241;

    for(int i=0; i<100; ++i)
    {
        double mid = (lo + hi) / 2.0;
        if (decision(locations, camera_cnt, mid))
            lo = mid;
        else
            hi = mid;
    }
    
    return lo;
}

// 0. M개중에 N개씩 조합해서 완전탐색하는 방법, 완전탐색
// `
int main() {
    
    int T; // number of T
    scanf("%d", &T);
    
    for(int t=0; t<T; ++t)
    {
        scanf("%d", &N);
        scanf("%d", &M);
        vector<double> locations;

        for (int i=0; i<M; ++i)
        {
            double locate;
            scanf("%lf", &locate);
            locations.push_back(locate);
        }

        printf("%0.2lf\n", optimize(locations, N));
    }

    return 0;
}
