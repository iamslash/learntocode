#include <stdio.h>
#include <string.h>
#include <stdbool.h>

void dump(bool a[][10])
{
    printf("-----\n");
    for (int i=0; i<10; ++i)
    {
        for (int j=0; j<10; ++j)
        {
            if (a[i][j])
                printf("[%d][%d]\n", i, j);
        }
    }
    printf("-----\n");
        
}

/* // already exist in history ?  */
/* bool touched_already(int a[][2], int p[2]) */
/* { */
/*     for (int i=0; i<46; ++i) */
/*     { */
/*         if (a[i][0] == -1 && a[i][1] == -1) */
/*             break; */

/*         if (a[i][0] == p[0] || */
/*             a[i][1] == p[0] || */
/*             a[i][0] == p[1] || */
/*             a[i][1] == p[1]) */
/*         { */
/*             /\* printf("-----> [%d] | %d %d | %d %d\n", *\/ */
/*             /\*        i, a[i][0], a[i][1], p[0], p[1]); *\/ */
/*             return true; */
/*         } */
/*     } */
    
/*     return false; */
/* } */

int result(bool ar_pairs[][10], bool ar_taken[], int N)
{
    // base condition
    int j_a = -1;
    for (int i=0; i<N; ++i)
    {
        if (!ar_taken[i])
        {
            j_a = i;
            break;
        }
    }
    if (j_a == -1) return 1;

    // recursion
    int r = 0;

    for(int j_b = j_a+1; j_b < N; ++j_b)
    {
        if ( !ar_taken[j_b] && ar_pairs[j_a][j_b])
        {
            ar_taken[j_a] = ar_taken[j_b] = true;
            /* printf("-->%d %d\n", j_a, j_b); */
            r += result(ar_pairs, ar_taken, N);
            ar_taken[j_a] = ar_taken[j_b] = false;
        }
    }

    return r;
    
}

int main() {
    
    int C; // number of cases
    int N; // number of students
    int M; // number of pairs
    bool ar_pairs[10][10];
    bool ar_taken[10];

    scanf("%d", &C);
    
    for(int c=0; c<C; ++c)
    {
        memset(ar_pairs, false, sizeof(ar_pairs));
        memset(ar_taken, false, sizeof(ar_taken));

        scanf("%d", &N);
        scanf("%d", &M);

        for (int i=0; i<M; ++i)
        {
            int x, y;
            scanf("%d", &x);
            scanf("%d", &y);
            ar_pairs[x][y] = true;
            ar_pairs[y][x] = true;
        }

        /* // dump */
        /* dump(ar_pairs); */

        printf("%d\n", result(ar_pairs, ar_taken, N));
    }
  
    return 0;
}
