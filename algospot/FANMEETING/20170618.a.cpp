#include <cstdio>
#include <string>
#include <vector>
#include <iostream>

using namespace std;

// num[] 의 자릿수 올림을 처리한다.
void normalize(vector<int>& num) {
    num.push_back(0);
    // 자릿수 올림을 처리한다
    for(int i = 0; i < num.size(); i++) {       
        if(num[i] < 0) {
            int borrow = (abs(num[i]) + 9) / 10;
            num[i+1] -= borrow;
            num[i] += borrow * 10;
        }
        else {
            num[i+1] += num[i] / 10;
            num[i] %= 10;
        }
    }
    if(num.back() == 0) num.pop_back();
}

// 두 긴 정수의 곱을 반환한다. 각 배열에는 각 수의 자리수가 1의 자리에서부터 시작해 저장되어 있다.
// 예: multiply({3,2,1},{6,5,4}) = 123*456 = 56088 = {8,8,0,6,5}
vector<int> multiply(const vector<int>& a, const vector<int>& b) {
    vector<int> c(a.size() + b.size() + 1, 0);
    for(int i = 0; i < a.size(); i++)
        for(int j = 0; j < b.size(); j++)
            c[i+j] += a[i] * b[j];
    //normalize(c);
    return c;
}

// a += b * (10^k); 를 구현한다.
void addTo(vector<int>& a, const vector<int>& b, int k) {
    a.resize(max(a.size(), b.size() + k));
    for(int i = 0; i < b.size(); i++) a[i+k] += b[i];
    //normalize(a);
}

// a -= b; 를 구현한다. a >= b 를 가정한다.
void subFrom(vector<int>& a, const vector<int>& b) {
    a.resize(max(a.size(), b.size()) + 1);
    for(int i = 0; i < b.size(); i++) a[i] -= b[i];
    //normalize(a);
}

// 두 긴 정수의 곱을 반환한다. 
vector<int> karatsuba(const vector<int>& a, const vector<int>& b) {
    int an = a.size(), bn = b.size();
    // a 가 b 보다 짧을 경우 둘을 바꾼다
    if(an < bn) return karatsuba(b, a);
    // 기저 사례: a 나 b 가 비어 있는 경우
    if(an == 0 || bn == 0) return vector<int>();
    // 기저 사례: a 가 비교적 짧은 경우 O(n^2) 곱셈으로 변경한다.
    if(an <= 2) return multiply(a, b);

    int half = an / 2;
    // a 와 b 를 밑에서 half 자리와 나머지로 분리한다
    vector<int> a0(a.begin(), a.begin() + half);
    vector<int> a1(a.begin() + half, a.end());
    vector<int> b0(b.begin(), b.begin() + min<int>(b.size(), half));
    vector<int> b1(b.begin() + min<int>(b.size(), half), b.end());
    // z2 = a1 * b1
    vector<int> z2 = karatsuba(a1, b1);
    // z0 = a0 * b0
    vector<int> z0 = karatsuba(a0, b0);
    // a0 = a0 + a1; b0 = b0 + b1
    addTo(a0, a1, 0); addTo(b0, b1, 0);
    // z1 = (a0 * b0) - z0 - z2;
    vector<int> z1 = karatsuba(a0, b0);
    subFrom(z1, z0);
    subFrom(z1, z2);
    // ret = z0 + z1 * 10^half + z2 * 10^(half*2)
    vector<int> ret;
    addTo(ret, z0, 0); 
    addTo(ret, z1, half);
    addTo(ret, z2, half + half);
    return ret;
}

// string toString(vector<int> a) {
//     string ret;
//     while(a.size() > 1 && a.back() == 0) a.pop_back();
//     for(int i = 0; i < a.size(); i++) 
//         ret += char('0' + a[a.size() - 1 - i]);
//     return ret;
// }

// vector<int> fromString(const string& s) {
//     vector<int> ret;
//     for(int i = 0; i < s.size(); i++)
//         ret.push_back(s[i] - '0');
//     reverse(ret.begin(), ret.end());
//     return ret;
// }

// get hug cnt with using karatsuba
int get_hug_cnt_karatsuba(string & M, string & F)
{
    int n_M = M.size();
    int n_F = F.size();
    vector<int> A(n_M), B(n_F);
    for (int i=0; i< n_M; ++i)
        A[n_M-i-1] = (M[i] == 'M');
    for (int i=0; i< n_F; ++i)
        B[i] = (F[i] == 'M');
    vector<int> C = karatsuba(A, B);
    int r = 0;
    for(int i=n_M-1; i<n_F; ++i)
        if (C[i] == 0)
            ++r;

    // for(int i=0; i<C.size(); ++i)
    //     printf("%d,",C[i]);
    // printf("\n");
    
    return r;
}

int get_hug_cnt(string & M, string & F)
{
    int r = 0;
    
    for(int i=0; i<=F.size()-M.size(); ++i)
    {
        for(int j=0; j<M.size(); ++j)
        {
            string s = F.substr(i, M.size());
            if (M.at(j) == 'M' && s.at(j) == 'M')
                break;
            if (j == M.size()-1)
                r++;
        }
    }
    
    return r;
}

int main() {
    
    int C; // number of cases
    
    scanf("%d", &C);
    
    for(int c=0; c<C; ++c)
    {
        int N;
        string  M, F; // members, fans
        scanf("%d", &N);
        cin >> M;
        cin >> F;

        printf("%d\n", get_hug_cnt_karatsuba(M, F));
    }
  
    return 0;
}
