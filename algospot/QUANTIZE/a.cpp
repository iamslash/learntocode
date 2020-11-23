#include <cstdio>
#include <string>
#include <vector>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <limits>
#include <cstddef>

const int INF = 987654321;

using namespace std;

int C;// case
int N, S;
int INPUT[101] = {0,};
int CACHE[101][11] = {0,}; //

int P_SUM[101];
int P_SQ_SUM[101];

void dump(int A[], int N)
{
    for (int i=0; i<N; ++i)
        printf("%d ", A[i]);
    printf("\n");
}

void quick_sort_1(int arr[], int left, int right) {
    int i = left, j = right;
    int tmp;
    int pivot = arr[(left + right) / 2];
 
    /* partition */
    while (i <= j) {
        while (arr[i] < pivot)
            i++;
        while (arr[j] > pivot)
            j--;
        if (i <= j) {
            tmp = arr[i];
            arr[i] = arr[j];
            arr[j] = tmp;
            i++;
            j--;
        }
    };
 
    /* recursion */
    if (left < j)
        quick_sort_1(arr, left, j);
    if (i < right)
        quick_sort_1(arr, i, right);
}

void sort(int I[], int N)
{
    quick_sort_1(I, 0, N-1);
}

int min_error(int lo, int hi)
{
    int sum = P_SUM[hi] - (lo == 0 ? 0 : P_SUM[lo-1]);
    int sq_sum = P_SQ_SUM[hi] - (lo == 0 ? 0 : P_SQ_SUM[lo-1]);

    int m = int(0.5 + (double)sum / (hi - lo + 1));

    int r = sq_sum - 2 * m * sum + m * m * (hi - lo + 1);

    // printf("%d %d %d\n", lo, hi, r);
    
    return r;
}

// from부터 parts만큼 묶음을 만들어 양자화 오류 제곱의 합
int quantize(int from, int parts)
{
    
    // base condition
    if (from == N) return 0;
    if (parts == 0) return INF;

    // memoization
    int & r = CACHE[from][parts];
    if (r >= 0) return r;

    r = INF;
    // recursion
    for(int size=1; from+size<=N; ++size)
    {
        r = min(r, min_error(from, from + size -1) +
                quantize(from + size, parts - 1));
    }

    //    printf("%d %d %d\n", from, parts, r);

    return r;
}

int get_result()
{
    // sort and save P_SUM, P_SQ_SUM for min_error
    sort(INPUT, N);
    P_SUM[0] = INPUT[0];
    P_SQ_SUM[0] = INPUT[0] * INPUT[0];
    for (int i=1; i<N; ++i)
    {
        P_SUM[i] = P_SUM[i-1] + INPUT[i];
        P_SQ_SUM[i] = P_SQ_SUM[i-1] + INPUT[i] * INPUT[i];
    }

    // dump(INPUT, N);
    // dump(P_SUM, N);
    // dump(P_SQ_SUM, N);

    return quantize(0, S);
}

int main() {
    
    scanf("%d", &C);
    
    for(int c=0; c<C; ++c)
    {
        memset(INPUT, -1, sizeof(INPUT));
        memset(CACHE, -1, sizeof(CACHE));

        scanf("%d", &N);
        scanf("%d", &S);

        for(int i=0; i<N; ++i)
            scanf("%d", &INPUT[i]);

        printf("%d\n", get_result());
    }
  
    return 0;
}
