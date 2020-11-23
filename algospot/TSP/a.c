#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <limits.h>

#define max(a,b) (a>b?a:b) 
#define min(a,b) (a>b?b:a) 

void dump(char boards[][20], int H, int W)
{
    printf("=====\n");
    for (int i=0; i<H; ++i)
    {
        for (int j=0; j<W; ++j)
        {
            printf("%c ", boards[i][j]);
        }
        printf("\n");
    }
    printf("=====\n");
}

/* int n; //     */
/* double dist[MAX][MAX]; //               */
/* I I p a t h                  */
/* I I v i s i t e d                  */
/* II currentLength             */
/* II                               . */
/* double shortestPath(vector<int>& path, vector<bool>& visited, */
/* double currentLength) { */
/* II     :                         . */
/* if (path.sizeO = n) */
/* return currentLength + dist[path[0]][path.back()]; */
/* double ret = INF; / /           //                . */
/* for(int next = 0; next < n; ++next) { */
/* if(visited[next]) continue; int here = path.backO; path push_back(next); visited[next] = true; */
/* II                               . double cand = shortestPath(path, visited, currentLength + */
/* ret = min( et, cand); visited[next] = false; path.pop_back(); */
/* } */
/* return ret; */

int shortest_path(int costs[][25], int N,
                  bool visits[][25], int path[], int cur_idx,
                  int cur_cost, int todo)
{
    
    int prev = path[max(0, cur_idx-1)];

    // base condition
    if (todo >= N)
        return cur_cost + costs[0][prev];

    // recursion
    int r = INT_MAX;
    
    for (int next=0; next<N; ++next)
    {
        if (visits[prev][next] || prev==next) continue;

        int here = prev;
        visits[prev][next] = true;
        path[cur_idx] = next;
        
        int cost = shortest_path(costs, N, visits, path, cur_idx+1, cur_cost, todo-1);

        r = min(cost, r);
        visits[prev][next] = false;
        path[cur_idx] = -1;
    }
    
    return r; 
}                 

int main() {
    
    int C; // number of cases
    int N; // number of nodes
    int costs[25][25]; // cost for x, y
    bool visits[25][25];
    int path[25];        // sales man path

    scanf("%d", &C);
    
    for(int c=0; c<C; ++c)
    {
        memset(costs, -1, sizeof(costs));
        memset(visits, false, sizeof(visits));
        memset(path, -1, sizeof(path));
        
        scanf("%d", &N);

        for (int i=0; i<N; ++i)
        {
            for (int j=0; j<N; ++j)
            {
                scanf("%d", &costs[j][i]);
            }
        }
        /* dump(boards, H, W); */

        printf("%d\n",
               shortest_path(costs, N, visits, path, 0, 0, N));
    }
  
    return 0;
}
