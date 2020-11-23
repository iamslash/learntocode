#include <cstdio>
#include <string>
#include <vector>
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

bool is_match(int C[][101], string & W, string & F, int w, int f)
{
    // printf("W:%s F:%s w:%d f:%d\n", W.c_str(), F.c_str(), w, f);

    // retrieve cache
    int & r = C[w][f];
    if (r >= 0) return r;

    // recursion
    // case of '?', character not '*'
    if (w == W.size() && f == F.size())
    {
        return r = true;
    }
    else if (w < W.size() && f < F.size() &&
           (W[w] == '?' || W[w] == F[f] ))
    {
        return r = is_match(C, W, F, w+1, f+1);
    }
    else if (W[w] == '*')
    {
        if (is_match(C, W, F, w+1, f) ||
            (f < F.size() && is_match(C, W, F, w, f+1)))
            return r = true;
    }

    // base condition
    return r = false;
}

int main() {
    
    int C; // number of cases
    
    scanf("%d", &C);
    
    for(int c=0; c<C; ++c)
    {
        string W; int N;
        cin >> W;
        scanf("%d", &N);
        vector<string> V;

        for (int n=0; n<N; ++n)
        {
            string F;
            cin >> F; 
            int C[101][101];
            memset(C, -1, sizeof(C));
            if (is_match(C, W, F, 0, 0))
                V.push_back(F);
        }
        
        sort(V.begin(), V.end());
        for (int v=0; v<V.size(); ++v)
        {
            printf("%s\n", V[v].c_str());
        }
    }
  
    return 0;
}
