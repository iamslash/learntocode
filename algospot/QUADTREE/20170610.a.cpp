#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#include <string>

using namespace std;

#define MAX 16

void dump(char P[][MAX])
{
    for (int i=0; i<MAX; ++i)
    {
        for (int j=0; j<MAX; ++j)
            printf("%c ", P[i][j]);
        printf("\n");
    }
}

void decode(char P[][MAX], char M[], int * p_idx, int x, int y, int size)
{
    char m = M[*p_idx];

    /* printf("-----> %c\n", m); */

    (*p_idx)++;
    
    // base condition
    if (m == 'w' || m == 'b')
    {
        for (int i=y; i<y+size; ++i)
            for (int j=x; j<x+size; ++j)
                P[i][j] = m;
        return;
    }

    // recursion
    decode(P, M, p_idx, x, y, size/2);
    decode(P, M, p_idx, x + size/2, y, size/2);
    decode(P, M, p_idx, x, y + size/2, size/2);
    decode(P, M, p_idx, x + size/2, y + size/2, size/2);
}

string reverse(string::iterator & it)
{
    char m = *it;
    it++;

    // base condition
    if (m == 'w' || m == 'b')
        return string(1, m);

    // recursion
    string lt = reverse(it);
    string rt = reverse(it);
    string lb = reverse(it);
    string rb = reverse(it);

    return string("x") + lb + rb + lt + rt;
    
}

int main() {
    
    int C; // number of cases

    scanf("%d", &C);
    
    for(int c=0; c<C; ++c)
    {
        char M[1000]; // coded string

        scanf("%s", M);

        string R = M;
        string::iterator it_R = R.begin();

        printf("%s\n", reverse(it_R).c_str());
    }
  
    return 0;
}
