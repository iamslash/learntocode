//https://algospot.com/judge/problem/read/DICT

#include <cstdio>
#include <string>
#include <vector>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <limits>
#include <cstddef>
#include <cmath>

const int INF = 987654321;

using namespace std;

int m, q; // 원문에 출현할 수 있는 단어의수, 처리해야할 문장의 수
double B[501]; // i단어가 첫번째로 출현할 확률 로그값
double T[501][501]; // i단어 이후 j단어가 출현할 확률 로그값
double M[501][501]; // i단어가 j단어로 분류될 활률의 로그값
string WORDS[501]; // 원문에 출현할 수 있는 단어들 
int R[100]; // 분류기가 반환한 문장 인덱스
double CACHE[102][502]; // 용량, 서수 : 최대절박도
int CHOICE[102][502];

// Q[s]이루를 채워서 얻을 수 있는 최대 g()곱의 로그값
// Q[s-1] == p라고 가정한다.
double recognize(int s, int p)
{
    return 0.0;
}

int get_words_idx(string & a)
{
    for(int i=0; i<m; ++i)
    {
        if (a.compare(WORDS[i]) == 0)
            return i;
    }
    return -1;
}

string reconstruct()
{
    return "";
}

void fill_choice()
{
}

void dump(int R[], int n)
{
    for (int i=0; i<n; ++i)
    {
        printf("%d ", R[i]);
    }
    printf("\n");
}
int main() {
    
    memset(B, 0.0, sizeof(B));     
    
    scanf("%d", &m);
    scanf("%d", &q);

    // fill WORDS
    for(int i=0; i<m; ++i)
    {
        char a[501]={0,};
        scanf("%s", a);
        WORDS[i] = a;
    }
    // fill B
    for(int i=0; i<m; ++i)
    {
        double d;
        scanf("%lf", &d);
        B[i] = log(d);
    }
    // fill T
    for(int i=0; i<m; ++i)
    {
        for(int j=0; j<m; ++j)
        {
            double d;
            scanf("%lf", &d);
            T[i][j] = log(d);
        }
    }
    // fill M
    for(int i=0; i<m; ++i)
    {
        for(int j=0; j<m; ++j)
        {
            double d;
            scanf("%lf", &d);
            M[i][j] = log(d);
        }
    }

    for(int i=0; i<q; ++i)
    {
        memset(R, -1, sizeof(R));     
        memset(CACHE, -1, sizeof(CACHE));     
        memset(CHOICE, -1, sizeof(CHOICE));     

        
        int n;
        scanf("%d", &n);
        // fill R
        for(int j=0; j<n; ++j)
        {
            char t[11]={0,};
            scanf("%s", t);
            string t_str = t;
            R[j] = get_words_idx(t_str);
        }
        fill_choice();
        printf("%s\n", reconstruct().c_str());
        dump(R, n);
    }

    return 0;
}
